// <file>
//     <copyright see="prj:///doc/copyright.txt"/>
//     <license see="prj:///doc/license.txt"/>
//     <owner name="none" email=""/>
//     <version>$Revision: 915 $</version>
// </file>

using System;
using System.Text;

namespace ICSharpCode.NRefactory.Parser
{
	public delegate void ErrorCodeProc(int line, int col, int n);
	public delegate void ErrorMsgProc(int line, int col, string msg);
	
	public class Errors
	{
		public int count = 0;                                               // number of errors detected
		public ErrorCodeProc SynErr;
		public ErrorCodeProc SemErr;
		public ErrorMsgProc  Error;
		StringBuilder errorText = new StringBuilder();
		
		public string ErrorOutput {
			get {
				return errorText.ToString();
			}
		}
		
		public Errors()
		{
			SynErr = new ErrorCodeProc(DefaultCodeError);  // syntactic errors
			SemErr = new ErrorCodeProc(DefaultCodeError);  // semantic errors
			Error  = new ErrorMsgProc(DefaultMsgError);    // user defined string based errors
		}
		
	//	public void Exception (string s)
	//	{
	//		Console.WriteLine(s); 
	//		System.Environment.Exit(0);
	//	}
	
		void DefaultCodeError(int line, int col, int n)
		{
			errorText.AppendLine(String.Format("-- line {0} col {1}: error {2}", line, col, n));
			count++;
		}
	
		void DefaultMsgError(int line, int col, string s) {
			errorText.AppendLine(String.Format("-- line {0} col {1}: {2}", line, col, s));
			count++;
		}
	} // Errors
}
