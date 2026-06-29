#include <iostream>
#include "parser.h"
#include "Redis.h"

using namespace std;

int main() {
    string input;
    Redis db;

    while (true) {
        cout << "redis> ";
        getline(cin, input);

        if (input == "EXIT")
            break;

        parse(input, db);
    }

    return 0;
}