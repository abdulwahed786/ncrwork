#include<stdio.h>
#include<dos.h>
#include<Windows.h>
#include<tchar.h>

DWORD WINAPI thread_func(LPVOID lpParam);

int _tmain() 
{
	DWORD dwThreadID;
	HANDLE hThread1;
	DWORD exit_code;

	/*LPDWORD lpExit_code;
	lpExit_code = &exit_code;*/

	hThread1 = CreateThread(NULL, 0, thread_func, NULL, 0, &dwThreadID);
	if (NULL == hThread1) {
		_tprintf(_T("Error"));
	}
	_tprintf(_T("Parent waiting for thread to execute normally"));

	WaitForSingleObject(hThread1, INFINITE);
	if ((GetExitCodeThread(hThread1, &exit_code))==0)
	{
		_tprintf(_T("Get exit code failed. Error no : %d"), GetLastError());
		return FALSE;
	}
	else 
	{
		//printf("\nExit code is %d\n", exit_code);
		if ((TerminateThread(hThread1, exit_code ))==0) //Handle ,ExitCode
		{
			_tprintf(_T("Thread termination failed. Error no:%d\n"), GetLastError());
		}
		else {
			_tprintf(_T("Thread terminated with code %d \n"), exit_code);
		}
	}
	CloseHandle(hThread1);

	printf("XXX");
	getchar();
	return TRUE;
}
DWORD WINAPI thread_func(LPVOID lpParam) {
	for (int i = 0; i < 10; i++) {
		_tprintf(_T("Thread executing..\n"));
	}
	Sleep(1000);
	_tprintf(_T("Thread executed"));
	return TRUE;
}