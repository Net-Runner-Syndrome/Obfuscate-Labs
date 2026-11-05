import re
import random

# C/C++
KEYWORDS = {
    "auto", "break", "case", "char", "const",
    "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for",
    "goto", "if", "inline", "int", "long",
    "register", "restrict", "return", "short",
    "signed", "sizeof", "static", "struct",
    "switch", "typedef", "union", "unsigned",
    "void", "volatile", "while", "HAPPY HALLOWEEN", "by", 
    "|NET-RUNNER-SYNDROME|",
    "|  HAPPY HALLOWEEN  |",
    "____________________",
    "___________________",
    "0x42, 0x60, 0x6D, 0x6D, 0x21, 0x6E, 0x67, 0x21, 0x45, 0x74, 0x75, 0x78, 0x21, 0x35, 0x00", "R",
    "0x1", "1", "2", "3", "4", "5", "6", "case", "32768", "size_t", "reinterpret_cast", "bool", "_", "|",

    # ASCII ART
    "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡤⠤⠔⠒⠒⣋⣛⣭⡥⠉⠂⣒⣒⣒⣀⣈⣍⣩⣉⣝⣛⣒⣶⠤⣄⡀⠀⠀⠀⠈⠀⠀⠉⠀⠓⠒⠀⠇⠀⠛⠀",
    "⠀⠀⠀⠀⠀⠀⠀⣀⡤⠔⠚⢉⣁⣤⣄⣶⡶⠿⣙⣮⣭⣶⡾⠿⣿⣿⣽⣿⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⠀⣤⣒⣦⢠⠖⠋⣁⣤⡖⢼⡻⠜⣃⣭⣴⡾⣟⣹⣥⡵⠶⠟⠛⠛⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠛⠛⠳⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⣾⡏⣽⣿⣿⣭⣤⡀⢠⣴⣾⢿⣿⡯⠶⠛⠋⠉⠀⠀⠀⢀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
    "⢸⣷⣸⣿⠋⠀⠀⢹⢟⡻⠗⠋⠁⠀⠀⠀⠀⠀⠀⢀⣾⣿⣶⣿⣯⣍⡛⠿⢖⣲⡶⢤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
      "⠿⣾⣿⠃⠀⠀⠘⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀⠠⠭⣙⠶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
      "⢿⣹⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡾⣹⣿⠿⠋⠉⠉⠉⠉⠳⠿⢷⣄⠀⠀⠀⠀⠉⠈⢝⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
       "⢸⡏⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣞⣵⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣧⠀⠀⠀⠀⠀⠀⠑⡷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⣷⢻⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣾⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣬⢹⣷⠀⠀⠀⠀⠀⠀⠈⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
       "⢹⡾⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⢸⣿⣿⢃⣀⣀⡀⣄⠀⢠⣴⣶⣶⣌⢻⣿⣿⣇⠀⠀⠀⠀⠀⠀⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
       "⠈⣿⢿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⣿⣿⣷⢹⠂⣿⣿⣿⣿⣿⡎⣿⣿⣿⠀⢀⠇⠀⠀⡆⢀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⢻⣼⣇⠀⠀⠀⠀⠀⠀⠀⠀⢀⡏⣿⡟⣿⣿⣿⠏⣘⡀⠸⢿⣿⣿⣿⣳⣿⢹⣿⠀⡎⡇⢿⣜⢼⣾⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        "⠸⣇⣿⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⣿⣧⣈⣭⡵⢸⣿⣿⡜⢶⣮⣭⣴⣟⣵⣿⣿⠘⣢⣧⣆⣷⡼⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
         "⢿⣸⡇⠀⠀⠀⠀⠀⠀⠀⣿⣻⣿⣿⣿⣿⣇⣘⢋⢛⢃⠘⣯⣿⣿⣷⣷⣿⣿⡆⢱⣿⣽⢻⣽⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
         "⢸⣏⣷⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⢿⢼⢼⢿⣾⣿⣿⣿⣿⢿⣿⣿⣿⣦⢻⡟⣾⣿⣯⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                            ____________________",
          "⣿⢻⡆⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⡿⣹⢾⢾⣼⣞⣿⣿⣿⣧⣿⣿⣿⣿⡿⣜⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           |  HAPPY HALLOWEEN  | ",
          "⢹⡟⣧⠀⠀⠀⠀⠀⢀⣸⣿⣿⣿⣿⣿⡗⠜⠹⠏⠟⠋⢚⣡⣾⣿⣿⣿⠿⠋⡾⢫⣿⣿⠋⠙⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                           |                   | ",
           "⠈⣿⢿⡀⠀⠀⣀⣤⣾⠁⠙⢿⣿⣿⣿⣿⣶⢶⢶⢶⢾⡿⡿⣿⣿⡿⡟⠀⠀⡁⡜⠃⣿⡄⠀⠀⠙⢿⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀                                           |        by         |",
             "⢻⣿⣇⡤⠚⠉⠉⠻⣦⡀⠈⠻⣿⣿⢿⣿⣿⢸⢸⣸⣷⣿⡿⡿⠃⠀⠀⣜⡜⠇⡾⡫⡂⡀⣠⠠⣻⡿⠻⢿⣦⠀⠀⠀⠀⠀⠀                                           |NET-RUNNER-SYNDROME|",
             "⣀⣼⣷⣿⠀⠀⠀⠀⠀⠈⢇⠀⠀⠹⣿⣧⡟⣻⣿⣿⣿⣿⡿⠋⠀⠀⣠⣸⡷⣭⠅⠁⡇⣡⣎⣽⡔⠃⠀⠀⠀⣿⣧⠀⠀⠀⠀⠀                                           |___________________|",
        "⢀⣠⣞⠃⠀⢿⣾⣇⡤⡀⢀⣄⢢⡪⣳⡀⠀⠙⣻⣻⣽⢺⣿⣿⣿⢁⠄⢀⣞⣿⣿⣻⣿⣷⣿⣾⣿⡿⣀⣀⡀⠀⠀⠀⢻⣿⣷⡄⠀⠀⠀",
    "⢀⣤⡶⢛⣻⣿⣷⣦⣸⣿⣷⣿⣯⣮⣫⡓⣝⣻⣷⠄⠀⠈⣷⡖⣧⢿⣿⣯⣿⡿⣿⣼⡿⠟⠋⠉⠁⠀⠉⠛⠿⣷⣶⣶⡦⠀⠀⠸⡯⣿⣿⣆⠀⠀",
    "⣠⠟⠁⠀⠀⠀⠈⠉⠉⢹⠟⠛⣛⣿⣿⣿⣿⣾⣟⣾⣿⣢⡌⣷⣿⣿⢿⣿⣻⣿⣿⣿⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣿⣶⣦⡄⠀⠑⠈⣿⣿⣆⠀",
    "⣰⠃⠀⠀⠀⠀⠀⠀⡠⠒⣵⣶⠿⠟⠙⢻⠿⣿⣿⣿⣿⣿⣳⡿⣻⣿⣧⣾⣿⡿⣿⣿⢿⣿⣿⣶⣄⠀⠀⠀⠀⠀⠀⡀⠀⢿⣿⡿⣿⣷⣤⣦⢾⣿⣿⡄",
    "⣿⣄⢀⢀⠀⠀⠀⢸⣗⡫⢟⣎⣭⣤⠾⣿⣶⣴⣹⣿⣿⣿⣿⣿⣿⣿⣿⣻⣿⣷⣿⣽⣻⣿⣿⣿⣿⣷⣄⡀⠀⠈⡼⣵⡆⠘⣿⣿⡌⢻⣷⣪⢾⣿⣿⣇",
    "⢸⡏⣹⢘⡼⡆⠀⢸⣼⣷⠿⠿⢛⣛⣡⣀⣹⣩⣛⢿⣿⣿⣿⣿⣿⣿⣿⠿⢛⣽⣾⣿⣿⢯⡿⣿⣿⣿⣿⣿⣯⢾⣀⡓⣿⣿⣷⢿⣿⣿⡀⠙⣷⣿⣿⣿⣿",
    "⠘⣧⡟⣸⢷⣇⠀⢰⣿⣿⣿⣿⣟⣿⡿⣻⡿⠟⣛⣻⣿⣿⣿⣿⣿⠟⣡⣾⣿⢟⣿⡿⣱⣿⣽⣿⣿⣿⣿⣿⣿⣯⣯⣷⣿⠏⣯⣾⣿⣿⣷⣾⣿⣿⣿⣿⣿",
    "⣿⣵⣷⣯⣿⣆⠰⣿⣿⣿⣷⣾⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠉⠉⠁⠈⡉⣠⣬⣿⣿⣿⣿⣿⣿⣿⣿⣿⢻⠛⣬⡀⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿",
    "⠸⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣴⣤⣷⡇⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠆⣿⣇⣿⣾⣹⡷⡊⢿⢸⢸⢸⣿⡆",
    "⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⡿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣄⣆⢿⣷⣿⣿⣷⣷⣷⣿⢾⣽⣻⢷⠁",
    "⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡻⢿⢈⣿⣿⣿⣿⣿⡿⣏⠗⡽⡻⠃⠀",
         "⠛⣏⢿⣿⣿⣿⣽⡟⣿⣿⣅⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣻⣾⣿⣿⣿⣿⣿⣿⠃⢘⡶⢱⠃⠀⠀",
         "⠹⡾⣿⣿⣿⣾⣇⣼⡿⠎⠐⠿⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣳⣿⣿⣿⣿⣿⡟⡽⡟⠃⠀⠘⠁⠀⠀⠀⠀",
      "⠘⢆⠠⡻⣿⣿⣿⣿⣼⠇⠀⠀⠈⡿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢋⠸⠃⠋⣼⣿⡱⠃⡸⡫⣿⡟⠏⠀⠼⠀⠀⡠⠀⠀⠀⠀⠀⠀",
       "⠀⠁⠀⠈⠻⣦⡈⣿⢧⡀⠀⠀⠀⠛⡃⣶⣾⢻⣿⣿⣿⣿⣿⣿⡁⠀⠟⠀⠘⣽⡟⠀⠁⠈⠀⠠⠏⠀⡔⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        

    # C/C++ types and common identifiers
    "wchar_t",
    "system",
    "std",
    "cerr",
    "cout",
    "endl",
    "stdout",
    "stderr",


    # Operators / symbols
    "*", "&", "=", "+", "-", "/", "%",
    "++", "--", "#",
    "!", "&&", "||",
    "<", ">", "<=", ">=", "==", "!=",
    "?", ":", ";", ",", ".", "->",
    "[", "]", "{", "}", "(", ")", "%n", "%p", "%s", "%d",


    # Format strings / literals
    "%d", "%s", "%p",
    "0", "\0", "%zu"
    "-1", "\n"

    # Program-specific strings
    r"C:\C4.dll",
    "pause",
    "color", " 7",

    # C++
    "class", "public", "private", "protected",
    "template", "typename", "namespace",
    "using", "new", "delete", "this",
    "virtual", "override", "final",
    "try", "catch", "throw",
    "true", "false", "nullptr", "nLength",
    "lpSecurityDescriptor", "bInheritHandle", 
    "static_cast", "STARTUPINFOW", "PROCESS_INFORMATION", 
    "constexpr", 
    "cb",

    # Libraries / headers
    "#", "include",
    "iostream", 
    "windows", "h",
    "strsafe", "h",
    "cstdlib",
    "cstdio",
    "filesystem",
    "array",
}


# Windows / Win32 API
WIN32_API = {
    "EnumWindows", "IsWindowVisible", "GetWindowTextLength", "GetWindowTextW",
    "WideCharToMultiByte", "GetWindowThreadProcessId", "OpenProcess", 
    "CloseHandle", "VirtualAllocEx", "GetLastError", "StringCchPrintf",
    "WriteProcessMemory", "CreateRemoteThread", "WaitForSingleObject",
    "GetProcAddress", "LoadLibraryA", "LoadLibraryW", "SECURITY_ATTRIBUTES",
    "LPTHREAD_START_ROUTINE", "TEXT", "CALLBACK", "GetConsoleTitle", "SetConsoleTitle", "SetConsoleOutputCP",
    "GetModuleFileNameW", "data", "size", "filesystem", "path", "parent_path", "exists", "is_regular_file", "L", "wstring",
    "is_directory", "wcerr", "CreateProcessW", "hThread", "hProcess"
}

# Windows types / constants
WIN32_TYPES = {
    "HWND",
    "HINSTANCE",
    "HICON",
    "HCURSOR",
    "HBRUSH",
    "HMENU",
    "HANDLE",
    "DWORD",
    "WORD",
    "BYTE",
    "BOOL",
    "UINT",
    "WPARAM",
    "LPARAM",
    "LRESULT",
    "LPVOID",
    "LPCSTR",
    "LPCWSTR",
    "SIZE_T",
    "TCHAR",
    "MAX_PATH"
}


WIN32_CONSTANTS = {
    "NULL",
    "TRUE",
    "FALSE",

    "MB_OK",
    "MB_OKCANCEL",
    "MB_YESNO",

    "SW_SHOW",
    "SW_HIDE",
    "SW_SHOWNORMAL",

    "CW_USEDEFAULT",

    "WM_CREATE",
    "WM_DESTROY",
    "WM_PAINT",
    "WM_CLOSE",
    "WM_COMMAND",
    "WM_SIZE",

    "CP_ACP",
    "CP_UTF8",
    "PROCESS_VM_READ",
    "PROCESS_VM_WRITE",
    "PROCESS_VM_OPERATION",
    "ERROR_INVALID_PARAMETER",
    "ERROR_ACCESS_DENIED",
    "EXIT_FAILURE",
    "MEM_COMMIT",
    "MEM_RESERVE",
    "MEM_TOP_DOWN",
    "PAGE_EXECUTE_READWRITE",
    
}

# C runtime functions
CRT_FUNCTIONS = {
    "printf",
    "fprintf",
    "sprintf",
    "snprintf",

    "scanf",
    "fscanf",
    "sscanf",

    "malloc",
    "calloc",
    "realloc",
    "free",

    "memcpy",
    "memset",
    "memcmp",

    "strlen",
    "strcmp",
    "strcpy",
    "strncpy",

    "exit",
    "abort",

    "c_str"
}


BLACKLIST = (
    KEYWORDS
    | WIN32_API
    | WIN32_TYPES
    | WIN32_CONSTANTS
    | CRT_FUNCTIONS
)

# Obfuscation counter
counter = 0

def generate_name():
    global counter
    counter += 1

    return f"v_0x{counter:04X}"

# Rename identifiers
def rename_identifiers(source):

    identifiers = re.findall(
        r'\b[A-Za-z_][A-Za-z0-9_]*\b',
        source
    )

    mapping = {}
    for identifier in identifiers:

        if identifier in BLACKLIST:
            continue

        if identifier == "main":
            continue

        # Skip already-obfuscated names
        if identifier.startswith(("v_0x", "f_0x")):
            continue

        if identifier not in mapping:
            mapping[identifier] = generate_name()

    
    for old, new in mapping.items():

        source = re.sub(
            rf'\b{re.escape(old)}\b',
            new,
            source
        )

    return source, mapping

def main():

    with open("2-C4_injector_CFF.cpp", "r", encoding="utf-8") as file:
        source = file.read()

    obfuscated, mapping = rename_identifiers(source)

    with open(
        "2-C4_injector_obfuscated.cpp",
        "w",
        encoding="utf-8"
    ) as file:
        file.write(obfuscated)

    with open(
        "2-mapping.txt",
        "w",
        encoding="utf-8"
    ) as file:

        for original, renamed in mapping.items():
            file.write(
                f"{original} -> {renamed}\n"
            )

    print("[+] Completed Obfuscation: source code written to '2-C4_injector_obfuscated.cpp'")
    print(f"Renamed {len(mapping)} identifiers.")

    
if __name__ == "__main__":
    main()