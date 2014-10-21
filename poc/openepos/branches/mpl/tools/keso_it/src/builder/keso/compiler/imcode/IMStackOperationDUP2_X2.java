/**(c)

  Copyright (C) 2005-2006 Christian Wawersich 

  This file is part of the KESO Operating System.

  It is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  Please contact wawi@cs.fau.de for more info.

  (c)**/

package keso.compiler.imcode; 

import keso.classfile.*;
import keso.classfile.constantpool.*; 
import keso.classfile.datatypes.*; 

import keso.compiler.*;
import keso.compiler.backend.*;
import keso.compiler.kni.*;

import keso.util.Debug; 
import keso.util.DecoratedNames; 
import keso.util.IntegerHashtable; 

import java.util.Vector;
import java.util.Enumeration;
import java.util.Hashtable;


/* AUTO GENERATED FILE DON'T EDIT */

public class IMStackOperationDUP2_X2 extends IMNode {


	/* copy constuctor */
	protected IMStackOperationDUP2_X2() { }

	public IMStackOperationDUP2_X2(IMMethod method, int bc, int bcpos) {
		super(method,bc,BCBasicDatatype.UNKNOWN_TYPE,bcpos);
	}


	public IMNode processStack(VirtualOperantenStack stack, IMNode extra_ops) throws CompileException {
		IMNode opr1,opr2,opr3,opr4;

		stack.store(bcPosition,extra_ops);
		opr1 = stack.pop();
		opr2 = stack.pop();
	    	if (isCategory2(opr1)) {
			if (isCategory2(opr2)) {
				stack.push(opr1);
			} else {
				opr3 = stack.pop();
				stack.push(opr1);
				stack.push(opr3);
			}
			stack.push(opr2);
			stack.push(opr1.copy(null));
	    	} else {
			opr3 = stack.pop();
			if (isCategory2(opr3)) {
				stack.push(opr2);
				stack.push(opr1);
				stack.push(opr3);
			} else {
				opr4 = stack.pop();
				stack.push(opr2);
				stack.push(opr1);
				stack.push(opr4);
				stack.push(opr3);
			}
			stack.push(opr2.copy(null));
			stack.push(opr1.copy(null));
		}

		return null;
	}

}