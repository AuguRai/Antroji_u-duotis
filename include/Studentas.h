#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

using std::string;
using std::vector;
using std::ifstream;
using std::sort;
using std::cout;
using std::stringstream;
using std::endl;

class duomenys
{
private:
	string vardas_;
	string pavarde_;
	vector <int> nd_rez_;
	int egz_rez_;
	double mediana_;
	double vidurkis_;

public:
	duomenys() : egz_rez_(0) {};
	/*duomenys() 
	{
		vardas_ = "";
		pavarde_ = "";
		egz_rez_ = 0;
		vidurkis_ = 0;
		mediana_ = 0;
	}*/
	duomenys(string vardas, string pavarde, vector<int> nd, int egzaminas);
	duomenys(const duomenys& s);
	duomenys& operator =(const duomenys& st);
	void mediana();
	double getmediana() const;
	~duomenys();
	void setvardas(string vardas);
	string getvardas() const;
	void setpavarde(string pavarde);
	string getpavarde() const;
	void setnd(vector <int> nd);
	vector <int> getnd() const;
	void setegzaminas(int egzaminas);
	int getegzaminas() const;
	void vidurkis();
	double getvidurkis() const;
	void read_and_calc(ifstream& open_f, int nd_count);
};

bool compareByMean(duomenys&, duomenys&);
bool compareAscending(duomenys&, duomenys&);
string read_line(ifstream & open_f);