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

class zmogus
{
protected:
	string vardas_;
	string pavarde_;

public:
	zmogus() : vardas_(""), pavarde_("") {};
	zmogus(string vardas, string pavarde);
	void setvardas(string vardas);
	void setpavarde(string pavarde);
	virtual const string getvardas() const = 0;
	virtual const string getpavarde() const = 0;
};

class studentas:public zmogus
{
private:
	vector <int> nd_rez_; 
	int egz_rez_; 
	double mediana_; 
	double vidurkis_; 

public:
	studentas() : egz_rez_(0) {}; 
	studentas(string vardas, string pavarde, vector<int> nd, int egzaminas);
	studentas(const studentas& s);
	studentas& operator =(const studentas& st);
	friend std::ostream& operator<<(std::ostream&, const studentas&);
	friend std::istream& operator>>(std::istream&, studentas&);
	void mediana();
	double getmediana() const;
	string const getvardas() const;
	string const getpavarde() const;
	~studentas();
	void setnd(vector <int> nd);
	vector <int> getnd() const;
	void setegzaminas(int egzaminas);
	int getegzaminas() const;
	void vidurkis();
	double getvidurkis() const;
	void read_and_calc(ifstream& open_f, int nd_count);
};
bool compareByMean(studentas&, studentas&);
bool compareAscending(studentas&, studentas&);
string read_line(ifstream& open_f);
bool rasti_vargsiukus(studentas studentas);