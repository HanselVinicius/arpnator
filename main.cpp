#include <iostream>
#include <string>
#include "headers/ArpService.h"

using namespace std;

int main() {
    string arp = executeArp();
    cout << "Saída do comando 'arp -v':\n" << arp << endl;
    return 0;
}