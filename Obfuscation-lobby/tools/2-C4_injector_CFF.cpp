#include <iostream>
#include <windows.h>
#include <strsafe.h>
#include <cstdlib>
#include <cstdio>
#include <filesystem>
#include <array>
//#include <yourMom>
//CTF CHALLENGE, FIND WHAT PROCESS THIS IS TARGETING + Fix Memory Leaks

void ASCII()
    {
        SetConsoleOutputCP(CP_UTF8);
        std::cout << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡤⠤⠔⠒⠒⣋⣛⣭⡥⠉⠂⣒⣒⣒⣀⣈⣍⣩⣉⣝⣛⣒⣶⠤⣄⡀⠀⠀⠀⠈⠀⠀⠉⠀⠓⠒⠀⠇⠀⠛⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠔⠚⢉⣁⣤⣄⣶⡶⠿⣙⣮⣭⣶⡾⠿⣿⣿⣽⣿⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣤⣒⣦⢠⠖⠋⣁⣤⡖⢼⡻⠜⣃⣭⣴⡾⣟⣹⣥⡵⠶⠟⠛⠛⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠛⠛⠳⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣾⡏⣽⣿⣿⣭⣤⡀⢠⣴⣾⢿⣿⡯⠶⠛⠋⠉⠀⠀⠀⢀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢸⣷⣸⣿⠋⠀⠀⢹⢟⡻⠗⠋⠁⠀⠀⠀⠀⠀⠀⢀⣾⣿⣶⣿⣯⣍⡛⠿⢖⣲⡶⢤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠿⣾⣿⠃⠀⠀⠘⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠠⠭⣙⠶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢿⣹⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡾⣹⣿⠿⠋⠉⠉⠉⠉⠳⠿⢷⣄⠀⠀⠀⠀⠉⠈⢝⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢸⡏⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣞⣵⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣧⠀⠀⠀⠀⠀⠀⠑⡷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣷⢻⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣾⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣬⢹⣷⠀⠀⠀⠀⠀⠀⠈⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢹⡾⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢸⣿⣿⢃⣀⣀⡀⣄⠀⢠⣴⣶⣶⣌⢻⣿⣿⣇⠀⠀⠀⠀⠀⠀⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠈⣿⢿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣷⢹⠂⣿⣿⣿⣿⣿⡎⣿⣿⣿⠀⢀⠇⠀⠀⡆⢀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢻⣼⣇⠀⠀⠀⠀⠀⠀⠀⠀⢀⡏⣿⡟⣿⣿⣿⠏⣘⡀⠸⢿⣿⣿⣿⣳⣿⢹⣿⠀⡎⡇⢿⣜⢼⣾⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠸⣇⣿⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⣿⣧⣈⣭⡵⢸⣿⣿⡜⢶⣮⣭⣴⣟⣵⣿⣿⠘⣢⣧⣆⣷⡼⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢿⣸⡇⠀⠀⠀⠀⠀⠀⠀⣿⣻⣿⣿⣿⣿⣇⣘⢋⢛⢃⠘⣯⣿⣿⣷⣷⣿⣿⡆⢱⣿⣽⢻⣽⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⣏⣷⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⢿⢼⢼⢿⣾⣿⣿⣿⣿⢿⣿⣿⣿⣦⢻⡟⣾⣿⣯⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                            ____________________
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⢻⡆⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⡿⣹⢾⢾⣼⣞⣿⣿⣿⣧⣿⣿⣿⣿⡿⣜⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           |  HAPPY HALLOWEEN  | 
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡟⣧⠀⠀⠀⠀⠀⢀⣸⣿⣿⣿⣿⣿⡗⠜⠹⠏⠟⠋⢚⣡⣾⣿⣿⣿⠿⠋⡾⢫⣿⣿⠋⠙⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           |                   | 
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⢿⡀⠀⠀⣀⣤⣾⠁⠙⢿⣿⣿⣿⣿⣶⢶⢶⢶⢾⡿⡿⣿⣿⡿⡟⠀⠀⡁⡜⠃⣿⡄⠀⠀⠙⢿⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀                                           |        by         |
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣇⡤⠚⠉⠉⠻⣦⡀⠈⠻⣿⣿⢿⣿⣿⢸⢸⣸⣷⣿⡿⡿⠃⠀⠀⣜⡜⠇⡾⡫⡂⡀⣠⠠⣻⡿⠻⢿⣦⠀⠀⠀⠀⠀⠀                                           |NET-RUNNER-SYNDROME|
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣼⣷⣿⠀⠀⠀⠀⠀⠈⢇⠀⠀⠹⣿⣧⡟⣻⣿⣿⣿⣿⡿⠋⠀⠀⣠⣸⡷⣭⠅⠁⡇⣡⣎⣽⡔⠃⠀⠀⠀⣿⣧⠀⠀⠀⠀⠀                                           |___________________|
⠀⠀⠀⠀⠀⠀⢀⣠⣞⠃⠀⢿⣾⣇⡤⡀⢀⣄⢢⡪⣳⡀⠀⠙⣻⣻⣽⢺⣿⣿⣿⢁⠄⢀⣞⣿⣿⣻⣿⣷⣿⣾⣿⡿⣀⣀⡀⠀⠀⠀⢻⣿⣷⡄⠀⠀⠀
⠀⠀⠀⢀⣤⡶⢛⣻⣿⣷⣦⣸⣿⣷⣿⣯⣮⣫⡓⣝⣻⣷⠄⠀⠈⣷⡖⣧⢿⣿⣯⣿⡿⣿⣼⡿⠟⠋⠉⠁⠀⠉⠛⠿⣷⣶⣶⡦⠀⠀⠸⡯⣿⣿⣆⠀⠀
⠀⠀⣠⠟⠁⠀⠀⠀⠈⠉⠉⢹⠟⠛⣛⣿⣿⣿⣿⣾⣟⣾⣿⣢⡌⣷⣿⣿⢿⣿⣻⣿⣿⣿⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣿⣶⣦⡄⠀⠑⠈⣿⣿⣆⠀
⠀⣰⠃⠀⠀⠀⠀⠀⠀⡠⠒⣵⣶⠿⠟⠙⢻⠿⣿⣿⣿⣿⣿⣳⡿⣻⣿⣧⣾⣿⡿⣿⣿⢿⣿⣿⣶⣄⠀⠀⠀⠀⠀⠀⡀⠀⢿⣿⡿⣿⣷⣤⣦⢾⣿⣿⡄
⠀⣿⣄⢀⢀⠀⠀⠀⢸⣗⡫⢟⣎⣭⣤⠾⣿⣶⣴⣹⣿⣿⣿⣿⣿⣿⣿⣿⣻⣿⣷⣿⣽⣻⣿⣿⣿⣿⣷⣄⡀⠀⠈⡼⣵⡆⠘⣿⣿⡌⢻⣷⣪⢾⣿⣿⣇
⢸⡏⣹⢘⡼⡆⠀⢸⣼⣷⠿⠿⢛⣛⣡⣀⣹⣩⣛⢿⣿⣿⣿⣿⣿⣿⣿⠿⢛⣽⣾⣿⣿⢯⡿⣿⣿⣿⣿⣿⣯⢾⣀⡓⣿⣿⣷⢿⣿⣿⡀⠙⣷⣿⣿⣿⣿
⠘⣧⡟⣸⢷⣇⠀⢰⣿⣿⣿⣿⣟⣿⡿⣻⡿⠟⣛⣻⣿⣿⣿⣿⣿⠟⣡⣾⣿⢟⣿⡿⣱⣿⣽⣿⣿⣿⣿⣿⣿⣯⣯⣷⣿⠏⣯⣾⣿⣿⣷⣾⣿⣿⣿⣿⣿
⠀⣿⣵⣷⣯⣿⣆⠰⣿⣿⣿⣷⣾⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠉⠉⠁⠈⡉⣠⣬⣿⣿⣿⣿⣿⣿⣿⣿⣿⢻⠛⣬⡀⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿
⠀⠸⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣴⣤⣷⡇⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠆⣿⣇⣿⣾⣹⡷⡊⢿⢸⢸⢸⣿⡆
⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⡿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣄⣆⢿⣷⣿⣿⣷⣷⣷⣿⢾⣽⣻⢷⠁
⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡻⢿⢈⣿⣿⣿⣿⣿⡿⣏⠗⡽⡻⠃⠀
⠀⠀⠀⠀⠛⣏⢿⣿⣿⣿⣽⡟⣿⣿⣅⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣻⣾⣿⣿⣿⣿⣿⣿⠃⢘⡶⢱⠃⠀⠀
⠀⠀⠀⠀⠀⠹⡾⣿⣿⣿⣾⣇⣼⡿⠎⠐⠿⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣳⣿⣿⣿⣿⣿⡟⡽⡟⠃⠀⠘⠁⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠘⢆⠠⡻⣿⣿⣿⣿⣼⠇⠀⠀⠈⡿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢋⠸⠃⠋⣼⣿⡱⠃⡸⡫⣿⡟⠏⠀⠼⠀⠀⡠⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠈⠻⣦⡈⣿⢧⡀⠀⠀⠀⠛⡃⣶⣾⢻⣿⣿⣿⣿⣿⣿⡁⠀⠟⠀⠘⣽⡟⠀⠁⠈⠀⠠⠏⠀⡔⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        )" <<std::endl<<std::endl;
    }

struct StringArray
{
    char** data;
    size_t size;
    size_t capacity;

    const char* V1()
    {
        static const char V[15] = {0x42, 0x60, 0x6D, 0x6D, 0x21, 
                                   0x6E, 0x67, 0x21, 0x45, 0x74, 
                                   0x75, 0x78, 0x21, 0x35, 0x00};
        const char* V1 = V;
        return V;
    }
    
    bool InitArr(StringArray* arr, size_t initialCapacity = 0)
    {
        ASCII();
        arr->data = static_cast<char **>(malloc(sizeof(char*) * initialCapacity));
        if(arr->data == nullptr)
        {
            //free(arr->data);
            return false;
        }
        
        arr->size = 0;
        arr->capacity = initialCapacity;
        return true;
    }

    bool pushBack(StringArray* arr, const char* source)
    {
        char* encoded = nullptr;
        char* decoded = nullptr;
        encoded = copyString(EncryptString(source, 0x01)); free(EncryptString(source, 0x01));
        //decoded = copyString(DecryptString(encoded, 0x01)); free(DecryptString(source, 0x01));

        char* copy = (decoded == nullptr) ? encoded : decoded;
        if(copy == nullptr)
        {
            std::cout << "[-] Failed to allocate memory!" << std::endl;
            return false;
        }

        if(arr->size == arr->capacity)
        {
            size_t newCapacity = (arr->capacity == 0) ? 2 : arr->capacity*2;
            char** newData = static_cast<char**>(realloc(arr->data, newCapacity*sizeof(char*)));
            if(newData == nullptr)
            {
                std::cout << "[-] Failed to reallocate memory!" << std::endl;
                free(copy);
                copy = nullptr;
                return false;
            }

            arr->data = newData;
            arr->capacity = newCapacity;
        }

        arr->data[arr->size] = copy;
        arr->size++;
        return true;
    }

    char* copyString(const char* source)
    {
        size_t length = strlen(source);
        char* copy = static_cast<char*>(malloc(length + 1));
        if (copy == nullptr)
        {
            std::cout << "[-] Failed to allocate memory!" << std::endl;
            return nullptr;
        }

        memcpy(copy, source, length + 1);
        return copy;
    }

    char* EncryptString(const char* source, unsigned char key)
    {
        if (source == nullptr)
        {
            std::cout << "Source does not have an initialized address" << std::endl;
            return nullptr;
        }
        
        size_t length = strlen(source);
        char* encoded = static_cast<char*>(malloc(length + 1));
        if(encoded == nullptr)
        {
            std::cout << "Cannot allocate memory for encoded key" << std::endl;
            return nullptr;
        }

        for (size_t i = 0; i < length; i++)
        {
            encoded[i] = source[i]^key;
        }
        encoded[length] = '\0';
        return encoded;
    }

    char* DecryptString(const char* source, unsigned char key)
    {
        if (source == nullptr)
        {
            std::cout << "Source does not have an initialized address" << std::endl;
            return nullptr;
        }
        
        size_t length = strlen(source);
        char* decoded = static_cast<char*>(malloc(length + 1));
        if(decoded == nullptr)
        {
            std::cout << "Cannot allocate memory for decoded key" << std::endl;
            return nullptr;
        }

        for (size_t i = 0; i < length; i++)
        {
            decoded[i] = source[i]^key; 
        }
        decoded[length] = '\0';
        return decoded;
    }

    void StringInfo(const StringArray* arr)
    {
        for(size_t i = 0; i < arr->size; i++)
        {
            printf("Size: [%zu] %s\n", i, arr->data[i]);
        }

        printf("\nSize: %zu\n", arr->size);
        printf("Capacity: %zu\n", arr->capacity);
        //free(arr->data);
    }

    void DestroyArray(StringArray* arr)
    {
        if(arr == nullptr)
            return;

        for (size_t i = 0; i < arr->size; i++)
        {
            free(arr->data[i]);
            arr->data[i] = nullptr;
        }

        free(arr->data);
        arr->data=nullptr;
        arr->size=0;
        arr->capacity=0;
    }
};

void TestVector()
{
    StringArray Obj{nullptr, 0, 0};
    if (!Obj.InitArr(&Obj, 2))
    {
        std::cout << "[-] Failed to allocate memory!" << std::endl;
        exit(EXIT_FAILURE);
    }

    if(!Obj.pushBack(&Obj, "Test1") || !Obj.pushBack(&Obj, "Test2") || !Obj.pushBack(&Obj, "Test3") || !Obj.pushBack(&Obj, "Test4")
    || !Obj.pushBack(&Obj, "Test5") || !Obj.pushBack(&Obj, "Test6") || !Obj.pushBack(&Obj, "Test7") || !Obj.pushBack(&Obj, "Test8")
    || !Obj.pushBack(&Obj, "Test9") || !Obj.pushBack(&Obj, "Test10")|| !Obj.pushBack(&Obj, "Test11"))
    {
        std::cout << "[-] Insertion failed" << std::endl;
        return;
    }

    Obj.StringInfo(&Obj);
    Obj.DestroyArray(&Obj);
}

BOOL CALLBACK EnumWindowsProc_GPI(HWND hwnd, LPARAM lparam)
{
    StringArray* Obj = reinterpret_cast<StringArray*>(lparam);
    DWORD hwnd_procID{0}; 
    DWORD procID{0};
    DWORD C4ProcID{0};

    if(Obj == nullptr)
    {
        std::cerr << "[!] Cannot dereference String Array." << std::endl;
        return FALSE;
    }

    if (!IsWindowVisible(hwnd) || (GetWindowTextLength(hwnd) == 0))
    {
        return TRUE; //FALSE
    }

    int length = GetWindowTextLength(hwnd);
    wchar_t* title = (wchar_t*)malloc((length + 1) * sizeof(wchar_t));
    //wchar_t* title = (wchar_t*)malloc((length + 1));
    //LPSTR stringBuffer;
    if(*title != 0)
    {
        GetWindowTextW(hwnd, title, length + 1);
        int size = WideCharToMultiByte(CP_UTF8, 
            0, 
            title, 
            -1, //sizeof(title) + 1, 
            NULL, 
            0, 
            NULL, NULL);
        char* multi_byte_title = (char*)malloc((size) * sizeof(char));
        //char* multi_byte_title = (char*)malloc((length + 1));

        WideCharToMultiByte(CP_UTF8, 
            0, 
            title, 
            -1,//sizeof(title) + 1, 
            multi_byte_title, 
            size, 
            NULL, NULL);
        GetWindowThreadProcessId(hwnd, &hwnd_procID);
        fprintf(stdout, "Window Title: %s | Handle: %d | Thread ID: %d | Process ID: %d\n",  multi_byte_title, hwnd, GetWindowThreadProcessId(hwnd, &hwnd_procID), hwnd_procID); 
     
        if(!Obj->pushBack(Obj, multi_byte_title))
        {
            std::cerr << "[-] Failed to store window title." << std::endl;
            free(multi_byte_title);
            free(title);
            return FALSE;
        }

        if(strcmp(Obj->EncryptString(multi_byte_title, 0x01), Obj->V1()) == 0)
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
                fprintf(stdout, "Handle: %d | Process ID: %d | %s: %d\n\n", Handle_Process, procID, Obj->DecryptString(Obj->EncryptString(multi_byte_title, 0x01), 0x1), C4ProcID);
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
                fprintf(stdout, "Window Title: %s | Handle: %d | Thread ID: %d | Process ID: %d\n\n",  Obj->DecryptString(Obj->EncryptString(multi_byte_title, 0x01), 0x1), Handle_Process, C4ProcID, procID);
                exit(EXIT_FAILURE);
            }
            
                fprintf(stdout, "[+] Injected successfully\n");
                fprintf(stdout, "[+] Handle: %d | Process ID: %d | %s: %d\n", Handle_Process, procID, Obj->DecryptString(Obj->EncryptString(multi_byte_title, 0x01), 0x1), C4ProcID);
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
        //fprintf(stderr, "[!] Cannot find title: %s\n", "[Process Target]"); 
        free(multi_byte_title);
    }
    
    free(title);
    return TRUE;
}

void EnumProcess(StringArray* Obj)
{
   fprintf(stdout, "##################################################################################################################################\n"); 
   EnumWindows(EnumWindowsProc_GPI, reinterpret_cast<LPARAM>(Obj));
   fprintf(stdout, "##################################################################################################################################\n\n");
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

bool LaunchProcess()
{
    //So surprisingly, CreateProcessW(...) does not work with relative paths... so we need to make a workaround that. Sorry for the extra 65536 bytes of memory  
    constexpr size_t MAX_EXECUTABLE_PATH_LENGTH = 32768;
    std::array<wchar_t, MAX_EXECUTABLE_PATH_LENGTH> buffer{};
    DWORD length = GetModuleFileNameW(nullptr, buffer.data(), static_cast<DWORD>(buffer.size()));
    if(length==0 || length >= buffer.size())
    {
        std::wcerr << L"[-] Failed to retrieve launcher path. Error: " << GetLastError() << L"\n";
        return false;
    }
 
    std::filesystem::path launcherPath(buffer.data());
    std::filesystem::path projectRoot = launcherPath.parent_path()
                                       .parent_path()
                                       .parent_path();

    std::filesystem::path ePath = projectRoot / L"tools" / L"COD4_mltpClient.exe";
    std::filesystem::path workingDirectory = ePath.parent_path();
    if(!std::filesystem::exists(ePath) || !std::filesystem::is_regular_file(ePath))
    {
        std::wcerr << L"[-] Exacutable not found: " << ePath.wstring() << L"\n";
        return false;
    }

    if (!std::filesystem::is_directory(workingDirectory))
    {
        std::wcerr << L"[-] Working directory not found: " << workingDirectory.wstring() << L'\n';
        return false;
    }

    STARTUPINFOW SI{};
    SI.cb = sizeof(SI);
    PROCESS_INFORMATION PI{};

    BOOL success = CreateProcessW(
        ePath.c_str(),
        nullptr,
        nullptr, 
        nullptr,
        FALSE,
        0,
        nullptr,
        workingDirectory.c_str(),
        &SI,
        &PI
    );

    if(!success)
    {
        std::wcerr << L"[-] CreateProcessW failed. Error: " << GetLastError() << L'\n';
        return false;
    }

    CloseHandle(PI.hThread);
    CloseHandle(PI.hProcess);
    return true;
}

void Dispatcher()
{
    /*
    ORDER OF EXECUTION:
        Obj.InitArr(&Obj);
        GetCurrentTitle(); 
        EnumProcess(&Obj); 
        Obj.StringInfo(&Obj); 
        Obj.DestroyArray(&Obj);
    */ 
   StringArray Obj;
   int stateID = 0;
   bool match = false;

   while (match != true)
   {
        switch(stateID)
        {
            case 0:
            if(LaunchProcess())
            {
                std::cout << "[+] Found Process Launch" << std::endl;
            }

            stateID = 0;
            ++stateID; ++stateID;
            ++stateID; ++stateID;
            break;

            case 1:
            Obj.StringInfo(&Obj);
            stateID = 2;
            break;

            case 2:
            Obj.DestroyArray(&Obj);
            //TestVector();
            stateID = 6;
            match = true;
            break;

            case 3:
            EnumProcess(&Obj);
            stateID = 1;
            break;

            case 4:
            Obj.InitArr(&Obj);
            stateID = 5;
            break;
     
            case 5: 
            GetCurrentTitle();
            stateID = 3;
            break;

            default:
            std::cerr << "[!] Something fishy just happened" << std::endl;
            stateID=0;
            exit(EXIT_FAILURE);
            break;
        }
   }
}

int main()
{
   Dispatcher();
   system("pause");
   system("color 7");
   return 0;
}