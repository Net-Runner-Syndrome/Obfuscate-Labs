#include <iostream>
#include <windows.h>
#include <strsafe.h>

BOOL CALLBACK v_0x0001(HWND v_0x0002, LPARAM v_0x0003)
{
    DWORD v_0x0004{0}; 
    DWORD v_0x0005{0};
    DWORD v_0x0006{0};

    if (!IsWindowVisible(v_0x0002) || (GetWindowTextLength(v_0x0002) == 0))
    {
        return TRUE;
    }

    int v_0x0007 = GetWindowTextLength(v_0x0002);
    wchar_t* v_0x0008 = (wchar_t*)malloc((v_0x0007 + 1) * sizeof(wchar_t));
    //wchar_t* v_0x0008 = (wchar_t*)malloc((v_0x0007 + 1));
    //v_0x0009 v_0x000A;
    if(*v_0x0008 != 0)
    {
        GetWindowTextW(v_0x0002, v_0x0008, v_0x0007 + 1);
        int v_0x000B = WideCharToMultiByte(CP_ACP, 
            0, 
            v_0x0008, 
            -1, //sizeof(v_0x0008) + 1, 
            NULL, 
            0, 
            NULL, NULL);
        char* v_0x000C = (char*)malloc((v_0x000B) * sizeof(char));
        //char* v_0x000C = (char*)malloc((v_0x0007 + 1));

        WideCharToMultiByte(CP_ACP, 
            0, 
            v_0x0008, 
            -1,//sizeof(v_0x0008) + 1, 
            v_0x000C, 
            v_0x000B, 
            NULL, NULL);
        GetWindowThreadProcessId(v_0x0002, &v_0x0004);
        fprintf(stdout, "v_0x000D v_0x000E: %v_0x000F | v_0x0010: %v_0x0011 | v_0x0012 v_0x0013: %v_0x0011 | v_0x0014 v_0x0013: %v_0x0011\v_0x0015",  v_0x000C, v_0x0002, GetWindowThreadProcessId(v_0x0002, &v_0x0004), v_0x0004); 

        if(strcmp(v_0x000C, "v_0x0016 v_0x0017 v_0x0018 4") == 0)
        {
            fprintf(stdout, "[+] v_0x0019 v_0x0014 v_0x001A!\v_0x0015");
            const char* v_0x001B = "v_0x001C:\\v_0x001D.v_0x001E";
            int v_0x001F = strlen(v_0x001B); //v_0x000B v_0x0017 v_0x0020 v_0x0021 v_0x0022 v_0x0023 v_0x0024 v_0x0025
            SIZE_T* v_0x0026{nullptr};
            v_0x0006 = GetWindowThreadProcessId(v_0x0002, &v_0x0005);
            HANDLE v_0x0027 = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, v_0x0005);
            if (GetLastError() == ERROR_INVALID_PARAMETER || GetLastError() == ERROR_ACCESS_DENIED)
            {
                system("color 6");
                fprintf(stderr, "[-] HANDLE v_0x0028: v_0x0029 v_0x002A v_0x002B v_0x002C v_0x002D -> v_0x002E %v_0x0011\v_0x0015", GetLastError()); 
                fprintf(stdout, "v_0x0010: %v_0x0011 | v_0x0014 v_0x0013: %v_0x0011 | v_0x0016 v_0x0017 v_0x0018 4 v_0x0012 v_0x0013: %v_0x0011\v_0x0015\v_0x0015", v_0x0027, v_0x0005, v_0x0006);
                exit(EXIT_FAILURE);
            }

            LPVOID v_0x002F = VirtualAllocEx(v_0x0027, 
                                            NULL,   
                                            v_0x001F, //4096, 
                                            MEM_COMMIT | MEM_RESERVE | MEM_TOP_DOWN, PAGE_EXECUTE_READWRITE);

            if(!(WriteProcessMemory(v_0x0027, 
                                    v_0x002F, 
                                    v_0x001B, //&v_0x002F, 
                                    v_0x001F, 
                                    v_0x0026))) // 0/10 v_0x0030
            {
                system("color 4");
                fprintf(stderr, "\v_0x0031 v_0x0032 v_0x0033 v_0x0034 v_0x0035 v_0x0036, v_0x0037 v_0x0038 v_0x0039: %v_0x0011\v_0x0015", GetLastError()); 
                fprintf(stdout, "v_0x000D v_0x000E: %v_0x000F | v_0x0010: %v_0x0011 | v_0x0012 v_0x0013: %v_0x0011 | v_0x0014 v_0x0013: %v_0x0011\v_0x0015\v_0x0015",  v_0x000C, v_0x0027, v_0x0006, v_0x0005);
                exit(EXIT_FAILURE);
            }
            
                fprintf(stdout, "[+] v_0x003A v_0x003B\v_0x0015");
                fprintf(stdout, "[+] v_0x0010: %v_0x0011 | v_0x0014 v_0x0013: %v_0x0011 | v_0x0016 v_0x0017 v_0x0018 4 v_0x0012 v_0x0013: %v_0x0011\v_0x0015", v_0x0027, v_0x0005, v_0x0006);
                fprintf(stdout, "[v_0x003C] v_0x003A v_0x003D v_0x003E: [%v_0x003F]\v_0x0015\v_0x0015\v_0x0015", v_0x002F);
                system("color 2");

                SECURITY_ATTRIBUTES v_0x0040{};
                v_0x0040.nLength = sizeof(v_0x0040);
                v_0x0040.lpSecurityDescriptor = NULL;
                v_0x0040.bInheritHandle = FALSE;

                HANDLE v_0x0041 = CreateRemoteThread(v_0x0027, &v_0x0040, 0, 
                    (LPTHREAD_START_ROUTINE)LoadLibraryA, 
                    (LPVOID)"v_0x001C:\\v_0x001D.v_0x001E", 0, NULL);   // 0/10 v_0x0030

                CloseHandle(v_0x0041);
                CloseHandle(v_0x0027);
        }
        //fprintf(stderr, "[!] v_0x0042 v_0x0043 v_0x0008: %v_0x000F\v_0x0015", "v_0x0016 v_0x0017 v_0x0018 4"); 

        free(v_0x000C);
    }
    
    free(v_0x0008);
    return TRUE;
}

void v_0x0044()
{
   fprintf(stdout, "##########################################################################################################\v_0x0015"); 
   EnumWindows(v_0x0001, 0);
   fprintf(stdout, "##########################################################################################################\v_0x0015\v_0x0015");
}

void v_0x0045()
{
    TCHAR v_0x0046[MAX_PATH];
    TCHAR v_0x0047[MAX_PATH];
    TCHAR v_0x0048[] = TEXT("v_0x001D v_0x0049");

    if (GetConsoleTitle(v_0x0046, MAX_PATH) == 0)
    {
        std::cerr << "[!] v_0x004A v_0x0032 v_0x004B v_0x004C v_0x0008. v_0x004D v_0x004E: " << GetLastError() << std::endl;
        exit(EXIT_FAILURE);
    }

    StringCchPrintf(v_0x0047, MAX_PATH, TEXT("v_0x004F v_0x0050 v_0x000E: %v_0x000F"), v_0x0046);
    fprintf(stdout, "%v_0x000F\v_0x0015", v_0x0047);

    if(!SetConsoleTitle(v_0x0048))
    {
        std::cerr << "[!] v_0x004A v_0x0032 v_0x0051 v_0x004C v_0x0008. v_0x004D v_0x004E: " << GetLastError() << std::endl;
        return;
    }
    else
    {
        fprintf(stdout, "[+] v_0x0050 v_0x0008 v_0x0051 v_0x0032: v_0x001D v_0x0049\v_0x0015\v_0x0015");
    }
}

int main()
{
   v_0x0045();
   v_0x0044();
   system("pause");
   system("color 7");
}