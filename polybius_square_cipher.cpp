#include <iostream>
#include <string>

#define SIZE 7

using namespace std;

char cipherArray[][SIZE] =
{
	{'A', 'B', 'C', 'D', 'E', 'F'},
	{'G', 'H', 'I', 'J', 'K', 'L'},
	{'M', 'N', 'O', 'P', 'Q', 'R'},
	{'S', 'T', 'U', 'V', 'W', 'X'},
	{'Y', 'Z', ' ', '1', '2', '3'},
	{'4' ,'5', '6', '7', '8', '9'},
	{'0', '?', '?', '?', '?', '?'}
};


string Encryption(string mesageToEncrypt)
{
	string message = "";
	bool notFound;

	for (int i = 0; mesageToEncrypt[i]; i++)
	{
		notFound = true;

		if (mesageToEncrypt[i] >= 97 && mesageToEncrypt[i] <= 122)
			mesageToEncrypt[i] = mesageToEncrypt[i] - 32;

		for (int c = 0; c < SIZE; c++)
		{
			for (int r = 0; r < SIZE; r++)
			{
				if (mesageToEncrypt[i] == cipherArray[c][r])
				{
					notFound = false;
					message.append(to_string(c + 1) + to_string(r + 1) + " ");
				}
			}
		}

		if (notFound)
			message.append("?? ");
	}

	return message;
}

string Decryption(string messageToDecrypt)
{
	string message = "";

	if (messageToDecrypt.length() % 3 != 0)
	{
		cout << "Niepoprawny format " << endl;
		return "?";
	}

	for (int i = 0; i < messageToDecrypt.length() - 2; i = i + 3)
	{

		if (!(((isdigit(messageToDecrypt[i]) && ((messageToDecrypt[i] - 48) <= SIZE) && ((messageToDecrypt[i] - 48) >= 1)) || messageToDecrypt[i] == '?') && ((isdigit(messageToDecrypt[i + 1]) && ((messageToDecrypt[i + 1] - 48) <= SIZE) && ((messageToDecrypt[i + 1] - 48) >= 1)) || messageToDecrypt[i + 1] == '?') && (messageToDecrypt[i + 2] == ' ')))
		{
			cout << "incorrect format of message!" << endl;
			return "?";
		}

		if (messageToDecrypt[i] == '?' && messageToDecrypt[i + 1] == '?')
			message.push_back('?');
		else
			message.push_back(cipherArray[messageToDecrypt[i] - 48 - 1][messageToDecrypt[i + 1] - 48 - 1]);
	}

	return message;
}

int main()
{
	int c;

		cout << "Szyfr Polibiusza " << endl
			<< "1. Zaszyfruj" << endl
			<< "2. Odszyfruj" << endl
			<< "3. Wyjscie" << endl
			<< "Wybor: ";
		cin >> c;

		char message[256]={};

		switch (c)
		{
		case 1:
			cin.ignore();
			cout << "Szyfrowanie \n";
			cout << "Wpisz wiadomosc: ";
			cin.getline(message, 128);
			cout << "Zaszyfrowana wiadomosc " << Encryption((string)message) << endl;
			break;

		case 2:
			cin.ignore();
			cout << "Odszyfrowywanie \n";
			cout << "Wpisz wiadomosc: ";
			cin.getline(message, 128);
			cout << "Odszyfrowana wiadomosc: " << Decryption((string)message) << endl;
			break;

		case 3:
			exit(0);
			break;

		default:
			cout << "Wybierz" << endl;
		}

		system("pause");
		system("cls");
}
