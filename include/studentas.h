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
/**
* Bazine klase, kurioje saugoma informacija apie zmogu (jo varda, pavarde).
*
* Klaseje realizuoti zmogaus vardo bei pavardes set'eriai bei get'eriai, sukurti konstruktoriai
*
*/
class zmogus
{
protected:
	/**
	* string tipo kintamasis, kuriame saugomas zmogaus vardas
	*/
	string vardas_;
	/**
	* string tipo kintamasis, kuriame saugoma zmogaus pavarde
	*/
	string pavarde_;

public:
	/**
	* Default tipo konstruktorius
	*/
	zmogus() : vardas_(""), pavarde_("") {};
	/**
	*Konstruktorius, skirtas sukurti nauja "zmogus" objekta
	* @param vardas zmogaus vardas
	* @param pavarde zmogaus pavarde
	*/
	zmogus(string vardas, string pavarde);
	/**
	* Nustato zmogaus varda
	*
	* @param vardas zmogaus vardas
	*/
	void setvardas(string vardas);
	/**
	*Nustato zmogaus pavarde
	*
	* @param pavarde zmogaus pavarde
	*/
	void setpavarde(string pavarde);
	/**
	*Grazina zmogaus varda
	*
	* Vardo grazinimas
	*/
	virtual const string getvardas() const = 0;
	/**
	* Pavardes grazinimas
	*/
	virtual const string getpavarde() const = 0;
};

/**
* Isvestine klases zmogus klase, kurioje saugoma informacija apie studenta (jo namu darbu rezultatus, egzamino rezultata)
* Klaseje atliekamas galutinio balo skaiciavimas pagal vidurki ir mediana.
*
*/

class studentas :public zmogus
{
private:
	/**
	* vector tipo kintamasis, kuriame saugomi studento namu darbu pazymiai
	*/
	vector <int> nd_rez_;
	/**
	* int tipo kintamasis, kuriame saugomas studento egzamino rezultatas
	*/
	int egz_rez_;
	/**
	* double tipo kintamasis, kuriame saugoma studento galutinio balo mediana
	*/
	double mediana_;
	/**
	* double tipo kintamasis, kuriame saugomas studento galutinio balo vidurkis
	*/
	double vidurkis_;

public:
	/**
	*Default tipo konstruktorius
	*/
	studentas() : egz_rez_(0) {};
	/**
	*Konstruktorius, skirtas sukurti nauja studentas objekta
	*
	* @param vardas studento vardas
	* @param pavarde studento pavarde
	* @param nd studento namu darbu rezultatai
	* @param egzaminas studento egzamino rezultatas
	*/
	studentas(string vardas, string pavarde, vector<int> nd, int egzaminas);
	/**
	* Copy konstruktorius
	*
	* @param s studento objektas
	*/
	studentas(const studentas& s);
	/**
	* Copy assignment operatorius
	*
	* @param st studento objektas
	*
	*/
	studentas& operator =(const studentas& st);
	/**
	* Isvesties operatorius, skirtas objekto isvedimui
	*
	* @param out skirtas isvesti objektui
	* @param st studento objektas
	*/
	friend std::ostream& operator<<(std::ostream&, const studentas&);
	/**
	* Ivesties operatorius
	*
	* @param in skirta ivesti objekta
	* @param st studento objektas
	*/
	friend std::istream& operator>>(std::istream&, studentas&);
	/**
	* Skaiciuojama galutinio balo mediana
	*
	*/
	void mediana();
	/**
	* Grazinama medianos reiksme
	*/
	double getmediana() const;
	/**
	* Grazinama vardas
	*/
	string const getvardas() const;
	/**
	* Grazinama pavarde
	*/
	string const getpavarde() const;
	/**
	* Destruktorius
	*/
	~studentas();
	/**
	* Skirtas nustatyti namu darbu rezultatus
	*
	* @param nd namu darbu rezultatai,saugomi vektoriuje
	*/
	void setnd(vector <int> nd);
	/**
	* Grazina namu darbu rezultatus
	*/
	vector <int> getnd() const;
	/**
	* Nustato studentu egzaminu rezultatus
	*
	* @param egzaminas studento egzamino rezultatas
	*/
	void setegzaminas(int egzaminas);
	/**
	* Grazina studento egzamino rezultata
	*/
	int getegzaminas() const;
	/**
	* Galutinio balo vidurkio skaiciavimas
	*/
	void vidurkis();
	/**
	* Grazina studento galutinio balo vidurki
	*
	*/
	double getvidurkis() const;
	/**
	* Duomenu nuskaitymas ir galutinio balo skaiciavimas
	*
	* @param open_f failo nuskaitymui
	* @param nd_count kiek is viso namu darbu
	*
	*/
	void read_and_calc(ifstream& open_f, int nd_count);
};
/**
* Palyginimas pagal vidurki
*
* @param data1 pirmojo studento objektas
* @param data2 antrojo studento objektas
*
* @return true arba false priklausomai nuo palygintu studentu vidurkiu
*/
bool compareByMean(studentas&, studentas&);
/**
* Palyginimas pagal varda ir pavarde
*
* @param data1 pirmojo studento objektas
* @param data2 antrojo studento objektas
*
* @return true arba false priklausomai ar palygintu studentu vardas (jei lygus - pavarde) pagal abecele turi buti auksciau ar zemiau
*/
bool compareAscending(studentas&, studentas&);
/**
* Eilutes nuskaitymas
*
* @return grazina nuskaityta eilute
*/
string read_line(ifstream& open_f);
/**
* "Vargsiuku" (kurie gavo maziau nei 5) ieskojimas pagal vidurki
*
* @param studentas objektas, kuriame saugoma informacija apie studenta
*/
bool rasti_vargsiukus(studentas studentas);
