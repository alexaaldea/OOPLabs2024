#pragma once
class Number
{
	// add data members
	char* Numar;
	int baza;
	int count;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	Number(const Number& ex);///copy constructor
	Number(Number&& ex);///move constructor
	Number(int value);///move assignment operator
	void CopyChar(char* destinatie, char* decopiat);
	// add operators and copy/move constructor
	Number& operator --();
	Number& operator --(int value);
	Number& operator =(const Number& otherNumber);
	friend Number operator+=(Number& value1, Number& value2);
	int operator[](int index);
	bool operator<(const Number& i);
	bool operator>(const Number& i);
	bool operator>=(const Number& i);
	bool operator<=(const Number& i);
	bool operator==(const Number& i);
	bool operator!=(const Number& i);
	Number& operator=(const char* v); //egalul pentru "123"
	
	///friend& Number operator+=(Number& value1, Number& value2);
	friend Number operator+(Number num1, Number num2);
	friend Number operator-(Number& num1, Number& num2);
	
	unsigned int GetBase10Number() const;
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};

