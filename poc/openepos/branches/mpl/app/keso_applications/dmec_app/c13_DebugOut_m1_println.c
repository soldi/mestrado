/* THIS FILE IS AUTO GENERATED BY KESO! DON'T EDIT */

#include <keso_support.h>
#include <keso_types.h>
#include "global.h"
#include "domains.h"
#include "c6_StringBuffer.h"
#include "char_array.h"
#include "c13_DebugOut.h"


/*
 * call analyse 2 c13_DebugOut_m1_println
 *
 * c4_DmecApp_m1_launch
 * ("DMEC APP for KESO is alive!")
 *
 * c4_DmecApp_m1_launch
 * ("done: OK")
 *
 * total (valid)
 */

/* test/DebugOut.println(Ljava/lang/String;)V */

void c13_DebugOut_m1_println(object_t* obj0) {
	jint i9_0;
	jint i9_1;
	jint i9_2;
	jint i4_1;
	object_t* obj1_0;
	object_t* obj6_0;
	object_t* obj10_0;
	object_t* obj3_1;
	object_t* obj3_2;

	
/*==============================================================/
| 68: 		buf.append(msg);
| 69: 		println();
/==============================================================*/
	obj1_0 = ((object_t*)SC13_DEBUGOUT_C13F1_BUF);
	KESO_CHECK_NULLPOINTER(obj1_0,"println",4);
	c6_StringBuffer_m4_append((object_t*)obj1_0,(object_t*)obj0);
	obj6_0 = ((object_t*)SC13_DEBUGOUT_C13F1_BUF);
	KESO_CHECK_NULLPOINTER(obj6_0,"println",8);
	i9_0 = ((C6_STRINGBUFFER_OBJ(obj6_0)->c6f2_length)+0x1);
	c6_StringBuffer_m2_ensureCapacity((object_t*)obj6_0,i9_0);
	obj10_0 = (C6_STRINGBUFFER_OBJ(obj6_0)->c6f1_data);
	i9_1 = (C6_STRINGBUFFER_OBJ(obj6_0)->c6f2_length);
	KESO_CHECK_ARR_REF(obj10_0,i9_1,"println",8);
	((char_array_t*)obj10_0)->data[i9_1]=0xa;
	i9_2 = ((C6_STRINGBUFFER_OBJ(obj6_0)->c6f2_length)+0x1);
	(C6_STRINGBUFFER_OBJ(obj6_0)->c6f2_length) = i9_2;
	c13_DebugOut_m4_raw_print((object_t*)obj6_0);
	c6_StringBuffer_m2_ensureCapacity((object_t*)obj6_0,0x0);
	if (0x0<=(C6_STRINGBUFFER_OBJ(obj6_0)->c6f2_length)) goto cc4899350_c6_StringBuffer_m5_setLength_B39;
	
/* cc18414151_c6_StringBuffer_m5_setLength_B13:  Pred:  0 No: 2 done */
	i4_1 = (C6_STRINGBUFFER_OBJ(obj6_0)->c6f2_length);
	
cc14111765_c6_StringBuffer_m5_setLength_B18: /* Pred:  13 23 No: 3 done */
	/* i4_1 = Phi(i4_1,i4_1)  */;
	if (i4_1>=0x0) goto cc7856_c6_StringBuffer_m5_setLength_B36;
	
/* cc13725633_c6_StringBuffer_m5_setLength_B23:  Pred:  18 No: 4 done */
	obj3_1 = (C6_STRINGBUFFER_OBJ(obj6_0)->c6f1_data);
	KESO_CHECK_ARR_REF(obj3_1,i4_1,"println",8);
	((char_array_t*)obj3_1)->data[i4_1]=0x0;
	i4_1 = (i4_1+0x1);
	goto cc14111765_c6_StringBuffer_m5_setLength_B18;
	
cc7856_c6_StringBuffer_m5_setLength_B36: /* Pred:  18 No: 5 done */
	goto cc31384576_c6_StringBuffer_m5_setLength_B46;
	
cc4899350_c6_StringBuffer_m5_setLength_B39: /* Pred:  0 No: 8 done */
	obj3_2 = (C6_STRINGBUFFER_OBJ(obj6_0)->c6f1_data);
	KESO_CHECK_ARR_REF(obj3_2,0,"println",8);
	((char_array_t*)obj3_2)->data[0x0]=0x0;
	
cc31384576_c6_StringBuffer_m5_setLength_B46: /* Pred:  39 36 No: 6 done */
	
/*==============================================================/
| 70: 	}
/==============================================================*/
	(C6_STRINGBUFFER_OBJ(obj6_0)->c6f2_length) = 0x0;
	/* goto c13_DebugOut_m1_println_B13 */;
	
/* c13_DebugOut_m1_println_B13:  Pred:  46 No: 7 done */
	return;
}
