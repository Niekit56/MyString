#pragma once

#ifndef MyString
#define MYSTRING_H

#include <cstring>
#include <stdexcept>
using namespace std;

class MyString
{
public:

	// Default constructor
	MyString()
	{
		str = nullptr;
	}

	// Constructor with C-style string parameter
	MyString(const char* str)
	{
		int length = strlen(str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	};

	// Assignment operator
	MyString& operator =(const MyString& other)
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}
		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';

		return *this;
	}

	// Copy constructor
	MyString(const MyString& other)
	{
		MyString newStr;

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		newStr.str = new char[thisLength + otherLength + 1];

		// Copy the content of the current string
		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}

		// Append the content of the other string
		for (int j = 0; j < otherLength; i++, j++)
		{
			newStr.str[i] = other.str[j];
		}
		newStr.str[thisLength + otherLength] = '\0';
	}

	// Concatenation operator
	MyString operator+(const MyString& other)
	{
		MyString newStr;

		// Calculate the lengths of both strings
		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		// Allocate new memory and copy the content from the other string
		newStr.str = new char[thisLength + otherLength + 1];

		// Copy the content of the current string
		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}

		// Append the content of the other string
		for (int j = 0; j < otherLength; i++, j++)
		{
			newStr.str[i] = other.str[j];
		}
		newStr.str[thisLength + otherLength] = '\0'; // Null-terminate the string

		return newStr;
	}

	// Comparison operators
	bool operator==(const MyString& other)
	{
		return strcmp(str, other.str) == 0;
	}

	bool operator!=(const MyString& other)
	{
		return !(*this == other);
	}

	bool operator<(const MyString& other)
	{
		return strcmp(str, other.str) < 0;
	}

	bool operator>(const MyString& other)
	{
		return strcmp(str, other.str) > 0;
	}

	bool operator<=(const MyString& other)
	{
		return strcmp(str, other.str) <= 0;
	}

	bool operator>=(const MyString& other)
	{
		return strcmp(str, other.str) >= 0;
	}

	// Check if the string is empty
	bool empty()
	{
		return (str == nullptr || *str == '\0');
	}

	// Access the first character of the string
	char& front() {
		if (str == nullptr || *str == '\0') {
			// If the string is empty, throw an exception
			throw out_of_range("String is empty");
		}
		return *str;
	}

	// Access the last character of the string
	char& back() {
		if (str == nullptr || *str == '\0') {
			throw out_of_range("String is empty");
		}
		// Find the last character of the string
		char* ptr = str;
		while (*(ptr + 1) != '\0') {
			++ptr;
		}
		return *ptr;
	}

	// Function to return the length of the string
	int length()
	{
		return strlen(str);
	}

	// Overloaded subscript operator to access individual characters of the string by index
	const char& operator[](int index) {
		return str[index];
	}

	// Function to return a pointer to the internal C-style string representation
	const char* c_str() const {
		return str;
	}

	// Destructor
	~MyString() {
		delete[] this->str;
	};

	// Display output
	void Print() {
		cout << str;
		cout << endl;
	}
private:
	char* str;
};

#endif // MYSTRING_H