#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>

#define BUFFERSIZE 5
DWORD g_BytesTransferred = 0;

void  _tmain(int argc, TCHAR *argv[])
{

	HANDLE hFile;
	char DataBuffer[] = "This is some test data to write to the file.";
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	DWORD dwBytesWritten = 0;
	BOOL bErrorFlag = FALSE;

	printf("\n");
	if (argc != 2)
	{
		printf("Usage Error:\tIncorrect number of arguments\n\n");
		_tprintf(TEXT("%s <file_name>\n"), argv[0]);
		return;
	}

	hFile = CreateFile(
		argv[1],                // name of the write
		GENERIC_WRITE,          // open for writing
		0,                      // do not share
		NULL,                   // default security
		CREATE_NEW,             // create new file only
		FILE_ATTRIBUTE_NORMAL,  // normal file
		NULL);                  // no attr. template

	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(TEXT("Terminal failure: Unable to open file \"%s\" for write.\n"), argv[1]);
		return;
	}

	_tprintf(TEXT("Writing %d bytes to %s.\n"), dwBytesToWrite, argv[1]);

	bErrorFlag = WriteFile(
		hFile,           // open file handle
		DataBuffer,      // start of data to write
		dwBytesToWrite,  // number of bytes to write
		&dwBytesWritten, // number of bytes that were written
		NULL);            // no overlapped structure

	if (FALSE == bErrorFlag)
	{
		printf("Terminal failure: Unable to write to file.\n");
	}
	else
	{
		if (dwBytesWritten != dwBytesToWrite) //  should write all data as requested
		{
			printf("Error: dwBytesWritten != dwBytesToWrite\n");
		}
		else
		{
			_tprintf(TEXT("Wrote %d bytes to %s successfully.\n"), dwBytesWritten, argv[1]);
		}
	}
	getchar();
	CloseHandle(hFile);
	//return 0;
}