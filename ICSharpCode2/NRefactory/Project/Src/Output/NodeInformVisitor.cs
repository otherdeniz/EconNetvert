﻿// <file>
//     <copyright see="prj:///doc/copyright.txt"/>
//     <license see="prj:///doc/license.txt"/>
//     <owner name="Mike Krüger" email="mike@icsharpcode.net"/>
//     <version>$Revision: 915 $</version>
// </file>

using System;
using System.Text;
using System.Collections;
using System.Diagnostics;

using ICSharpCode.NRefactory.Parser;
using ICSharpCode.NRefactory.Parser.CSharp;
using ICSharpCode.NRefactory.Parser.AST;

namespace ICSharpCode.NRefactory.PrettyPrinter
{
	public delegate void InformNode(INode node);
	
	public class NodeTracker
	{
		IASTVisitor callVisitor;
		
		public IASTVisitor CallVisitor {
			get {
				return callVisitor;
			}
		}
		
		public NodeTracker(IASTVisitor callVisitor)
		{
			this.callVisitor = callVisitor;
		}
		
		public void BeginNode(INode node)
		{
			if (NodeVisiting != null) {
				NodeVisiting(node);
			}
		}
		
		public void EndNode(INode node)
		{
			if (NodeVisited != null) {
				NodeVisited(node);
			}
		}
		
		public object TrackedVisit(INode node, object data)
		{
			BeginNode(node);
			object ret = node.AcceptVisitor(callVisitor, data);
			EndNode(node);
			return ret;
		}
		
		public object TrackedVisitChildren(INode node, object data)
		{
			foreach (INode child in node.Children) {
				TrackedVisit(child, data);
			}
			if (NodeChildrenVisited != null) {
				NodeChildrenVisited(node);
			}
			return data;
		}
		
		public event InformNode NodeVisiting;
		public event InformNode NodeChildrenVisited;
		public event InformNode NodeVisited;
	}
}
