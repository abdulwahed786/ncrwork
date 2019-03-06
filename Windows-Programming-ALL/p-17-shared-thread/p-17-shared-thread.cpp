#include <Windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;

int i = 100;

DWORD WINAPI thread_func2(LPVOID param)
{
	i += 10;
	cout << "\n thread 2 i= " << i << endl;
	Sleep(1000);

	return 0;
}

DWORD WINAPI thread_func(LPVOID param)
{
	 i+=20;
	
	 DWORD thID;
	 HANDLE hThread;
	 //HANDLE harray[2];
	 hThread = CreateThread(
		 NULL, //default security attributes
		 0, // default stak size
		 thread_func2, //callback thread function 
		 NULL,
		 0, //create or CREATE_SUSPENDED
		 &thID);

	 if (hThread == NULL)
	 {
		 printf("unable to create thread \n");
		 getchar();
		 return 0;
	 }
	 cout << "\n thread 1 i= " << i << endl;
	Sleep(1000);
	CloseHandle(hThread);
	return 0;
}

int main()
{
	//while (1)
	//{
		cout << "\n main i= " << i << endl;
		DWORD thID1;
		HANDLE hThread1;
		//HANDLE harray[2];
		hThread1 = CreateThread(
			NULL, //default security attributes
			0, // default stak size
			thread_func, //callback thread function 
			NULL,
			0, //create or CREATE_SUSPENDED
			&thID1);

		if (hThread1 == NULL)
		{
			printf("unable to create thread \n");
			getchar();
			return 0;
		}
		//supspend thread for 5secs
		Sleep(1000);

		//resume thread
		//DWORD dwR = ResumeThread(hThread1);
		CloseHandle(hThread1);
		getchar();
		cout << "\n main end i= " << i << endl;

	//} //while
	


	system("pause");
	return 0;
}