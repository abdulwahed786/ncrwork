#include<Windows.h>
#include<iostream>
using namespace std;

// Write a program to convert ANSI string to Wide character string and vice versa.
// Use MultiByteToWideChar and WideCharToMultiByte for conversion and IsTextUnicode for testing the results.


int main()
{
	WCHAR c1[] = L"WAHED";
	char c2[] = "ABDUL";

	printf("%S", c1);
	cout << " " << c2 << endl;

	int l1 = wcslen(c1);
	int l2 = strlen(c2);
	cout << l1 << " " << l2 << endl;

	int ll1 = sizeof(c1[0]);
	int ll2 = sizeof(c2[0]);
	cout << ll1 << " " << ll2 << endl;

	cout << "\n --------wide  to multi char ------\n ";
	int r = WideCharToMultiByte(CP_UTF8, 0, c1, -1, NULL, 0, NULL, NULL);
	if (0 == r)
	{
		cout << "\n error with wide char to multi";
	}

	char *aNewmul = new char[r];
	WideCharToMultiByte(CP_UTF8, 0, c1, -1, aNewmul, r, NULL, NULL);

	cout << "\n new created mulchar:  " << aNewmul << endl;



	cout << "\n --------multi char to wide ------ \n";
	int res = MultiByteToWideChar(CP_UTF8, 0, c2, -1, NULL, 0);
	if (0 == res)
	{
		cout << "error wiht wide char to multi";
	}

	WCHAR *wNewwide = new WCHAR[res];
	MultiByteToWideChar(CP_UTF8, 0, c2, -1, wNewwide, res);

	cout << "\n new created mulchar:  ";
	printf(" %S \n", wNewwide);


	BOOL check1 = IsTextUnicode(wNewwide, res, NULL);
	cout << " check on wchar IsTextUnicode : " << check1 << endl;

	BOOL check2 = IsTextUnicode(aNewmul, r, NULL);
	cout << " check on wchar IsTextUnicode : " << check2 << endl;

	cout << endl;
	return 0;
}