// <file>
//     <copyright see="prj:///doc/copyright.txt"/>
//     <license see="prj:///doc/license.txt"/>
//     <owner name="none" email=""/>
//     <version>$Revision: 915 $</version>
// </file>

using System;
using ICSharpCode.NRefactory.Parser.AST;

namespace ICSharpCode.NRefactory.Parser
{
	public interface IASTVisitor
	{
		[Obsolete("Warning: you are visiting INode")]
		object Visit(INode node, object data);
		
		object Visit(CompilationUnit compilationUnit, object data);
		object Visit(TypeReference typeReference, object data);
		object Visit(InnerClassTypeReference innerClassTypeReference, object data);
		object Visit(AttributeSection attributeSection, object data);
		object Visit(ICSharpCode.NRefactory.Parser.AST.Attribute attribute, object data);
		object Visit(NamedArgumentExpression namedArgumentExpression, object data);
		
		// GlobalScope
		object Visit(Using @using, object data);
		object Visit(UsingDeclaration usingDeclaration, object data);
		object Visit(NamespaceDeclaration namespaceDeclaration, object data);
		object Visit(TypeDeclaration typeDeclaration, object data);
		object Visit(TemplateDefinition templateDefinition, object data);
		object Visit(DelegateDeclaration delegateDeclaration, object data);
		object Visit(OptionDeclaration optionDeclaration, object data);
		
		// TypeLevel
		object Visit(FieldDeclaration    fieldDeclaration, object data);
		object Visit(VariableDeclaration variableDeclaration, object data);
		object Visit(PropertyDeclaration propertyDeclaration, object data);
		object Visit(PropertyGetRegion propertyGetRegion, object data);
		object Visit(PropertySetRegion propertySetRegion, object data);
		object Visit(EventDeclaration eventDeclaration, object data);
		object Visit(EventAddRegion eventAddRegion, object data);
		object Visit(EventRemoveRegion eventRemoveRegion, object data);
		object Visit(EventRaiseRegion eventRaiseRegion, object data); // VB.NET
		
		object Visit(ParameterDeclarationExpression parameterDeclarationExpression, object data);
		object Visit(MethodDeclaration methodDeclaration, object data);
		object Visit(ConstructorDeclaration constructorDeclaration, object data);
		object Visit(ConstructorInitializer constructorInitializer, object data);
		object Visit(IndexerDeclaration indexerDeclaration, object data);
		object Visit(DestructorDeclaration destructorDeclaration, object data);
		object Visit(OperatorDeclaration operatorDeclaration, object data);
		
		object Visit(DeclareDeclaration declareDeclaration, object data);
		
		// Statements
		object Visit(BlockStatement blockStatement, object data);
		object Visit(AddHandlerStatement addHandlerStatement, object data);
		object Visit(RemoveHandlerStatement removeHandlerStatement, object data);
		object Visit(RaiseEventStatement raiseEventStatement, object data);
		object Visit(EraseStatement eraseStatement, object data);
		object Visit(ErrorStatement errorStatement, object data);
		object Visit(OnErrorStatement onErrorStatement, object data);
		object Visit(ReDimStatement reDimStatement, object data);
//		object Visit(ReDimClause reDimClause, object data);
		object Visit(StatementExpression statementExpression, object data);
		object Visit(LocalVariableDeclaration localVariableDeclaration, object data);
		object Visit(EmptyStatement emptyStatement, object data);
		object Visit(YieldStatement yieldStatement, object data);
		object Visit(ReturnStatement returnStatement, object data);
		object Visit(IfElseStatement ifElseStatement, object data);
		object Visit(ElseIfSection elseIfSection, object data);
		
		object Visit(ForStatement forStatement, object data);
		object Visit(LabelStatement labelStatement, object data);
		object Visit(GotoStatement gotoStatement, object data);
		object Visit(SwitchStatement switchStatement, object data);
		object Visit(SwitchSection switchSection, object data);
		object Visit(CaseLabel caseLabel, object data);
		object Visit(BreakStatement breakStatement, object data);
		object Visit(StopStatement stopStatement, object data);
		object Visit(ResumeStatement resumeStatement, object data);
		object Visit(EndStatement endStatement, object data);
		object Visit(ContinueStatement continueStatement, object data);
		object Visit(GotoCaseStatement gotoCaseStatement, object data);
		object Visit(DoLoopStatement doLoopStatement, object data);
		object Visit(ForeachStatement foreachStatement, object data);
		object Visit(LockStatement lockStatement, object data);
		object Visit(UsingStatement usingStatement, object data);
		object Visit(WithStatement withStatement, object data);
		object Visit(TryCatchStatement tryCatchStatement, object data);
		object Visit(CatchClause catchClause, object data);
		object Visit(ThrowStatement throwStatement, object data);
		object Visit(FixedStatement fixedStatement, object data);
		object Visit(UnsafeStatement unsafeStatement, object data);
		object Visit(CheckedStatement checkedStatement, object data);
		object Visit(UncheckedStatement uncheckedStatement, object data);
		object Visit(ExitStatement exitStatement, object data);
		object Visit(ForNextStatement forNextStatement, object data);
		
		// Expressions
		object Visit(ClassReferenceExpression classReferenceExpression, object data);
		object Visit(PrimitiveExpression primitiveExpression, object data);
		object Visit(BinaryOperatorExpression binaryOperatorExpression, object data);
		object Visit(ParenthesizedExpression parenthesizedExpression, object data);
		object Visit(InvocationExpression invocationExpression, object data);
		object Visit(IdentifierExpression identifierExpression, object data);
		object Visit(TypeReferenceExpression typeReferenceExpression, object data);
		object Visit(UnaryOperatorExpression unaryOperatorExpression, object data);
		object Visit(AssignmentExpression assignmentExpression, object data);
		object Visit(SizeOfExpression sizeOfExpression, object data);
		object Visit(TypeOfExpression typeOfExpression, object data);
		object Visit(TypeOfIsExpression typeOfIsExpression, object data);
		object Visit(DefaultValueExpression defaultValueExpression, object data);
		object Visit(AddressOfExpression addressOfExpression, object data);
		object Visit(AnonymousMethodExpression anonymousMethodExpression, object data);
		object Visit(CheckedExpression checkedExpression, object data);
		object Visit(UncheckedExpression uncheckedExpression, object data);
		object Visit(PointerReferenceExpression pointerReferenceExpression, object data);
		object Visit(CastExpression castExpression, object data);
		object Visit(StackAllocExpression stackAllocExpression, object data);
		object Visit(IndexerExpression indexerExpression, object data);
		object Visit(ThisReferenceExpression thisReferenceExpression, object data);
		object Visit(BaseReferenceExpression baseReferenceExpression, object data);
		object Visit(ObjectCreateExpression objectCreateExpression, object data);
		object Visit(ArrayCreateExpression arrayCreateExpression, object data);
		object Visit(FieldReferenceExpression fieldReferenceExpression, object data);
		object Visit(DirectionExpression directionExpression, object data);
		object Visit(ArrayInitializerExpression arrayInitializerExpression, object data);
		object Visit(ConditionalExpression conditionalExpression, object data);
	}
}
