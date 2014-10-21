/**(c)

  Copyright (C) 2005 Christian Wawersich 

  This file is part of the KESO Operating System.

  It is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  Please contact wawi@cs.fau.de for more info.

  (c)**/

package keso.compiler.kni;

import keso.compiler.*;
import keso.compiler.imcode.*;
import keso.compiler.backend.*;

import java.util.Hashtable;

/**
 * Weavelets can be used to affect the translation of certain Java
 * methods and directly generate C-Code for them.
 * This is sometimes necessary for low-level functions that are not
 * possible with the use of pure Java.
 *
 * To create a new Weavelet, 
 *
 *  (1) create the class in the libs Dir and leave the methods empty whose
 *    code will be generated by the Weavelet.
 *  (2) create a new subclass of the Weavelet class
 *
 *  (3) implement all methods of the Weavelet that you need in the subclass.
 *
 *  (4) register an instance with the joinpointschecker in the BuilderOptions.
 */
public abstract class Weavelet {

	final public static int NOTDEF = -1;
	final public static int FALSE  =  0;
	final public static int TRUE   =  1;

	final public static int ATTR_BLOCK   = 1;
	final public static int ATTR_PURE    = 2;
	final public static int ATTR_CONST   = 3;
	final public static int ATTR_NOTNULL = 4;
	final public static int ATTR_IGNORE  = 5;
	final public static int ATTR_DO_NOT_OMIT = 5;
	final public static int ATTR_NOESCAPE = 6;

	protected ClassStore repository;
	protected BuilderOptions opts;
	protected String[] joinPoints;
	
	public Weavelet(BuilderOptions opts, ClassStore repository) {
		this.opts = opts;
		this.repository = repository;
		this.joinPoints=null;
	}

	/**
	 * Use this to mark classes or methods as required.
	 *
	 * The Builder cannot determine the dependencies of code generated by Weavelets.
	 * Thus, you may use this method to tell the Builder which methods/classes
	 * are required by an Weavelet.
	 */
	public void require(int domainID, String className, String methodName) { }

	/**
	 * This prevent a method body from analayses and translation process.
	 */
	public boolean ignoreMethodBody(IMClass clazz, IMMethod method) throws CompileException {
		return false;
	}

	/**
	 * The checkFieldAttribut method changes the attributes of a field.
	 * The default value for all attributes of all affected fields 
	 * is FALSE.
	 */
	public int checkFieldAttribut(String classname, String fieldname, int attr) {
		return FALSE;
	}

	/**
	 * The checkAttribut method changes the attributes of a method.
	 * The default value for all attributes of all affected methods
	 * is FALSE.
	 *
	 * Attribute:
	 * ATTR_BLOCK    Method may block the Task. Thus we need a stackmap
	 * 		 for the GC.
	 * ATTR_PURE     Method has no side effects, but reads global memory.
	 * ATTR_CONST    Method has no side effects at all, the return value
	 * 	    	 is always constant for the same arguments.
	 * ATTR_NOTNULL  The return value is allways a valid object reference
	 * 		 and not null.
	 * ATTR_IGNORE   Ignore the method body.
	 * ATTR_NOESCAPE All arguments won`t escape the method stack. 
	 *
	 */
	public int checkAttribut(IMMethod method, int attr) throws CompileException {
		return FALSE;
	}

	/**
	 * This method can be used to affect or replace the intermediate code object.
	 *
	 * See the Config Weavelet for a example. 
	 *
	 * @param self   intermediate representation of the affected method invokation 
	 * @param method intermediate representation of the caller-side method
	 * @param callee intermediate representation of the called method
	 * @param obj    intermediate representation of the this-pointer or null
	 * @param args[] intermediate representation of the arguments
	 *
	 * @return the new intermediate object which replace "self".  
	 *
	 */
	public IMNode affectIMInvoke(IMInvoke self, IMMethod method, IMMethod callee,
			IMNode obj, IMNode args[]) throws CompileException {
		return self;
	}

	/**
	 * Use this method to add fields to the affected class.
	 * See the Task Weavelet on an example on how to use this. The added fields are
	 * for internal use only, they are not visible to the application.
	 *
	 * The fields will be appended to the regular object fields, no matter if they
	 * are reference fields or not. The class store will contain the size
	 * including the added fields, roff will not be affected since the fields are
	 * put behind the object header.
	 * This especially implicates that reference fields added with this method
	 * will _not_ be scanned by the garbage collector. Therefore you should not
	 * keep references to mortal objects in added fields, as they may be garbage
	 * collected in case they are not visible by the application anymore.
	 * 
	 * @param clazz The intermediate representation of the affected class
	 * @param coder Coder object that can be used to generate code for the class 
	 * @param raw_fields raw access  for adding C code into the object layout.
	 *
	 */

	public boolean addFields(IMClass clazz, Coder coder, StringBuffer raw_fields) throws CompileException {
		return false;
	}

	/**
	 * This method can be used to affect the code generated for a method.
	 * All calls to the method are not affected, unless you do so using the
	 * parts of the Weavelet API that are in charge for this task.
	 *
	 * @param clazz intermediate representation of the affected class
	 * @param method intermediate representation of the method
	 * @param coder Coder object that can be used to generate code for the method
	 * @return boolean value, indicates if the method has been affected
	 */
	public boolean affectMethod(IMClass clazz, IMMethod method, Coder coder) throws CompileException {
		return false;
	}

	/**
	 * This code can be used to affect calls to a static method, changing the
	 * calling code. (in contrast to affectMethod where the code of the method
	 * itself is affected)
	 * 
	 * For an example, see the InterruptService Weavelet.
	 *
	 * @param node intermediate representation of the invokestatic node
	 * @param caller intermediate representation of the calling method
	 * @param callee intermediate representation of the called method
	 * @param args array that contains the intermediate representations of the
	 *   methods parameters.
	 * @param coder Coder object that can be used to generate code for the method
	 *   invokation
	 * @return boolean value, indicates if the method call has been affected
	 */
	public boolean affectInvokeStatic(IMInvoke node, IMMethod caller, IMMethod callee,
			IMNode args[], Coder coder) throws CompileException {
		return false;
	}

	/**
	 * This code can be used to affect a method call via the invokespecial
	 * bytecode, changing the calling code. (in contrast to affectMethod 
	 * where the code of the method itself is affected)
	 * 
	 * @param node intermediate representation of the invokestatic node
	 * @param caller intermediate representation of the calling method
	 * @param callee intermediate representation of the called method
	 * @param obj intermediate representation of the object that the method is
	 *   invoked on
	 * @param args array that contains the intermediate representations of the
	 *   methods parameters.
	 * @param coder Coder object that can be used to generate code for the method
	 *   invokation
	 * @return boolean value, indicates if the method call has been affected
	 */
	public boolean affectInvokeSpecial(IMInvoke node, IMMethod caller, IMMethod callee,
			IMNode obj, IMNode args[], Coder coder) throws CompileException {
		return false;
	}

	/**
	 * This code can be used to affect a method call via the invokevirtual
	 * bytecode, changing the calling code. (in contrast to affectMethod 
	 * where the code of the method itself is affected)
	 * 
	 * For an example, take a look at the Memory Weavelet.
	 * 
	 * @param node intermediate representation of the invokestatic node
	 * @param caller intermediate representation of the calling method
	 * @param callee intermediate representation of the called method
	 * @param obj intermediate representation of the object that the method is
	 *   invoked on
	 * @param args array that contains the intermediate representations of the
	 *   methods parameters.
	 * @param coder Coder object that can be used to generate code for the method
	 *   invokation
	 * @return boolean value, indicates if the method call has been affected
	 */
	public boolean affectInvokeVirtual(IMInvoke node, IMMethod caller, IMMethod callee,
			IMNode obj, IMNode args[], Coder coder) throws CompileException {
		return false;
	}

	/**
	 * This code can be used to affect a method call via the invokeinterface
	 * bytecode, changing the calling code. (in contrast to affectMethod 
	 * where the code of the method itself is affected)
	 * 
	 * @param node intermediate representation of the invokestatic node
	 * @param caller intermediate representation of the calling method
	 * @param callee intermediate representation of the called method
	 * @param obj intermediate representation of the object that the method is
	 *   invoked on
	 * @param args array that contains the intermediate representations of the
	 *   methods parameters.
	 * @param coder Coder object that can be used to generate code for the method
	 *   invokation
	 * @return boolean value, indicates if the method call has been affected
	 */
	public boolean affectInvokeInterface(IMInvoke node, IMMethod caller, IMMethod callee,
			IMNode obj, IMNode args[], Coder coder) throws CompileException {
		return false;
	}

	public String assert_symbol(IMNode node, String msg) throws CompileException {
		// TODO: test if node is a valid symbol!
		if (node.isConstant()) return ((IMAConstant)node).getString();
		throw new CompileException(msg+" must be constant!");
	}

	public String assert_string(IMNode node, String msg) throws CompileException {
		if (node.isConstant()) return ((IMAConstant)node).getString();
		throw new CompileException(msg+" must be constant!");
	}

	public IMConstant assert_const(IMNode node, String msg) throws CompileException {
		if (node.isConstant()) return (IMConstant)node;
		throw new CompileException(msg+" must be constant!");
	}

	public IMAConstant assert_aconst(IMNode node, String msg) throws CompileException {
		if (node.isConstant()) return (IMAConstant)node;
		throw new CompileException(msg+" must be constant!");
	}

	public IMIConstant assert_iconst(IMNode node, String msg) throws CompileException {
		if (node.isConstant()) return (IMIConstant)node;
		throw new CompileException(msg+" must be constant!");
	}

	public IMDConstant assert_dconst(IMNode node, String msg) throws CompileException {
		if (node.isConstant()) return (IMDConstant)node;
		throw new CompileException(msg+" must be constant!");
	}
}