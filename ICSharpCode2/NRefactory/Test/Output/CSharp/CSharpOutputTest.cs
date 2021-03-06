// <file>
//     <copyright see="prj:///doc/copyright.txt"/>
//     <license see="prj:///doc/license.txt"/>
//     <owner name="Daniel Grunwald" email="daniel@danielgrunwald.de"/>
//     <version>$Revision: 915 $</version>
// </file>

using System;
using System.IO;
using NUnit.Framework;
using ICSharpCode.NRefactory.Parser;
using ICSharpCode.NRefactory.Parser.AST;
using ICSharpCode.NRefactory.PrettyPrinter;

namespace ICSharpCode.NRefactory.Tests.PrettyPrinter
{
	[TestFixture]
	public class CSharpOutputTest
	{
		void TestProgram(string program)
		{
			IParser parser = ParserFactory.CreateParser(SupportedLanguage.CSharp, new StringReader(program));
			parser.Parse();
			Assert.AreEqual("", parser.Errors.ErrorOutput);
			CSharpOutputVisitor outputVisitor = new CSharpOutputVisitor();
			outputVisitor.Visit(parser.CompilationUnit, null);
			Assert.AreEqual("", outputVisitor.Errors.ErrorOutput);
			Assert.AreEqual(StripWhitespace(program), StripWhitespace(outputVisitor.Text));
		}
		
		string StripWhitespace(string text)
		{
			return text.Trim().Replace("\t", "").Replace("\r", "").Replace("\n", " ").Replace("  ", " ");
		}
		
		void TestTypeMember(string program)
		{
			TestProgram("class A { " + program + " }");
		}
		
		void TestStatement(string statement)
		{
			TestTypeMember("void Method() { " + statement + " }");
		}
		
		void TestExpression(string expression)
		{
			IParser parser = ParserFactory.CreateParser(SupportedLanguage.CSharp, new StringReader(expression + ";"));
			Expression e = parser.ParseExpression();
			Assert.AreEqual("", parser.Errors.ErrorOutput);
			CSharpOutputVisitor outputVisitor = new CSharpOutputVisitor();
			e.AcceptVisitor(outputVisitor, null);
			Assert.AreEqual("", outputVisitor.Errors.ErrorOutput);
			Assert.AreEqual(StripWhitespace(expression), StripWhitespace(outputVisitor.Text));
		}
		
		[Test]
		public void Field()
		{
			TestTypeMember("int a;");
		}
		
		[Test]
		public void Method()
		{
			TestTypeMember("void Method() { }");
		}
		
		[Test]
		public void PartialModifier()
		{
			TestProgram("public partial class Foo { }");
		}
		
		[Test]
		public void GenericClassDefinition()
		{
			TestProgram("public class Foo<T> where T : IDisposable, ICloneable { }");
		}
		
		[Test]
		public void GenericClassDefinitionWithBaseType()
		{
			TestProgram("public class Foo<T> : BaseClass where T : IDisposable, ICloneable { }");
		}
		
		[Test]
		public void GenericMethodDefinition()
		{
			TestTypeMember("public void Foo<T>(T arg) where T : IDisposable, ICloneable { }");
		}
		
		[Test]
		public void ArrayRank()
		{
			TestStatement("object[,,] a = new object[1, 2, 3];");
		}
		
		[Test]
		public void JaggedArrayRank()
		{
			TestStatement("object[,][,,] a = new object[1, 2][,,];");
		}
		
		[Test]
		public void ArrayInitializer()
		{
			TestStatement("object[] a = new object[] {1, 2, 3};");
		}
		
		[Test]
		public void Assignment()
		{
			TestExpression("a = b");
		}
		
		[Test]
		public void Integer()
		{
			TestExpression("12");
		}
		
		[Test]
		public void LongInteger()
		{
			TestExpression("12l");
		}
		
		[Test]
		public void LongUnsignedInteger()
		{
			TestExpression("12ul");
		}
		
		[Test]
		public void UnsignedInteger()
		{
			TestExpression("12u");
		}
		
		[Test]
		public void Double()
		{
			TestExpression("12.5");
			TestExpression("12.0");
		}
		
		[Test]
		public void GenericMethodInvocation()
		{
			TestExpression("GenericMethod<T>(arg)");
		}
		
		[Test]
		public void Cast()
		{
			TestExpression("(T)a");
		}
		
		[Test]
		public void AsCast()
		{
			TestExpression("a as T");
		}
		
		[Test]
		public void NullCoalescing()
		{
			TestExpression("a ?? b");
		}
		
		[Test]
		public void SpecialIdentifierName()
		{
			TestExpression("@class");
		}
		
		[Test]
		public void GenericDelegate()
		{
			TestProgram("public delegate void Predicate<T>(T item) where T : IDisposable, ICloneable;");
		}
		
		[Test]
		public void Enum()
		{
			TestProgram("enum MyTest { Red, Green, Blue, Yellow }");
		}
		
		[Test]
		public void EnumWithInitializers()
		{
			TestProgram("enum MyTest { Red = 1, Green = 2, Blue = 4, Yellow = 8 }");
		}
		
		[Test]
		public void SyncLock()
		{
			TestStatement("lock (a) { Work(); }");
		}
		
		[Test]
		public void Using()
		{
			TestStatement("using (A a = new A()) { a.Work(); }");
		}
		
		[Test]
		public void AbstractProperty()
		{
			TestTypeMember("public abstract bool ExpectsValue { get; set; }");
			TestTypeMember("public abstract bool ExpectsValue { get; }");
			TestTypeMember("public abstract bool ExpectsValue { set; }");
		}
		
		[Test]
		public void AbstractMethod()
		{
			TestTypeMember("public abstract void Run();");
			TestTypeMember("public abstract bool Run();");
		}
		
		[Test]
		public void Interface()
		{
			TestProgram("interface ITest {" +
			            " bool GetterAndSetter { get; set; }" +
			            " bool GetterOnly { get; }" +
			            " bool SetterOnly { set; }" +
			            " void InterfaceMethod();" +
			            " string InterfaceMethod2();\n" +
			            "}");
		}
	}
}
