

#include <Windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;

DWORD WINAPI thread_func(LPVOID param)
{
	int i = 0;
	char* p[] = { "next"," on"," AMC"," is"," BREAKING"," BAD" };
	for (i = 0; i < 6; i++)
	{
		printf(" %s", p[i]);
		Sleep(1000);
	}
	return 0;
}
int main()
{
	DWORD thID1, thID2;
	HANDLE hThread1, hThread2;
	HANDLE harray[2];
	hThread1 = CreateThread(
		NULL, //default security attributes
		0, // default stak size
		thread_func, //callback thread function 
		NULL,
		0,
		&thID1);
	if (hThread1 == NULL)
	{
		printf("unable to create thread \n");
		getchar();
		return 0;
	}
	CloseHandle(hThread1);
	getchar();

	system("pause");
	return 0;
}