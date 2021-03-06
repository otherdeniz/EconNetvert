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
	/// Base class of output formatters.
	/// </summary>
	public abstract class AbstractOutputFormatter : IOutputFormatter
	{
		int           indentationLevel = 0;
		StringBuilder text = new StringBuilder();
		
		bool          indent         = true;
		bool          doNewLine      = true;
		AbstractPrettyPrintOptions prettyPrintOptions;
		
		public int IndentationLevel {
			get {
				return indentationLevel;
			}
			set {
				indentationLevel = value;
			}
		}
		
		public string Text {
			get {
				return text.ToString();
			}
		}
		
		
		public bool DoIndent {
			get {
				return indent;
			}
			set {
				indent = value;
			}
		}
		
		public bool DoNewLine {
			get {
				return doNewLine;
			}
			set {
				doNewLine = value;
			}
		}
		
		public AbstractOutputFormatter(AbstractPrettyPrintOptions prettyPrintOptions)
		{
			this.prettyPrintOptions = prettyPrintOptions;
		}
		
		public void Indent()
		{
			if (DoIndent) {
				int indent = 0;
				while (indent < prettyPrintOptions.IndentSize * indentationLevel) {
					char ch = prettyPrintOptions.IndentationChar;
					if (ch == '\t' && indent + prettyPrintOptions.TabSize > prettyPrintOptions.IndentSize * indentationLevel) {
						ch = ' ';
					}
					text.Append(ch);
					if (ch == '\t') {
						indent += prettyPrintOptions.TabSize;
					} else {
						++indent;
					}
				}
			}
		}
		
		public void Space()
		{
			text.Append(' ');
		}
		
		int lastLineStart = 0;
		
		public bool LastCharacterIsNewLine {
			get {
				return text.Length == lastLineStart;
			}
		}
		
		public virtual void NewLine()
		{
			if (DoNewLine) {
				text.AppendLine();
				lastLineStart = text.Length;
			}
		}
		
		public virtual void EndFile()
		{
		}
		
		protected void WriteInPreviousLine(string txt)
		{
			if (LastCharacterIsNewLine) {
				Indent();
				text.AppendLine(txt);
				lastLineStart = text.Length;
			} else {
				string lastLine = text.ToString(lastLineStart, text.Length - lastLineStart);
				text.Remove(lastLineStart, text.Length - lastLineStart);
				Indent();
				text.AppendLine(txt);
				lastLineStart = text.Length;
				text.Append(lastLine);
			}
		}
		
		public void PrintTokenList(ArrayList tokenList)
		{
			foreach (int token in tokenList) {
				PrintToken(token);
				Space();
			}
		}
		
		public abstract void PrintComment(Comment comment);
		
		public virtual void PrintPreProcessingDirective(PreProcessingDirective directive)
		{
			WriteInPreviousLine(directive.Cmd + " " + directive.Arg);
		}
		
		public abstract void PrintToken(int token);
		
		public void PrintText(string text)
		{
			this.text.Append(text);
		}
		
		public abstract void PrintIdentifier(string identifier);
	}
}
