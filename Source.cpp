#include<iostream>
#include"MyString.h"
using namespace std;

int main() {
	setlocale(0, "");

	MyString str("Hello");
	MyString str1("Hello ");
	MyString str2("World");
	MyString str3(" !!");
	MyString str4("");

	MyString result(str1 + str2 + str3);

	cout << "str2 = ";
	str2.Print();
	cout << "str = ";
	str.Print();
	cout << "result = ";
	result.Print();

	// Comparison operators
	cout << "--------------------" << "\n";
	bool result1 = str == str1;
	cout << "result(str == str1) = " << result1 << endl;
	cout << "--------------------" << "\n";
	bool result2 = str != str3;
	cout << "result(str != str3) = " << result2 << endl;
	cout << "--------------------" << "\n";
	bool result3 = str1 < str2;
	cout << "result(str1 < str2) = " << result3 << "\n";
	cout << "--------------------" << "\n";
	bool result4 = str1 > str2;
	cout << "result(str1 > str2) = " << result4 << "\n";
	cout << "--------------------" << "\n";
	bool result5 = str1 >= str2;
	cout << "result(str1 >= str2) = " << result5 << "\n";
	cout << "--------------------" << "\n";
	bool result6 = str1 <= str2;
	cout << "result(str1 <= str2) = " << result6 << "\n";
	cout << "--------------------" << "\n";

	cout << "String length(str): " << str.length() << endl;
	cout << "--------------------" << "\n";

	// Use the [] operator to access string characters
	for (int i = 0; i < str.length(); ++i) {
		cout << str[i] << " ";
	}
	cout << endl;

	// Use the c_str() method to get a pointer to a C string
	const char* cstring = str.c_str();
	cout << "--------------------" << "\n";

	// Display the C string on the screen
	cout << "C-style string: " << cstring << endl;
	cout << "--------------------" << "\n";

	//Indicates whether the string is empty or not
	bool empty = str4.empty();
	cout << empty << endl;
	cout << "--------------------" << "\n";

	char firstChar = str.front();
	cout << "The first char of string " << firstChar << endl;
	cout << "--------------------" << "\n";

	char lastChar = str.back();
	cout << "The last char of string " << lastChar << endl;

	return 0;
}
