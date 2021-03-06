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
	/// <summary>
	/// Description of IOutputASTVisitor.
	/// </summary>
	public interface IOutputASTVisitor : IASTVisitor
	{
		string Text {
			get;
		}
		
		Errors Errors {
			get;
		}
		
		object Options {
			get;
			set;
		}
		IOutputFormatter OutputFormatter {
			get;
		}
	}
	public interface IOutputFormatter
	{
		int IndentationLevel {
			get;
			set;
		}
		string Text {
			get;
		}
		void NewLine();
		void Indent();
		void PrintComment(Comment comment);
		void PrintPreProcessingDirective(PreProcessingDirective directive);
	}
}
