﻿// <file>
//     <copyright see="prj:///doc/copyright.txt"/>
//     <license see="prj:///doc/license.txt"/>
//     <owner name="Mike Krüger" email="mike@icsharpcode.net"/>
//     <version>$Revision: 915 $</version>
// </file>

using System;
using System.IO;
using NUnit.Framework;
using ICSharpCode.NRefactory.Parser;
using ICSharpCode.NRefactory.Parser.AST;

namespace ICSharpCode.NRefactory.Tests.AST
{
	[TestFixture]
	public class RaiseEventStatementTest
	{
		#region C#
		// No C# representation
		#endregion
		
		#region VB.NET
		[Test]
		public void VBNetRaiseEventStatementTest()
		{
			RaiseEventStatement raiseEventStatement = ParseUtilVBNet.ParseStatement<RaiseEventStatement>("RaiseEvent MyEvent(a, 5, (6))");
		}
		#endregion
	}
}
