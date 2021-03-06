#include "pch.h"
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

inline void open_proccess(const LPCWSTR path) {
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	if (CreateProcess(path, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &cif, &pi) == TRUE) {
		cout << "Notepad is opened" << endl;
		cout << "Please save file data.txt" << endl;
	}
	WaitForSingleObject(pi.hProcess, INFINITE);
}

inline void read_file(const LPCWSTR path) {
	HANDLE hFile = CreateFile(path, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		cout << "error reading file";
	}
	else {
		DWORD size = GetFileSize(hFile, NULL);
		DWORD rb;
		char res[1024];
		ReadFile(hFile, &res, size, &rb, NULL);
		cout << "Content: " << endl;
		for (int i = 0; i < size; i++) {
			cout << res[i];
		}
	}
}

int main() {
	open_proccess(L"c:\\windows\\notepad.exe");
	read_file(L"data.txt");
	return 0;
}
