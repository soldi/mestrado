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

public class IMNewObjArray extends IMNode {

	protected IMNode size;

	/* copy constuctor */
	protected IMNewObjArray() { }

	protected ClassCPEntry cpEntry;
	protected IMArrayClass aclass;

	public IMNewObjArray(IMMethod method, int bc, int bcpos, ClassCPEntry clazz) {
		super(method,bc,BCBasicDatatype.REFERENCE,bcpos);
		int domainID=0;
		this.cpEntry=clazz;
		method.requireClass(domainID, cpEntry.getClassName());
		method.requireClass(domainID, "[Ljava/lang/Object;");
		aclass=(IMArrayClass)method.getIMClass("[Ljava/lang/Object;");
		//method.requireClass(domainID, aclass.getClassName());
		aclass.requireAlloc();
	}

	public int getArrayLength() throws CompileException {
		if (size.isConstant()) return ((IMConstant)size).getIntValue(); 
		return -1;
	}

	final public IMNode copy(IMCopyVisitor visitor) throws CompileException {

		IMNewObjArray nnode = new IMNewObjArray();
		nnode.copyNodeValues(visitor, this);

		nnode.cpEntry=cpEntry;
		nnode.aclass=aclass;
		nnode.size=size.copy(visitor);

		if (visitor==null) return nnode;
		return visitor.visit(nnode,this);
	}

	final public void visitNodes(IMVisitor visitor) throws CompileException {
		if (visitor.skipNode(this)) return;

		visitor.visit(this);

		size.visitNodes(visitor);

	}


	public boolean isChecked(IMBasicBlock bb) throws CompileException { return true; }

	public void analyseCall() throws CompileException {
		method.isPure = false;
		method.isConst = false;
		if (!method.getMethodName().equals("<clinit>") && 
				opts.getGlobalHeap().allocationCanBlock()) method.blockInNew();
	}

	private boolean does_not_escape = false;
	private IMNode escape_path = null;
	private IMNode why_escape = null;
	public void escapeAnalyses(int mode) throws CompileException {
		if (mode!=IMEscapeVisitor.PREPARE) {
			if (doEscape(this, false)) {
				why_escape=whyEscape(this, false);
				if (why_escape instanceof IMEpilog && !doEscape(this, true)) {
					opts.verbose(this.lineInfo()+" escaping object thru "+why_escape.toReadableString()+" only!");
				}
				does_not_escape = false;
			} else {
				does_not_escape = true;
			}
		}
	}

	public boolean doEscape(IMNode node, boolean isArgument) throws CompileException {
		if (escape_path==null) {
			opts.warn(this.lineInfo()+": new "+toReadableString()+" with unknown escape path!");
			return false;
		}
		return escape_path.doEscape(node, isArgument);
	}

	final public IMNode whyEscape(IMNode node, boolean isArgument) throws CompileException {
		if (escape_path==null) {
			return null;
		}
		return escape_path.whyEscape(this, isArgument);
	}

	public void setEscapePath(IMNode node) throws CompileException {
		escape_path = node;
	}

	public IMNode getEscapePath() throws CompileException {
		return escape_path;
	}
	public IMNode processStack(VirtualOperantenStack stack, IMNode extra_ops) throws CompileException {
		method.isConst=false;
		method.isPure=false;
		size = stack.pop();
		assertIsIntValue(size);
		stack.store(bcPosition,extra_ops);
		stack.push(this);
		return null;
	}

	public String toReadableString() {
	return "keso_allocObjArray("+cpEntry.getClassName()+","+size.toReadableString()+")";
	}

	public String dumpBC() {return "NewObjArray";}

	public int costs() throws CompileException {
		return 50;
	}

	public void translate(Coder coder) throws CompileException {
		IMClass clazz = method.getIMClass(cpEntry.getClassName());
		if (clazz==null) throw new CompileException("Class not found! "+cpEntry.getClassName());

		coder.add_class(clazz.getAlias());
		coder.add_class(aclass.getAlias());

		if (!method.getMethodName().equals("<clinit>") &&
			 opts.getGlobalHeap().allocationCanBlock()) 
				method.getMethodFrame().codeEOLL(coder);

		if (why_escape!=null) { 
			coder.add_befor("\t/* escaping: ");
			coder.add_befor(why_escape.toReadableString());
			coder.add_befor(" (array) */\n");
		} 
		if (does_not_escape) {
			coder.add_befor("\t/* no escaping: ");
			coder.add_befor(toReadableString());
			coder.add_befor(" (array) */\n");
		}

		coder.add("keso_alloc_object_array(");
		coder.add(clazz.getClassID());
		coder.add(',');
		size.translate(coder);	
		coder.add(')');
	}

}