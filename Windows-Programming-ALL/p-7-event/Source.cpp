#include <Windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;

int main()
{

	HANDLE hevent = CreateEvent(  //returns a handle
		NULL, //handle cannot be inherited by child
		FALSE,// bManualReset FALSE, the function creates an auto-reset event object, and system automatically resets the event state to nonsignaled
		FALSE, // TRUE, the initial state of the event object is signaled; otherwise, it is nonsignaled.
		TEXT("my-event") //name of the event object. The name is limited to MAX_PATH 
	);
	
	system("pause");
	return 0;
}