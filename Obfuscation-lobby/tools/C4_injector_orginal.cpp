#include <iostream>
#include <windows.h>
#include <strsafe.h>

BOOL CALLBACK EnumWindowsProc_GPI(HWND hwnd, LPARAM lparam)
{
    DWORD hwnd_procID{0}; 
    DWORD procID{0};
    DWORD C4ProcID{0};

    if (!IsWindowVisible(hwnd) || (GetWindowTextLength(hwnd) == 0))
    {
        return TRUE;
    }

    int length = GetWindowTextLength(hwnd);
    wchar_t* title = (wchar_t*)malloc((length + 1) * sizeof(wchar_t));
    //wchar_t* title = (wchar_t*)malloc((length + 1));
    //LPSTR stringBuffer;
    if(*title != 0)
    {
        GetWindowTextW(hwnd, title, length + 1);
        int size = WideCharToMultiByte(CP_ACP, 
            0, 
            title, 
            -1, //sizeof(title) + 1, 
            NULL, 
            0, 
            NULL, NULL);
        char* multi_byte_title = (char*)malloc((size) * sizeof(char));
        //char* multi_byte_title = (char*)malloc((length + 1));

        WideCharToMultiByte(CP_ACP, 
            0, 
            title, 
            -1,//sizeof(title) + 1, 
            multi_byte_title, 
            size, 
            NULL, NULL);
        GetWindowThreadProcessId(hwnd, &hwnd_procID);
        fprintf(stdout, "Window Title: %s | Handle: %d | Thread ID: %d | Process ID: %d\n",  multi_byte_title, hwnd, GetWindowThreadProcessId(hwnd, &hwnd_procID), hwnd_procID); 

        if(strcmp(multi_byte_title, "Call of Duty 4") == 0)
        {
            fprintf(stdout, "[+] Found Process Target!\n");
            const char* DLL_DIR = "C:\\C4.dll";
            int nSize = strlen(DLL_DIR); //size of dllPath in bytes inlcuding Null Terminator
            SIZE_T* nbytesWritten{nullptr};
            C4ProcID = GetWindowThreadProcessId(hwnd, &procID);
            HANDLE Handle_Process = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, procID);
            if (GetLastError() == ERROR_INVALID_PARAMETER || GetLastError() == ERROR_ACCESS_DENIED)
            {
                system("color 6");
                fprintf(stderr, "[-] HANDLE ERROR: INVALID PARAMETER or ACCESS DENIED -> Code %d\n", GetLastError()); 
                fprintf(stdout, "Handle: %d | Process ID: %d | Call of Duty 4 Thread ID: %d\n\n", Handle_Process, procID, C4ProcID);
                exit(EXIT_FAILURE);
            }

            LPVOID VAspace = VirtualAllocEx(Handle_Process, 
                                            NULL,   
                                            nSize, //4096, 
                                            MEM_COMMIT | MEM_RESERVE | MEM_TOP_DOWN, PAGE_EXECUTE_READWRITE);

            if(!(WriteProcessMemory(Handle_Process, 
                                    VAspace, 
                                    DLL_DIR, //&VAspace, 
                                    nSize, 
                                    nbytesWritten))) // 0/10 bypass
            {
                system("color 4");
                fprintf(stderr, "\nFailed to write into process memory, check access rights: %d\n", GetLastError()); 
                fprintf(stdout, "Window Title: %s | Handle: %d | Thread ID: %d | Process ID: %d\n\n",  multi_byte_title, Handle_Process, C4ProcID, procID);
                exit(EXIT_FAILURE);
            }
            
                fprintf(stdout, "[+] Injected successfully\n");
                fprintf(stdout, "[+] Handle: %d | Process ID: %d | Call of Duty 4 Thread ID: %d\n", Handle_Process, procID, C4ProcID);
                fprintf(stdout, "[Debug] Injected Module Address: [%p]\n\n\n", VAspace);
                system("color 2");

                SECURITY_ATTRIBUTES _S_A{};
                _S_A.nLength = sizeof(_S_A);
                _S_A.lpSecurityDescriptor = NULL;
                _S_A.bInheritHandle = FALSE;

                HANDLE hRemoteThread = CreateRemoteThread(Handle_Process, &_S_A, 0, 
                    (LPTHREAD_START_ROUTINE)LoadLibraryA, 
                    (LPVOID)"C:\\C4.dll", 0, NULL);   // 0/10 bypass

                CloseHandle(hRemoteThread);
                CloseHandle(Handle_Process);
        }
        //fprintf(stderr, "[!] Cannot find title: %s\n", "Call of Duty 4"); 

        free(multi_byte_title);
    }
    
    free(title);
    return TRUE;
}

void EnumProcess()
{
   fprintf(stdout, "##########################################################################################################\n"); 
   EnumWindows(EnumWindowsProc_GPI, 0);
   fprintf(stdout, "##########################################################################################################\n\n");
}

void GetCurrentTitle()
{
    TCHAR titleBuffer1[MAX_PATH];
    TCHAR titleBuffer2[MAX_PATH];
    TCHAR newTitle[] = TEXT("C4 Injector");

    if (GetConsoleTitle(titleBuffer1, MAX_PATH) == 0)
    {
        std::cerr << "[!] Failed to get console title. Error code: " << GetLastError() << std::endl;
        exit(EXIT_FAILURE);
    }

    StringCchPrintf(titleBuffer2, MAX_PATH, TEXT("Current Console Title: %s"), titleBuffer1);
    fprintf(stdout, "%s\n", titleBuffer2);

    if(!SetConsoleTitle(newTitle))
    {
        std::cerr << "[!] Failed to set console title. Error code: " << GetLastError() << std::endl;
        return;
    }
    else
    {
        fprintf(stdout, "[+] Console title set to: C4 Injector\n\n");
    }
}

int main()
{
   GetCurrentTitle();
   EnumProcess();
   system("pause");
   system("color 7");
}