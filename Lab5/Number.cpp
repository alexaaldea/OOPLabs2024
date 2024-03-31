#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <stdio.h>
#include <iostream>
#include <cstring>
Number::Number(const char* value, int base)
{
	int i, lg = 0;
	this->baza = base;
	for (i = 0; value[i] != '\0'; i++)
		lg++;
	Numar = new char[lg+1];
	this->count = lg;
	for (i = 0; i < lg; i++)
		Numar[i] = value[i];
	Numar[lg] = '\0';
}
Number::Number(Number&& ex) {
	this->Numar = new char [sizeof(ex.Numar)];
	this->baza = ex.baza;
	this->count = ex.count;

	this->Numar = NULL;
	this->baza = 0;
	this->count = 0;
}

void Number::CopyChar(char* destinatie, char* decopiat)
{
	int i;
	for (i = 0; i < GetDigitsCount(); i++)
		decopiat[i] = destinatie[i];
	destinatie[GetDigitsCount() + 1] = '\0';
}
Number::Number(const Number& ex)
{
	this->baza = ex.baza;
	this->count = ex.count;
	this->Numar = new char[GetDigitsCount() + 1];
	CopyChar(this->Numar, ex.Numar);
}
Number::Number(int value)
{
	int aux = value, i;
	int v[100];
	this->count = 0;
	this->baza = 10;
	Numar = new char[100];
	while (aux != 0)
	{
		v[count] = aux % 10;
		count++;
		aux = aux / 10;
	}
	aux = count-1;
	for (i = aux; i >=0; i--)
		 Numar[aux-i] = v[i] + '0';
	Numar[count] = '\0';
}

Number::~Number()
{
	Numar = nullptr;
	delete[] Numar;
}
unsigned int Number::GetBase10Number() const
{
	unsigned int result = 0, power = 1;

	for (int i = count - 1; i >= 0; i--)
	{
		if (Numar[i] >= '0' && Numar[i] <= '9')
			result += (Numar[i] - '0') * power;
		else
			result += (Numar[i] - 'A' + 10) * power;
		power = power * baza;
	}
	return result;
}
void Number::SwitchBase(int newBase)
{
	int b10 = GetBase10Number();
	///std::cout << "bla " << b10;
	int aux = b10;
	count = 0;
	baza = newBase;
	while (aux > 0)
	{
		aux /= newBase;
		count++;
	}
	///count--;
	Numar = new char[100];
	aux = count-1;
	while (b10 > 0)
	{
		int rest = b10 % newBase;
		if (rest < 10)
			Numar[aux] = rest + '0';
		else
			Numar[aux] = rest - 10 + 'A';
		aux--;
		b10 /= newBase;
	}
	Numar[count] = '\0';
}
void Number::Print()
{
	int i;
	for (i = 0; i < GetDigitsCount(); i++)
		printf("%c", this->Numar[i]);
	printf("\n");
}
int  Number::GetDigitsCount()
{
	return this->count;
}
int  Number::GetBase()
{
	return this->baza;
}

Number& Number::operator --()///prefixat
{
	int i;
	for (i = 0; i < GetDigitsCount() - 1; i++)
		this->Numar[i] = this->Numar[i + 1];
	this->Numar[this->GetDigitsCount() - 1] = '\0';
	return (*this);
}
Number& Number::operator --(int value)///postfixat
{
	this->Numar[this->GetDigitsCount() - 1] = '\0';
	return (*this);
}

int Number::operator[](int index)
{
	if(index>0 && index<GetDigitsCount())
	   return this->Numar[index];
}
bool Number::operator<(const Number& i) {
	if (GetBase10Number() < i.GetBase10Number())
		return true;
	return false;
}
bool Number::operator>(const Number& i) {
	if (GetBase10Number() > i.GetBase10Number())
		return true;
	return false;
}
bool Number::operator>=(const Number& i) {
	if (GetBase10Number() >= i.GetBase10Number())
		return true;
	return false;
}
bool Number::operator<=(const Number& i) {
	if (GetBase10Number() <= i.GetBase10Number())
		return true;
	return false;
}
bool Number::operator==(const Number& i) {
	if (GetBase10Number() == i.GetBase10Number())
		return true;
	return false;
}
bool Number::operator!=(const Number& i) {
	if (GetBase10Number() != i.GetBase10Number())
		return true;
	return false;
}
Number& Number::operator=(const char* v) {
	int i;
	this->baza = 10;
	this->count = 0;
	for (i = 0; v[i] != '\0'; i++)
		count++;
	Numar = new char[100];
	int aux = count - 1;
	for (i = aux; i >= 0; i--)
		Numar[i] = v[i];
	Numar[count] = '\0';
	return (*this);
}

Number& Number::operator =(const Number& otherNumber)
{
		delete[] Numar;
		Numar = new char[100] {};
		strcpy(Numar, otherNumber.Numar);
		count = otherNumber.count;
		baza = otherNumber.baza;
	return *this;
}

unsigned int GetBaseLenght(int number, int base)
{
	int aux = 0;
	while (number > 0)
	{
		number /= base;
		aux++;
	}
	return aux;
}
char* GetNumberInBase(int number, int base, int lg)
{
	char* sir2 = new char[lg + 1];
	sir2[lg + 1] = '\0';
	while (number > 0)
	{
		int rest = number % base;
		if (rest < 10)
			sir2[lg] = rest + '0';
		else
			sir2[lg] = rest - 10 + 'A';
		lg--;
		number /= base;
	}
	return sir2;
}

Number operator+(Number num1, Number num2)
{
	int baza10 = num1.GetBase10Number() + num2.GetBase10Number();
	///trb sa transformam aux in baza cea mai mare dintre cele 2 numere
	int maxBase = num1.GetBase();
	if (maxBase < num2.GetBase())
		maxBase = num2.GetBase();
	int count = GetBaseLenght(baza10, maxBase);
	char* sir3 = new char[count + 1] {};
	Number resultat(GetNumberInBase(baza10, maxBase, count - 1), maxBase);
	return resultat;
}
Number operator-(Number& num1, Number& num2)
{
	int baza10 = num1.GetBase10Number() - num2.GetBase10Number();
	///trb sa transformam aux in baza cea mai mare dintre cele 2 numere
	int maxBase = num1.GetBase();
	if (maxBase < num2.GetBase())
		maxBase = num2.GetBase();
	int count = GetBaseLenght(baza10, maxBase);
	char* sir3 = new char[count + 1] {};
	Number resultat(GetNumberInBase(baza10, maxBase, count - 1), maxBase);
	return resultat;
}
Number operator+=(Number& value1, Number& value2)
{
	value1 = value1 + value2;
	return 1;
}
