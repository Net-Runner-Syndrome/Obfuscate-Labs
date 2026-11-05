#include <iostream>
#include <windows.h>
#include <strsafe.h>
#include <cstdlib>
#include <cstdio>
#include <filesystem>
#include <array>
//#include <v_0x0001>
//v_0x0002 v_0x0003, v_0x0004 v_0x0005 v_0x0006 v_0x0007 v_0x0008 v_0x0009 + v_0x000A v_0x000B v_0x000C

void v_0x000D()
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

struct v_0x0013
{
    char** data;
    size_t size;
    size_t v_0x0014;

    const char* v_0x0015()
    {
        static const char v_0x0016[15] = {0x42, 0x60, 0x6D, 0x6D, 0x21, 
                                   0x6E, 0x67, 0x21, 0x45, 0x74, 
                                   0x75, 0x78, 0x21, 0x35, 0x00};
        const char* v_0x0015 = v_0x0016;
        return v_0x0016;
    }
    
    bool v_0x0017(v_0x0013* v_0x0018, size_t v_0x0019 = 0)
    {
        v_0x000D();
        v_0x0018->data = static_cast<char **>(malloc(sizeof(char*) * v_0x0019));
        if(v_0x0018->data == nullptr)
        {
            //free(v_0x0018->data);
            return false;
        }
        
        v_0x0018->size = 0;
        v_0x0018->v_0x0014 = v_0x0019;
        return true;
    }

    bool v_0x001A(v_0x0013* v_0x0018, const char* v_0x001B)
    {
        char* v_0x001C = nullptr;
        char* v_0x001D = nullptr;
        v_0x001C = v_0x001E(v_0x001F(v_0x001B, 0x01)); free(v_0x001F(v_0x001B, 0x01));
        //v_0x001D = v_0x001E(v_0x0020(v_0x001C, 0x01)); free(v_0x0020(v_0x001B, 0x01));

        char* v_0x0021 = (v_0x001D == nullptr) ? v_0x001C : v_0x001D;
        if(v_0x0021 == nullptr)
        {
            std::cout << "[-] v_0x0022 v_0x0023 v_0x0024 v_0x0025!" << std::endl;
            return false;
        }

        if(v_0x0018->size == v_0x0018->v_0x0014)
        {
            size_t v_0x0026 = (v_0x0018->v_0x0014 == 0) ? 2 : v_0x0018->v_0x0014*2;
            char** v_0x0027 = static_cast<char**>(realloc(v_0x0018->data, v_0x0026*sizeof(char*)));
            if(v_0x0027 == nullptr)
            {
                std::cout << "[-] v_0x0022 v_0x0023 v_0x0028 v_0x0025!" << std::endl;
                free(v_0x0021);
                v_0x0021 = nullptr;
                return false;
            }

            v_0x0018->data = v_0x0027;
            v_0x0018->v_0x0014 = v_0x0026;
        }

        v_0x0018->data[v_0x0018->size] = v_0x0021;
        v_0x0018->size++;
        return true;
    }

    char* v_0x001E(const char* v_0x001B)
    {
        size_t v_0x0029 = strlen(v_0x001B);
        char* v_0x0021 = static_cast<char*>(malloc(v_0x0029 + 1));
        if (v_0x0021 == nullptr)
        {
            std::cout << "[-] v_0x0022 v_0x0023 v_0x0024 v_0x0025!" << std::endl;
            return nullptr;
        }

        memcpy(v_0x0021, v_0x001B, v_0x0029 + 1);
        return v_0x0021;
    }

    char* v_0x001F(const char* v_0x001B, unsigned char v_0x002A)
    {
        if (v_0x001B == nullptr)
        {
            std::cout << "v_0x002B v_0x002C v_0x002D v_0x002E v_0x002F v_0x0030 v_0x0031" << std::endl;
            return nullptr;
        }
        
        size_t v_0x0029 = strlen(v_0x001B);
        char* v_0x001C = static_cast<char*>(malloc(v_0x0029 + 1));
        if(v_0x001C == nullptr)
        {
            std::cout << "v_0x0032 v_0x0024 v_0x0025 for v_0x001C v_0x002A" << std::endl;
            return nullptr;
        }

        for (size_t v_0x0033 = 0; v_0x0033 < v_0x0029; v_0x0033++)
        {
            v_0x001C[v_0x0033] = v_0x001B[v_0x0033]^v_0x002A;
        }
        v_0x001C[v_0x0029] = '\0';
        return v_0x001C;
    }

    char* v_0x0020(const char* v_0x001B, unsigned char v_0x002A)
    {
        if (v_0x001B == nullptr)
        {
            std::cout << "v_0x002B v_0x002C v_0x002D v_0x002E v_0x002F v_0x0030 v_0x0031" << std::endl;
            return nullptr;
        }
        
        size_t v_0x0029 = strlen(v_0x001B);
        char* v_0x001D = static_cast<char*>(malloc(v_0x0029 + 1));
        if(v_0x001D == nullptr)
        {
            std::cout << "v_0x0032 v_0x0024 v_0x0025 for v_0x001D v_0x002A" << std::endl;
            return nullptr;
        }

        for (size_t v_0x0033 = 0; v_0x0033 < v_0x0029; v_0x0033++)
        {
            v_0x001D[v_0x0033] = v_0x001B[v_0x0033]^v_0x002A; 
        }
        v_0x001D[v_0x0029] = '\0';
        return v_0x001D;
    }

    void v_0x0034(const v_0x0013* v_0x0018)
    {
        for(size_t v_0x0033 = 0; v_0x0033 < v_0x0018->size; v_0x0033++)
        {
            printf("v_0x0035: [%zu] %s\n", v_0x0033, v_0x0018->data[v_0x0033]);
        }

        printf("\nv_0x0039: %zu\n", v_0x0018->size);
        printf("v_0x003A: %zu\n", v_0x0018->v_0x0014);
        //free(v_0x0018->data);
    }

    void v_0x003B(v_0x0013* v_0x0018)
    {
        if(v_0x0018 == nullptr)
            return;

        for (size_t v_0x0033 = 0; v_0x0033 < v_0x0018->size; v_0x0033++)
        {
            free(v_0x0018->data[v_0x0033]);
            v_0x0018->data[v_0x0033] = nullptr;
        }

        free(v_0x0018->data);
        v_0x0018->data=nullptr;
        v_0x0018->size=0;
        v_0x0018->v_0x0014=0;
    }
};

void v_0x003C()
{
    v_0x0013 v_0x003D{nullptr, 0, 0};
    if (!v_0x003D.v_0x0017(&v_0x003D, 2))
    {
        std::cout << "[-] v_0x0022 v_0x0023 v_0x0024 v_0x0025!" << std::endl;
        exit(EXIT_FAILURE);
    }

    if(!v_0x003D.v_0x001A(&v_0x003D, "v_0x003E") || !v_0x003D.v_0x001A(&v_0x003D, "v_0x003F") || !v_0x003D.v_0x001A(&v_0x003D, "v_0x0040") || !v_0x003D.v_0x001A(&v_0x003D, "v_0x0041")
    || !v_0x003D.v_0x001A(&v_0x003D, "v_0x0042") || !v_0x003D.v_0x001A(&v_0x003D, "v_0x0043") || !v_0x003D.v_0x001A(&v_0x003D, "v_0x0044") || !v_0x003D.v_0x001A(&v_0x003D, "v_0x0045")
    || !v_0x003D.v_0x001A(&v_0x003D, "v_0x0046") || !v_0x003D.v_0x001A(&v_0x003D, "v_0x0047")|| !v_0x003D.v_0x001A(&v_0x003D, "v_0x0048"))
    {
        std::cout << "[-] v_0x0049 v_0x004A" << std::endl;
        return;
    }

    v_0x003D.v_0x0034(&v_0x003D);
    v_0x003D.v_0x003B(&v_0x003D);
}

BOOL CALLBACK v_0x004B(HWND v_0x004C, LPARAM v_0x004D)
{
    v_0x0013* v_0x003D = reinterpret_cast<v_0x0013*>(v_0x004D);
    DWORD v_0x004E{0}; 
    DWORD v_0x004F{0};
    DWORD v_0x0050{0};

    if(v_0x003D == nullptr)
    {
        std::cerr << "[!] v_0x0032 v_0x0051 v_0x0052 v_0x0053." << std::endl;
        return FALSE;
    }

    if (!IsWindowVisible(v_0x004C) || (GetWindowTextLength(v_0x004C) == 0))
    {
        return TRUE; //FALSE
    }

    int v_0x0029 = GetWindowTextLength(v_0x004C);
    wchar_t* v_0x0054 = (wchar_t*)malloc((v_0x0029 + 1) * sizeof(wchar_t));
    //wchar_t* v_0x0054 = (wchar_t*)malloc((v_0x0029 + 1));
    //v_0x0055 v_0x0056;
    if(*v_0x0054 != 0)
    {
        GetWindowTextW(v_0x004C, v_0x0054, v_0x0029 + 1);
        int size = WideCharToMultiByte(CP_UTF8, 
            0, 
            v_0x0054, 
            -1, //sizeof(v_0x0054) + 1, 
            NULL, 
            0, 
            NULL, NULL);
        char* v_0x0057 = (char*)malloc((size) * sizeof(char));
        //char* v_0x0057 = (char*)malloc((v_0x0029 + 1));

        WideCharToMultiByte(CP_UTF8, 
            0, 
            v_0x0054, 
            -1,//sizeof(v_0x0054) + 1, 
            v_0x0057, 
            size, 
            NULL, NULL);
        GetWindowThreadProcessId(v_0x004C, &v_0x004E);
        fprintf(stdout, "v_0x0058 v_0x0059: %s | v_0x005A: %d | v_0x005C v_0x005D: %d | v_0x005E v_0x005D: %d\n",  v_0x0057, v_0x004C, GetWindowThreadProcessId(v_0x004C, &v_0x004E), v_0x004E); 
     
        if(!v_0x003D->v_0x001A(v_0x003D, v_0x0057))
        {
            std::cerr << "[-] v_0x0022 v_0x0023 v_0x005F v_0x0060 v_0x0054." << std::endl;
            free(v_0x0057);
            free(v_0x0054);
            return FALSE;
        }

        if(strcmp(v_0x003D->v_0x001F(v_0x0057, 0x01), v_0x003D->v_0x0015()) == 0)
        {
            fprintf(stdout, "[+] v_0x0061 v_0x005E v_0x0062!\n");
            const char* v_0x0063 = "v_0x0064:\\v_0x0065.dll";
            int v_0x0039 = strlen(v_0x0063); //size v_0x0067 v_0x0068 v_0x0069 v_0x006A v_0x006B v_0x006C v_0x006D
            SIZE_T* v_0x006E{nullptr};
            v_0x0050 = GetWindowThreadProcessId(v_0x004C, &v_0x004F);
            HANDLE v_0x006F = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, v_0x004F);
            if (GetLastError() == ERROR_INVALID_PARAMETER || GetLastError() == ERROR_ACCESS_DENIED)
            {
                system("color 6");
                fprintf(stderr, "[-] HANDLE v_0x0070: v_0x0071 v_0x0072 v_0x0073 v_0x0074 v_0x0075 -> v_0x0076 %d\n", GetLastError()); 
                fprintf(stdout, "v_0x005A: %d | v_0x005E v_0x005D: %d | %s: %d\n\n", v_0x006F, v_0x004F, v_0x003D->v_0x0020(v_0x003D->v_0x001F(v_0x0057, 0x01), 0x1), v_0x0050);
                exit(EXIT_FAILURE);
            }

            LPVOID v_0x0077 = VirtualAllocEx(v_0x006F, 
                                            NULL,   
                                            v_0x0039, //4096, 
                                            MEM_COMMIT | MEM_RESERVE | MEM_TOP_DOWN, PAGE_EXECUTE_READWRITE);

            if(!(WriteProcessMemory(v_0x006F, 
                                    v_0x0077, 
                                    v_0x0063, //&v_0x0077, 
                                    v_0x0039, 
                                    v_0x006E))) // 0/10 v_0x0078
            {
                system("color 4");
                fprintf(stderr, "\v_0x0079 v_0x0023 v_0x007A v_0x007B v_0x007C v_0x0025, v_0x007D v_0x007E v_0x007F: %d\n", GetLastError()); 
                fprintf(stdout, "v_0x0058 v_0x0059: %s | v_0x005A: %d | v_0x005C v_0x005D: %d | v_0x005E v_0x005D: %d\n\n",  v_0x003D->v_0x0020(v_0x003D->v_0x001F(v_0x0057, 0x01), 0x1), v_0x006F, v_0x0050, v_0x004F);
                exit(EXIT_FAILURE);
            }
            
                fprintf(stdout, "[+] v_0x0080 v_0x0081\n");
                fprintf(stdout, "[+] v_0x005A: %d | v_0x005E v_0x005D: %d | %s: %d\n", v_0x006F, v_0x004F, v_0x003D->v_0x0020(v_0x003D->v_0x001F(v_0x0057, 0x01), 0x1), v_0x0050);
                fprintf(stdout, "[v_0x0082] v_0x0080 v_0x0083 v_0x0084: [%p]\n\n\n", v_0x0077);
                system("color 2");

                SECURITY_ATTRIBUTES v_0x0086{};
                v_0x0086.nLength = sizeof(v_0x0086);
                v_0x0086.lpSecurityDescriptor = NULL;
                v_0x0086.bInheritHandle = FALSE;

                HANDLE v_0x0087 = CreateRemoteThread(v_0x006F, &v_0x0086, 0, 
                    (LPTHREAD_START_ROUTINE)LoadLibraryA, 
                    (LPVOID)"v_0x0064:\\v_0x0065.dll", 0, NULL);   // 0/10 v_0x0078

                CloseHandle(v_0x0087);
                CloseHandle(v_0x006F);
        }
        //fprintf(stderr, "[!] v_0x0032 v_0x0088 v_0x0054: %s\n", "[v_0x005E v_0x0062]"); 
        free(v_0x0057);
    }
    
    free(v_0x0054);
    return TRUE;
}

void v_0x0089(v_0x0013* v_0x003D)
{
   fprintf(stdout, "##################################################################################################################################\n"); 
   EnumWindows(v_0x004B, reinterpret_cast<LPARAM>(v_0x003D));
   fprintf(stdout, "##################################################################################################################################\n\n");
}

void v_0x008A()
{
    TCHAR v_0x008B[MAX_PATH];
    TCHAR v_0x008C[MAX_PATH];
    TCHAR v_0x008D[] = TEXT("v_0x0065 v_0x008E");

    if (GetConsoleTitle(v_0x008B, MAX_PATH) == 0)
    {
        std::cerr << "[!] v_0x0022 v_0x0023 v_0x008F v_0x0090 v_0x0054. v_0x0091 v_0x0092: " << GetLastError() << std::endl;
        exit(EXIT_FAILURE);
    }

    StringCchPrintf(v_0x008C, MAX_PATH, TEXT("v_0x0093 v_0x0094 v_0x0059: %s"), v_0x008B);
    fprintf(stdout, "%s\n", v_0x008C);

    if(!SetConsoleTitle(v_0x008D))
    {
        std::cerr << "[!] v_0x0022 v_0x0023 v_0x0095 v_0x0090 v_0x0054. v_0x0091 v_0x0092: " << GetLastError() << std::endl;
        return;
    }
    else
    {
        fprintf(stdout, "[+] v_0x0094 v_0x0054 v_0x0095 v_0x0023: v_0x0065 v_0x008E\n\n");
    }
}

bool v_0x0096()
{
    //v_0x0097 v_0x0098, CreateProcessW(...) v_0x002C v_0x002D v_0x0099 v_0x009A v_0x009B v_0x009C... v_0x009D v_0x009E v_0x009F v_0x0023 v_0x00A0 v_0x00A1 v_0x00A2 v_0x00A3. v_0x00A4 for v_0x00A5 v_0x00A6 65536 v_0x006A v_0x0067 v_0x0025  
    constexpr size_t v_0x00A7 = 32768;
    std::array<wchar_t, v_0x00A7> v_0x00A8{};
    DWORD v_0x0029 = GetModuleFileNameW(nullptr, v_0x00A8.data(), static_cast<DWORD>(v_0x00A8.size()));
    if(v_0x0029==0 || v_0x0029 >= v_0x00A8.size())
    {
        std::wcerr << L"[-] v_0x0022 v_0x0023 v_0x00A9 v_0x00AA path. v_0x0091: " << GetLastError() << L"\n";
        return false;
    }
 
    std::filesystem::path v_0x00AB(v_0x00A8.data());
    std::filesystem::path v_0x00AC = v_0x00AB.parent_path()
                                       .parent_path()
                                       .parent_path();

    std::filesystem::path v_0x00AD = v_0x00AC / L"v_0x00AE" / L"v_0x00AF.v_0x00B0";
    std::filesystem::path v_0x00B1 = v_0x00AD.parent_path();
    if(!std::filesystem::exists(v_0x00AD) || !std::filesystem::is_regular_file(v_0x00AD))
    {
        std::wcerr << L"[-] v_0x00B2 v_0x002D v_0x00B3: " << v_0x00AD.wstring() << L"\n";
        return false;
    }

    if (!std::filesystem::is_directory(v_0x00B1))
    {
        std::wcerr << L"[-] v_0x00B4 v_0x00B5 v_0x002D v_0x00B3: " << v_0x00B1.wstring() << L'\n';
        return false;
    }

    STARTUPINFOW v_0x00B6{};
    v_0x00B6.cb = sizeof(v_0x00B6);
    PROCESS_INFORMATION v_0x00B7{};

    BOOL v_0x00B8 = CreateProcessW(
        v_0x00AD.c_str(),
        nullptr,
        nullptr, 
        nullptr,
        FALSE,
        0,
        nullptr,
        v_0x00B1.c_str(),
        &v_0x00B6,
        &v_0x00B7
    );

    if(!v_0x00B8)
    {
        std::wcerr << L"[-] CreateProcessW v_0x004A. v_0x0091: " << GetLastError() << L'\n';
        return false;
    }

    CloseHandle(v_0x00B7.hThread);
    CloseHandle(v_0x00B7.hProcess);
    return true;
}

void v_0x00B9()
{
    /*
    v_0x00BA v_0x00BB v_0x00BC:
        v_0x003D.v_0x0017(&v_0x003D);
        v_0x008A(); 
        v_0x0089(&v_0x003D); 
        v_0x003D.v_0x0034(&v_0x003D); 
        v_0x003D.v_0x003B(&v_0x003D);
    */ 
   v_0x0013 v_0x003D;
   int v_0x00BD = 0;
   bool v_0x00BE = false;

   while (v_0x00BE != true)
   {
        switch(v_0x00BD)
        {
            case 0:
            if(v_0x0096())
            {
                std::cout << "[+] v_0x0061 v_0x005E v_0x00BF" << std::endl;
            }

            v_0x00BD = 0;
            ++v_0x00BD; ++v_0x00BD;
            ++v_0x00BD; ++v_0x00BD;
            break;

            case 1:
            v_0x003D.v_0x0034(&v_0x003D);
            v_0x00BD = 2;
            break;

            case 2:
            v_0x003D.v_0x003B(&v_0x003D);
            //v_0x003C();
            v_0x00BD = 6;
            v_0x00BE = true;
            break;

            case 3:
            v_0x0089(&v_0x003D);
            v_0x00BD = 1;
            break;

            case 4:
            v_0x003D.v_0x0017(&v_0x003D);
            v_0x00BD = 5;
            break;
     
            case 5: 
            v_0x008A();
            v_0x00BD = 3;
            break;

            default:
            std::cerr << "[!] v_0x00C0 v_0x00C1 v_0x00C2 v_0x00C3" << std::endl;
            v_0x00BD=0;
            exit(EXIT_FAILURE);
            break;
        }
   }
}

int main()
{
   v_0x00B9();
   system("pause");
   system("color 7");
   return 0;
}