// inheritance
#include <Windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;

int main() //without cmdline
{
	//handle hProcess;

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	TCHAR name[50] = L"Abdul";

	/*BOOL CreateProcess(
	PCTSTR pszApplicationName,
	PTSTR pszCommandLine,
	PSECURITY_ATTRIBUTES psaProcess,
	PSECURITY_ATTRIBUTES psaThread,
	BOOL bInheritHandles,
	DWORD fdwCreate,
	PVOID pvEnvironment,
	PCTSTR pszCurDir,
	PSTARTUPINFO psiStartInfo,
	PPROCESS_INFORMATION ppiProcInfo);
	*/

	//creating security attribute for ----parent---
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE; // Make the returned handle inheritable.
	BOOL cp = CreateProcess(
		L"C:\\Windows\\System32\\notepad.exe",//name
		name, //cmdline
		&sa, // PSECURITY_ATTRIBUTES psaProcess
		NULL, //PSECURITY_ATTRIBUTES psaThread
		TRUE,  //putting binherit TRUE
		0,
		NULL,
		NULL,
		&si, //startupinfo
		&pi); //pro_info
	if (!cp)
	{
		cout << "Process creation error\n";
		printf("\n the error number is : %d", GetLastError());
		getchar();
		return FALSE;
	}
	//printf_s("\n handle of the process is %d ", pi.hProcess);
	//printf_s("\n ProcessID of the process is %d ", pi.dwProcessId);
	HANDLE hParent = pi.hProcess;
	DWORD dwRet = WaitForSingleObject(pi.hProcess, INFINITE);
	printf_s("wait  for single object output %d ", dwRet);


	// --------- child process
	TCHAR cnamei[] = L"notepad.exe";

	BOOL ch = CreateProcess(
		NULL,//name
		cnamei, //cmdline
		NULL, // PSECURITY_ATTRIBUTES psaProcess
		NULL, //PSECURITY_ATTRIBUTES psaThread
		TRUE,  //putting binherit TRUE
		0,
		NULL,
		NULL,
		&si, //startupinfo
		&pi); //pro_info
	


	getchar();
	//system("pause");
	return 0;
}