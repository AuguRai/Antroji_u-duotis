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
	duomenys() : egz_rez_(0) { };
	void vidurkis();
	void mediana();
	void setvardas(string vardas);
	void setpavarde(string pavarde);
	void setnd(vector <int> nd);
	void setegzaminas(int egzaminas);
	string getvardas();
	string getpavarde();
	int getegzaminas();
	vector <int> getnd();
	double getvidurkis();
	double getmediana();
	void read_and_calc(ifstream& open_f, int nd_count);
};

bool compareByMean(duomenys&, duomenys&);
bool compareAscending(duomenys&, duomenys&);
string read_line(ifstream& open_f);