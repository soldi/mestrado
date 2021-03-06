#!/bin/bash
EPOS_DIR=$1

cd $EPOS_DIR/src/abstraction

email_body=$EPOS_DIR/report.log
storage_options=(512 1024 2048 3072 4096)
quantum_options=(10000 20000 50000 100000 200000 500000);
scheduling_options=('RR' 'FCFS');
failure=0;
success=0;

#sed -i "s/include makedefs/include makedefs \n\nautomated_test: \n\t\$\(INSTALL\) \$\(SRC\)\/abstraction\/\$\(APPLICATION\).cc \$\(APP\) \n\t\$\(INSTALL\) \$\(SRC\)\/abstraction\/\$\(APPLICATION\)_traits.h \$\(APP\) \n\t\$\(MAKETEST\) clean1 run1 \n\t\$\(CLEAN\) \$\(APP\)\/\$\(APPLICATION\)\* \n/g" makefile

#sed -i "s/$(MACH_PC)_CC_FLAGS.*/(MACH_PC)_CC_FLAGS     := -g -Wa,--32/g" makedefs

#Para cada arquivo de tese, monte o nome do traits.
#Se o arquivo existir, modifique-o, senão modifique o arquivo base, que fica na pasta raiz

echo "= = = = = TEST REPORT = = = = =" >> ${email_body}
echo "= Configurations =">> ${email_body}
echo "Quantum: 10ms, 20ms, 50ms, 100ms, 200ms, 500ms">> ${email_body}
echo "Stack: 512MB, 1GB, 2GB,3GB 4GB">> ${email_body}
echo "Heap: 512MB, 1GB, 2GB,3GB 4GB">> ${email_body}
echo "Schedulers: RR, FCFS " >> ${email_body} 
echo "">> ${email_body}

for test_file in *_test.cc 
do
   application=`echo ${test_file} | cut -d'.' -f 1`
   trait=`echo ${application}_traits.h`
   failure=0
   success=0
   echo "${application}_traits.h"

   sed -i '/main()/,/return *;*}/ {s/return/cout << "****TAP - test successful" <<endl;return/g}' ${application}.cc

   if [ -e $trait ]; then
      cp ${trait} ${trait}.bkp
   else
      cp ../../include/system/traits.h ${application}_traits.h
   fi

   for app_stack in "${storage_options[@]}"
   do
      sed -i "/template <> struct Traits<Application>: public Traits<void>/,/template <> struct/ {s/static const unsigned int STACK_SIZE.*/static const unsigned int STACK_SIZE = $app_stack;/g}" $trait

	
      for app_heap in "${storage_options[@]}"
      do
         if [ "$app_heap" -gt "$app_stack" ]; then
            sed -i "/template <> struct Traits<Application>: public Traits<void>/,/template <> struct/ {s/static const unsigned int HEAP_SIZE.*/static const unsigned int HEAP_SIZE = $app_heap;/g}" $trait
         fi

	 for sys_stack in "${storage_options[@]}"
	 do
	    sed -i "/template <> struct Traits<System>: public Traits<void>/,/template <> struct/ {s/static const unsigned int STACK_SIZE.*/static const unsigned int STACK_SIZE = $sys_stack;/g}" $trait

            for sys_heap in "${storage_options[@]}"
            do
               if [ "$sys_heap" -gt "$sys_stack" ]; then
                  sed -i "/template <> struct Traits<Application>: public Traits<void>/,/template <> struct/ {s/static const unsigned int HEAP_SIZE.*/static const unsigned int HEAP_SIZE = $sys_heap;/g}" $trait
            fi

	       for sys_quantum in "${quantum_options[@]}"
	       do
	          sed -i "/template <> struct Traits<System>: public Traits<void>/,/template <> struct/ {s/static const unsigned int QUANTUM.*/static const unsigned int QUANTUM = $sys_quantum;/g}" $trait

   	          for thread_quantum in "${quantum_options[@]}"
	          do
	             sed -i "/template <> struct Traits<Thread>: public Traits<void>/,/template <> struct/ {s/static const unsigned int QUANTUM.*/static const unsigned int QUANTUM = $thread_quantum;/g}" $trait

		     for scheduler in "${scheduling_options[@]}"
	             do
	                sed -i "s/typedef Scheduling_Criteria::.*/typedef Scheduling_Criteria::$scheduler Criterion;/g" $trait
	                echo "= Application:${application}"
   	                echo "Application stack:${app_stack}, Application heap:${app_heap}, System stack:${sys_stack}, System heap:${sys_heap}, System quantum:${sys_quantum}, Thread quantum:${thread_quantum}, Scheduler:${scheduler}."

	                log_name=${application}_AppStack_${app_stack}_AppHeap_${app_heap}_SysTack_${ys_stack}_SysHeap${sys_heap}_SysQuantum_${sys_quantum}_ThreadQuantum_${thread_quantum}_Scheduler_${scheduler}.log

	                cd $EPOS_DIR
	                `make automated_test APPLICATION=${application} 3>&1 1>>log/${log_name} 2>&1`
		      
                         if grep -q '****TAP - test successful' log/${log_name}; then
			    success=$((success+1))
			    rm log/${log_name}
		         else
			    failure=$((failure+1))
		         fi

	                cd $EPOS_DIR/src/abstraction
                     done
                  done
	       done
            done
         done
      done
   done

   echo "">> ${email_body}
   echo "= Application: "${application}" =">> ${email_body}
   echo "Successful tests:${success} - Failed tests:${failure}" >> ${email_body}
   #if [ "${failure}" -gt 0 ]; then
    #  echo "Failed tests execution log and debugging information on attachment." >> ${email_body}
   #fi
done
