#include <iostream>
#include "hashtable.h"

using namespace std;
using namespace cop4530;

void menu() {
    int size;
    cout << "Enter HashTable size: " << endl;
    cin >> size;
    HashTable<string> htObject(size);
    char selection = '\0';
    string input;
    while (selection != 'x') {
        cout << "\n\n";
        cout << "l - Load Dictionary From File" << endl;
        cout << "a - input Word" << endl;
        cout << "r - Remove Word" << endl;
        cout << "c - Clear HashTable" << endl;
        cout << "f - input Word" << endl;
        cout << "d - Dump HashTable" << endl;
        cout << "s - HashTable Size" << endl;
        cout << "w - Write to File" << endl;
        cout << "x - Exit program" << endl;
        cout << "\nEnter choice : ";
        cin >> selection;
        switch (selection) {
            case 'l':
                break;
            case 'a':
                cout << "Enter Word: ";
                cin >> input;
                if (htObject.insert(input)) {
                    cout << "Word " << input << " added." << endl;
                } else {
                    cout << "*****: Word already exists. Could not add." << endl;
                }
                break;
            case 'r':
                cout << "Enter Word: ";
                cin >> input;
                if (htObject.remove(input)) {
                    cout << "Word " << input << " deleted." << endl;
                } else {
                    cout << "*****: Word not found. Could not delete." << endl;
                }
                break;
            case 'c':
                htObject.clear();
                break;
            case 'f':
                cout << "Enter Word: ";
                cin >> input;
                if (htObject.contains(input)) {
                    cout << "Word " << input << " found." << endl;
                } else {
                    cout << "Word " << input << " not found." << endl;
                }
                break;
            case 'd':
                htObject.dump();
                break;
            case 's':
                cout << htObject.getSize() << endl;
                break;
            default:
                cout << "*****Error: Invalid Entry. Try again. ";
                break;
        }
    }


}

int main() {

    menu();


    return 0;
}