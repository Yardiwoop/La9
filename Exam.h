#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include <ctime>
#include <list>

namespace MyNamespace
{
	class Exam
	{
	private:
		static int in;
		int id;
		std::string name;
		std::string teach_name;
	public:
		Exam(std::string nm, std::string dg) : name(nm), teach_name(dg)
		{
			id = in;
			in++;
		}
		Exam()
		{
			id = 0;
			in++;
			name = "-";
			teach_name = "-";
		}
		void input()
		{
			std::cout << "\nEnter your pet's name" << std::endl;
			getline(std::cin, name);
			std::cout << "\nEnter your pet's teach_name" << std::endl;
			getline(std::cin, teach_name);

		}
		void output()
		{
			std::cout << "\nId - " << id << "\nName - " << name << "\nDiagnosis - " << teach_name << std::endl;
		}
		bool operator< (Exam& c2) const
		{
			return (name[0] < c2.name[0]) ? true : false;
		}
		bool operator> (Exam& c2) const
		{
			return (name[0] > c2.name[0]) ? true : false;
		}
		bool operator== (Exam& c2) const
		{
			return (name[0] == c2.name[0]) ? true : false;
		}
		friend std::ostream& operator<<(std::ostream& out, const Exam c);
	};
	int Exam::in = -1;
	std::ostream& operator<<(std::ostream& out, const Exam c)
	{
		out << "\nId - " << c.id << "\nName - " << c.name << "\nTeachers name - " << c.teach_name << std::endl;
		return out;
	}
	class Exception
	{
	protected:
		int error;
	public:
		Exception()
		{
			error = 0;
		}
		Exception(int _error)
		{
			error = _error;
		}
		~Exception() { };
		void Print()
		{
			if (this->error == 1)
			{
				std::cout << "File isn't open!" << std::endl;
			}
			if (this->error == 2)
			{
				std::cout << "The list is empty!" << std::endl;
			}
			if (this->error < 1 || this->error > 2)
			{
				int time = clock();
				std::cout << "Error time! " << time << std::endl;
			}
		}
	};
	class Algorithm
	{
	public:
		void algorithm1()
		{
			std::ifstream file1;
			int c = 1;
			file1.open("T1.txt");
			try {
				if (!file1.is_open())
				{

					throw 1;
				}
			}
			catch (int i)
			{
				MyNamespace::Exception ex(i);
				ex.Print();
				return;
			}
			std::ofstream file2;
			file2.open("T2.txt");
			try {
				if (!file2.is_open())
				{
					throw 1;
				}
			}
			catch (int i)
			{
				MyNamespace::Exception ex(i);
				ex.Print();
				return;
			}
			while (!file1.eof())
			{
				char s[256];
				int count = 0;
				file1.getline(s, 256);
				for (int i = 0; i < 256; i++)
				{
					if (s[i] == ' ' || s[i] == '\0')
					{
						count++;
					}
					if (s[i] == '\0')
						break;
				}
				char str[] = "The number of words in line ";
				file2 << str << c << ": " << count << "\n";
				c++;
			}
			file1.close();
			file2.close();
		}
		void algorithm2(std::list<MyNamespace::Exam>::iterator  begin, std::list<MyNamespace::Exam>::iterator end, MyNamespace::Exam T)
		{
			int g = 0;
			while (begin != end)
			{
				
				begin++;
				if (begin == end) break;
				if (*begin == T)
				{
					g++;
					
				}				
			}
			std::cout << "\n\nAlgorithm 2 , quintity of elements  " << g << std::endl;
		}
		void algorithm3(std::list<MyNamespace::Exam>::iterator  begin, std::list<MyNamespace::Exam>::iterator end, MyNamespace::Exam T, std::list<MyNamespace::Exam>& L)
		{
			int i = 0;
			for (std::list<MyNamespace::Exam>::iterator i = L.begin(); i != L.end(); i++)
				if (*i == T)
				{
					L.erase(++i);
					break; 
				}
		}
	};
}