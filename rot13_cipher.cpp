#include <iostream>
using namespace std;


int main()
{
    while (1) {
        char* word = new char[128];
        char message[256] = {};

        cin.sync();

        cout << "podaj tekst: " << endl;
        cin.getline(message, 128);
        //65-90
        //97-122
        for (int i = 0; i < strlen(message); i++) {
            if ((message[i] >= 97) && (message[i] <= 122)) {
                message[i] = message[i] - 97;
                message[i] = ((message[i] + 13) % 26);
                message[i] = message[i] + 97;
            }
            if ((message[i] >= 65) && (message[i] <= 90)) {
                message[i] = message[i] - 65;
                message[i] = ((message[i] + 13) % 26);
                message[i] = message[i] + 65;
            }
            if (message[i] == 32) {
                continue;
            }
            if ((message[i] < 65) || (message[i] > 122) || ((message[i] > 90) && (message[i] < 97)) ) {
                cout << "podaj tekst bez znakow";
                exit(1);
            }
        }
        cout << "Slowo: " << message << endl;
    }
}

