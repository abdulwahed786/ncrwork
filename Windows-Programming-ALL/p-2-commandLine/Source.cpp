#include <windows.h>
//#include <stdio.h>
//#include <shellapi.h>
//int _tmain( int argc, TCHAR *argv[])

#include <iostream>
using namespace std;
#include <tchar.h>

#if defined(UNICODE)
#define _tcout wcout
#else
#define _tcout cout
#endif

int _tmain(int argc, _TCHAR *argv[])
{
	_tcout << TEXT("There are ") << argc << _T(" arguments:") << endl;

	// Loop through each argument and print its number and value
	for (int i = 0; i<argc; i++)
		_tcout << i << _T(" ") << argv[i] << std::endl;
	getchar();
	return 0;
}

/*
int  main()
//int _tmain(int argc, TCHAR *argv[])
{
	LPWSTR *szArglist;
	int nArgs;
	int i;

	szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
	if (NULL == szArglist)
	{
		wprintf(L"CommandLineToArgvW failed \n");
		//cout << GetLastError() << endl;
		return 0;
	}
	else for (i = 0; i<nArgs; i++)
		printf("%d: %ws \n", i, szArglist[i]);

	// Free memory allocated for CommandLineToArgvW arguments.

	//delete(szArglist);
	system("pause");
	return(0);
}*/