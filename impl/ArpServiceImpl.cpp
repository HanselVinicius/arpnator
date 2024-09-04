#include <iostream>
#include <cstdio> 
#include <memory> 
#include <stdexcept> 
#include <string>   

using namespace std;

string executeArp() {
    const char* cmd = "arp -v";

    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw runtime_error("popen() falhou!");
    }

    char buffer[128];
    string result;

    while (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
        result += buffer;
    }

    return result;
}