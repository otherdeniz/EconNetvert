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
using ICSharpCode.NRefactory.Parser.VB;
using ICSharpCode.NRefactory.Parser.AST;

namespace ICSharpCode.NRefactory.PrettyPrinter
{
	/// <summary>
	/// Description of VBNetOutputFormatter.
	/// </summary>
	public sealed class VBNetOutputFormatter : AbstractOutputFormatter
	{
		public VBNetOutputFormatter(VBNetPrettyPrintOptions prettyPrintOptions) : base(prettyPrintOptions)
		{
		}
		
		public override void PrintToken(int token)
		{
			PrintText(Tokens.GetTokenString(token));
		}
		
		public override void PrintIdentifier(string identifier)
		{
			int token = Keywords.GetToken(identifier);
			if (token < 0 || Tokens.Unreserved[token]) {
				PrintText(identifier);
			} else {
				PrintText("[");
				PrintText(identifier);
				PrintText("]");
			}
		}
		
		public override void PrintComment(Comment comment)
		{
			switch (comment.CommentType) {
				case CommentType.Block:
					WriteInPreviousLine("'" + comment.CommentText.Replace("\n", "\n'"));
					break;
				case CommentType.Documentation:
					WriteInPreviousLine("'''" + comment.CommentText);
					break;
				default:
					WriteInPreviousLine("'" + comment.CommentText);
					break;
			}
		}
	}
}
