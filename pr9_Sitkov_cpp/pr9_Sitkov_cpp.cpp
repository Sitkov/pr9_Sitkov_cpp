#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main()
{
    setlocale(0,"rus");

    wchar_t  AppWORD[] = L"\"C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE\"";
  //wchar_t  AppWORD[] = L"C:\\Sitkov\\pr9_Sitkov_cpp\\x64\\Debug\\father_process.exe";
    wchar_t  AppEXEL[] = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\EXEL.EXE";
    wchar_t AppPAINT[] = L"C:\WINDOWS\system32\\mspaint.exe";
    wchar_t  AppWord[] = L"C:\Program Files\Notepad++\\notepad++.exe";

    wchar_t* apps[] = { AppWORD, AppEXEL, AppPAINT, AppWord };

    STARTUPINFO si;
    PROCESS_INFORMATION piApp;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    if (!CreateProcess(AppWORD,NULL,NULL,NULL,FALSE,
        CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp)) {
        cout << "Дочерний процесс не запущен!!!" << endl;
        _getch();
        return 0;
    }

    cout << "Дочерний процесс запущен!" << endl;

    WaitForSingleObject(piApp.hProcess, INFINITE);

    CloseHandle(piApp.hProcess);
    CloseHandle(piApp.hThread);
}
