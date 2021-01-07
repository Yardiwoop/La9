// Laba9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iterator>
#include"Exam.h"

int main()
{
	MyNamespace::Algorithm A;
	A.algorithm1();
	std::ifstream file;
	file.open("T2.txt");
	try {
		if (!file.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		MyNamespace::Exception ex(i);
		ex.Print();
		return 0;
	}
	char str[256];
	while (!file.getline(str, sizeof(str)).eof())
		std::cout << str << std::endl;
	file.close();
	std::list<MyNamespace::Exam> L;
	MyNamespace::Exam T1;
	MyNamespace::Exam T2;
	std::fstream file1;
	file1.open("T3.txt");
	std::string str1;
	std::string str2;
	char c;
	for (int i = 0;;i++)
	{
		do {
			file1.get(c);
			str1 += c;
		} while (c != ' ' && c != '\n');
		do {
			file1.get(c);
			str2 += c;
		} while (c != '\n' && c != ' ');
		if (file1.eof()) break;
		MyNamespace::Exam T(str1, str2);
		if (i==3) T1 = T;
		if (i == 2) T2 = T;
		str1.clear();
		str2.clear();
		L.push_back(T);
		if (file1.eof())
			break;
	}
	try {
		if (L.size() <= 0)
		{
			throw 2;
		}
	}
	catch (int i)
	{
		MyNamespace::Exception ex(i);
		ex.Print();
		return 0;
	}
	std::list<MyNamespace::Exam>::iterator It;
	It = L.begin();
	while (It != L.end())
	{
		std::cout << *It;
		It++;
	}
	std::cout << "\nThe desired element: " << std::endl;
	std::cout << T1;
	A.algorithm2(It = L.begin(), It = L.end(), T1);
	std::cout << "\n-----------------------------------------------------------------\n";
	std::list<MyNamespace::Exam> L2;
	std::cout << "\nThe copy element in list 2: " << std::endl;
	L2.push_back(T2);
	A.algorithm3(It = L.begin(), It = L.end(), T2, L);
	file1.close();
	It = L2.begin();
	while (It != L2.end())
	{
		std::cout << *It;
		It++;
	}
	std::cout << "\nThe new list 1: " << std::endl;
	It = L.begin();
	while (It != L.end())
	{
		std::cout << *It;
		It++;
	}
}
