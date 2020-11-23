#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void encrypt(string& text, int k){
	if (k > 26) {
		k = k % 26;
	}

	for (int i = 0; i < text.length(); i++){
		if (text[i] == ' ') {
			continue;
		}
			text[i] += k;
			if (text[i] > 'Z') {
				text[i] -= 26;
			}
	}
}

void decrypt(string& text, int k){
	if (k > 26) {
		k = k % 26;
	}

	for (int i = 0; i < text.length(); i++){
		if (text[i] == ' ') {
			continue;
		}
		text[i] -= k;
		if (text[i] < 'A') {
			text[i] += 26;
		}
	}
}

int main(){
	string text;
	int n, key;

	cout << "encrypt(1) decrypt(2) ";
	cin >> n;

	if (n == 1){
		cout << "Text: ";
		cin.ignore();
		getline(cin, text);
		transform(text.begin(), text.end(), text.begin(), ::toupper);
		cout << "Key: ";
		cin >> key;
		encrypt(text, key);
		cout << text << endl;
	}
	else if (n == 2){
		cout << "Text: ";
		cin.ignore();
		getline(cin, text);
		transform(text.begin(), text.end(), text.begin(), ::toupper);
		cout << "Key: ";
		cin >> key;
		decrypt(text, key);
		cout << text << endl;
	}
}
