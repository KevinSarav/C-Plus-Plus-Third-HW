#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct message {
	int messageNum;
	string codedMessage;
	string decodedMessage;
};

string decode(string coded, string codes[], string decodes[]);

int main() {
	string inp, line;
	ifstream read;
	ofstream write("out.txt");
	string *coded = new string[26];
	string *decoded = new string[26];
	int i, size;

	cout << "Please input the input file name with its extension: ";
	cin >> inp;
	read.open(inp);

	if (read.is_open()) {
		for(i = 0; i < 26; i++) {
			getline(read, line);
			coded[i] = string(1, line.at(0));
			decoded[i] = string(1, line.at(4));
		}

		getline(read, line);
		size = int(line.at(0)) - 48;
		message *struc = new message[size];
		
		for (i = 0; i < size; i++) {
			getline(read, line);
			struc[i].messageNum = i + 1;
			struc[i].codedMessage = line;
			struc[i].decodedMessage = decode(line, coded, decoded);
		}

		for (i = 0; i < size; i++) {
			write << "Message Num: " << struc[i].messageNum << endl <<
				"Coded Message \n" <<
				struc[i].codedMessage << endl <<
				"Decoded Message \n" <<
				struc[i].decodedMessage << endl;
		}
	}
	else
		cout << "Input File unable to open.";
}

string decode(string coded, string codes[], string decodes[])
{
	int j, k;
	string decoded = "";

	for (j = 0; j < int(coded.length()); j++) {
		for (k = 0; k < 26; k++) {
			string str(1, coded.at(j));
			if (str == codes[k]) {
				decoded += decodes[k];
				break;
			}
			else if (k == 25) {
				decoded += str;
				break;
			}
		}
	}

	return decoded;
}
