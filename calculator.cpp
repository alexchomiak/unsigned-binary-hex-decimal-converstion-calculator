#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>  
#include <algorithm>

using namespace std;


void strupper(string &s) {
	 transform(s.begin(),s.end(),s.begin(),::toupper);
}
string hexchar2fourbits(char hexchar) {
	hexchar = toupper(hexchar);
	switch(hexchar) {
		case '0':
			return "0000";
			break;
		case '1':
			return "0001";
			break;
		case '2':
			return "0010";
			break;
		case '3':
			return "0011";
			break;
		case '4':
			return "0100";
			break;
		case '5':
			return "0101";
			break;
		case '6':
			return "0110";
			break;
		case '7':
			return "0111";
			break;
		case '8':
			return "1000";
			break;
		case '9':
			return "1001";
			break;
		case 'A':
			return "1010";
			break;
		case 'B':
			return "1011";
			break;
		case 'C':
			return "1100";
			break;
		case 'D':
			return "1101";
			break;
		case 'E':
			return "1110";
			break;
		case 'F':
			return "1111";
			break;


	}
	
}

char fourbits2hexchar(string fourbits) {
	if(fourbits == "0000") return '0';
	if(fourbits == "0001") return '1';
	if(fourbits == "0010") return '2';
	if(fourbits == "0011") return '3';
	if(fourbits == "0100") return '4';
	if(fourbits == "0101") return '5';
	if(fourbits == "0110") return '6';
	if(fourbits == "0111") return '7';
	if(fourbits == "1000") return '8';
	if(fourbits == "1001") return '9';
	if(fourbits == "1010") return 'A';
	if(fourbits == "1011") return 'B';
	if(fourbits == "1100") return 'C';
	if(fourbits == "1101") return 'D';
	if(fourbits == "1110") return 'E';
	if(fourbits == "1111") return 'F';
}

string binary2hex(string num) {
	int offset = 0;
	if(num.length() % 4 != 0) {
		offset = 4 - (num.length() % 4);
		for(int i = 0; i < offset; i++) {
			num = '0' + num;
		}
	}
	string returnHex = "";
	cout << "Converting Binary representation " << num << " to hexadecimal form." << endl;
	cout << "Charting every four characters to corresponding hexadecimal character." << endl;
	for(int i = 0; i < ((num.length() + offset)/4); i++) {
		
		cout << num.substr(i * 4, 4) << " -- " << fourbits2hexchar(num.substr(i * 4, 4)) << endl;
		returnHex +=  fourbits2hexchar(num.substr(i * 4, 4));
	}

	cout << "To end up with finalized hexadecimal form " << returnHex << endl;

	return returnHex;
}

string hex2binary(string num) {
	strupper(num);
	cout << "Converting hexadecimal form " << num << " to binary representation." << endl;
	cout << "Charting every hexadecimal character to corresponding 4 bit representation." << endl;
	string returnBinary = "";
	for(int i = 0;i < num.length(); i++) {
		cout << num.at(i) << " -- " << hexchar2fourbits(num.at(i)) << endl;
		returnBinary += hexchar2fourbits(num.at(i));
	}
	cout << "To end up with finalized binary representation " << returnBinary << "." << endl;
	return returnBinary;
}

long long binary2dec(string num) {
	long long returnNum = 0;
	cout << "Converted " << num << " to decimal represenation ";
	for(int i = 0; i < num.length(); i++) {
		if(num.at(num.length() - i - 1 ) == '1') returnNum += pow(2,i); 
	}
	cout << returnNum << "." << endl;	
	return returnNum;
}


string dec2binary(long long num) {
	string returnBinary = "";

	cout << "Converted decimal number " << num  <<  " to binary representation ";
	while(num != 0) {
		int rem = num % 2;
		num = num / 2;
		returnBinary =  char ('0' + rem) + returnBinary;
	}


	cout << returnBinary << "." << endl;
	return returnBinary;
}

string dec2hex(long long num) {
	return binary2hex(dec2binary(num));
}

long long hex2dec(string num) {
	strupper(num);
	return binary2dec(hex2binary(num));
}

void help() {
	cout << "----------------------------------------------------------------" << endl;
	cout <<  "Unsigned Binary, Hexadecimal and Decimal conversion calculator" << endl;
	cout << "Commands:" << endl;
	cout << "b2d <num> -- binary to decimal" << endl;
	cout << "b2h <num> -- binary to hexadecimal" << endl;
	cout << "h2d <num> -- hexadecimal to decimal" << endl;
	cout << "h2b <num> -- hexadecimal to binary" << endl;
	cout << "d2b <num> -- decimal to binary" << endl;
	cout << "d2h <num> -- decimal to hexadecimal" << endl;
	cout << "help -- prints commands" << endl;
	cout << "exit -- exit program" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << endl;
}

int main() {
	help();
	while(true) {
		bool unknownCommand = true;
		string commandType;
		cout << ">>> ";
		cin >> commandType;
		if(commandType == "b2d") {
			string num;
			cin >> num;
			cout << binary2dec(num) << endl;
			unknownCommand = false;
		}
		if(commandType == "b2h") {
			string num;
			cin >> num;
			cout << binary2hex(num) << endl;
			unknownCommand = false;
		}
		if(commandType == "h2d") {
			string num;
			cin >> num;
			cout << hex2dec(num) << endl;
			unknownCommand = false;
		}
		if(commandType == "h2b") {
			string num;
			cin >> num;
			cout << hex2binary(num) << endl;
			unknownCommand = false;
		}
		if(commandType == "d2b") {
			long long num;
			cin >> num;
			cout << dec2binary(num) << endl;
			unknownCommand = false;
		}
		if(commandType == "d2h") {
			long long num;
			cin >> num;
			cout << dec2hex(num) << endl;
			unknownCommand = false;
		}
		if(commandType == "help") {
			help();
			unknownCommand = false;
		}
		if(commandType == "exit") {
			exit(0);
		}
		
		if(unknownCommand){
			cout << "Unknown command... Try typing help to see the available commands to you." << endl;
		}


		cout << endl;
	}
}

