#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../include/headers/ArpService.hpp"
#include "../include/headers/UiService.hpp"

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void showMenu() {
    cout << "----- ARP Service Menu -----" << endl;
    cout << "1. Show ARP Table" << endl;
    cout << "2. Exit" << endl;
    cout << "----------------------------" << endl;
    cout << "Enter your choice: ";
}

void displayArpTable(const string& arpResult) {
    cout << "----- ARP Table -----" << endl;
    cout << "IP Address\t\tMAC Address\t\tInterface" << endl;
    cout << "----------------------------------------------" << endl;

    stringstream ss(arpResult);
    string line;
    while (getline(ss, line)) {
        cout << line << endl;
    }
    cout << "-----------------------------" << endl;
}

int main() {
    int choice;
    bool running = true;
    
    while (running) {
        clearScreen();
        showMenu();
        cin >> choice;

        clearScreen();

        switch (choice) {
            case 1: {
                string arpResults = executeArp();
                displayArpTable(arpResults);
                cout << "\nPress enter to return to menu...";
                cin.ignore();
                cin.get();
                break;
            }
            case 2:
                running = false;
                break;
            default:
                cout << "Invalid choice. Please select again." << endl;
                cout << "Press enter to return to menu...";
                cin.ignore();
                cin.get();
        }
    }

    cout << "Exiting..." << endl;
    return 0;
}
