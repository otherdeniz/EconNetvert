// <file>
//     <copyright see="prj:///doc/copyright.txt"/>
//     <license see="prj:///doc/license.txt"/>
//     <owner name="none" email=""/>
//     <version>$Revision: 915 $</version>
// </file>

using System;
using System.Collections;

namespace ICSharpCode.NRefactory.Parser.AST
{
	public class BlockStatement : Statement
	{
		// Children in C#: LabelStatement, LocalVariableDeclaration, Statement
		// Children in VB: LabelStatement, EndStatement, Statement
		
		public static new NullBlockStatement Null {
			get {
				return NullBlockStatement.Instance;
			}
		}
		
		public static BlockStatement CheckNull(BlockStatement blockStatement)
		{
			return blockStatement == null ? NullBlockStatement.Instance : blockStatement;
		}
		
		public override object AcceptVisitor(IASTVisitor visitor, object data)
		{
			return visitor.Visit(this, data);
		}
		
		public override string ToString()
		{
			return String.Format("[BlockStatement: Children={0}]",
			                     GetCollectionString(base.Children));
		}
	}
	
	public class NullBlockStatement : BlockStatement
	{
		static NullBlockStatement nullBlockStatement = new NullBlockStatement();
		
		public override bool IsNull {
			get {
				return true;
			}
		}
		
		public static NullBlockStatement Instance {
			get {
				return nullBlockStatement;
			}
		}
		
		NullBlockStatement()
		{
		}
		
		public override object AcceptVisitor(IASTVisitor visitor, object data)
		{
			return data;
		}
		public override object AcceptChildren(IASTVisitor visitor, object data)
		{
			return data;
		}
		public override void AddChild(INode childNode)
		{
			throw new InvalidOperationException();
		}
		
		public override string ToString()
		{
			return String.Format("[NullBlockStatement]");
		}
	}
}
