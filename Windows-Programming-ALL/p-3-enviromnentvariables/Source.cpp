// ExpandEnvironmentStrings
#include<iostream>
#include <windows.h>
#include<dos.h>
#include<tchar.h>

using namespace std;

/*
void DumpEnvironVariables(TCHAR *env[])
{
	int i = 1;
	while (env != NULL)
	{
		cout << i << "  :  ";
		//wprintf("\n %ws \n", *env);
		_tprintf(TEXT("%S\n"), *env);
		i++;
		env++;
	}
}
*/
void DumpEnvStrings(TCHAR *env[])
{
	
	TCHAR **temp = env; int c = 0;
	while (*temp != NULL)
	{
		c++;
		_tprintf(TEXT("%d - %S\n"), c, *temp);
		//wcout << c << " " << *temp << " " << wcslen(*temp) << endl;
		(temp)++;
	}
}

//int  main()
int main(int argc, TCHAR *argv[],TCHAR *env[])
{
	// method 1 direct
	//DumpEnvironVariables(env); //function call

	DumpEnvStrings(env);
	cout << "\n----------------------\n";
	//method 2- using expand 
	
	TCHAR envVarString[] = TEXT("SystemRoot='%SystemRoot%'");
	TCHAR buffer[MAX_PATH];
	DWORD ret;
	ret = ExpandEnvironmentStrings(envVarString, buffer, MAX_PATH);
	if (!ret)
	{
		printf("%d\n", GetLastError());
		getchar();
		return 0;
	}
	_tprintf(TEXT("%s"), buffer);

	cout << "\n----------------------\n";
	//---- text book way
	DWORD chValue = ExpandEnvironmentStrings(TEXT("PATH='%PATH%'"), NULL, 0);
	PTSTR pszBuffer = new TCHAR[chValue];
	chValue = ExpandEnvironmentStrings(TEXT("PATH='%PATH%'"), pszBuffer, chValue);
	_tprintf(TEXT("%s\r\n"), pszBuffer);
	delete[] pszBuffer;


	//DumpEnvStrings(env);
	system("pause");
	return(0);
}