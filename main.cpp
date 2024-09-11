#include <iostream>
#include <string>
#include "../include/headers/ArpService.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

int main() {
    string arp = executeArp();
    cout << "Saída do comando 'arp -v':\n" << arp << endl;
    return 0;
}