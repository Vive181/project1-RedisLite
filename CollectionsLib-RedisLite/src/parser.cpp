#include <iostream>
#include <sstream>
#include "parser.h"

using namespace std;

void parse(string input, Redis& db) {
    string command, key, value;
    stringstream ss(input);

    ss >> command;

    // Convert command to uppercase
    for (char& c : command) {
        c = toupper(c);
    }

    if (command == "SET") {
        ss >> key;
        getline(ss, value);
        // Trim leading spaces from value
        size_t start = value.find_first_not_of(" \t");
        if (start != string::npos) {
            value = value.substr(start);
        } else {
            value = "";
        }
        db.set(key, value);
        cout << "OK" << endl;
    }
    else if (command == "GET") {
        ss >> key;
        string result = db.get(key);
        if (result != "") {
            cout << result << endl;
        } else {
            cout << "(nil)" << endl;
        }
    }
    else if (command == "DEL") {
        ss >> key;
        bool result = db.del(key);
        cout << (result ? "(integer) 1" : "(integer) 0") << endl;
    }
    else {
        cout << "Unknown Command" << endl;
    }
}