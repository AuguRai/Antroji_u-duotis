#include "Studentas.h"


duomenys::duomenys(string vardas, string pavarde, vector<int> nd, int egzaminas)
{
    vardas_ = vardas;
    pavarde_ =  pavarde;
    nd_rez_ = nd;
    egz_rez_ = egzaminas;
}
duomenys::duomenys(const duomenys& duomenys) 
{
    vardas_ = duomenys.vardas_;
    pavarde_ = duomenys.pavarde_;
    nd_rez_ = duomenys.nd_rez_;
    egz_rez_ = duomenys.egz_rez_;
    vidurkis_ = duomenys.vidurkis_;
    mediana_ = duomenys.mediana_;
}

duomenys& duomenys::operator =(const duomenys& duomenys)
{
    if (&duomenys == this)
    { 
        return *this;
    }

    vardas_ = duomenys.vardas_;
    pavarde_ = duomenys.pavarde_;
    nd_rez_ = duomenys.nd_rez_;
    egz_rez_ = duomenys.egz_rez_;
    mediana_ = duomenys.mediana_;
    vidurkis_ = duomenys.vidurkis_;
    return *this;
}

duomenys::~duomenys() 
{
    this->nd_rez_.clear();
}

void duomenys::setvardas(string vardas)
{
    this->vardas_ = vardas;
}
string duomenys::getvardas() const
{
    return vardas_;
}
void duomenys::setpavarde(string pavarde)
{
    this->pavarde_ = pavarde;
}
string duomenys::getpavarde() const
{
    return pavarde_;
}
void duomenys::setnd(vector <int> nd)
{
    this->nd_rez_ = nd;
}
vector <int> duomenys::getnd() const
{
    return nd_rez_;
}
void duomenys::setegzaminas(int egzaminas)
{
    this->egz_rez_ = egzaminas;
}

int duomenys::getegzaminas() const
{
    return egz_rez_;
}

void duomenys::vidurkis()
{
    double rez = 0;
    double vid = 0;
    double galutinis = 0;

    if (nd_rez_.size() == 0)
        this->vidurkis_ = 0;

    for (int j = 0; j < nd_rez_.size(); j++)
        rez = rez + nd_rez_[j];


    vid = rez / nd_rez_.size();
    this->vidurkis_ = 0.4 * vid + 0.6 * egz_rez_;
}

double duomenys::getvidurkis() const 
{
    return vidurkis_;
}

void duomenys::mediana()
{
    double rez = 0;
    double med = 0;
    double galutinis = 0;

    if (nd_rez_.size() == 0)
        this->mediana_ = 0;

    sort(nd_rez_.begin(), nd_rez_.end());
    med = int(nd_rez_.size() / 2);

    if (nd_rez_.size() % 2 != 0)
        med = nd_rez_[med];

    else
        med = double(nd_rez_[med] + nd_rez_[med - 1]) / 2;

    this->mediana_ = 0.4 * med + 0.6 * egz_rez_;
}

double duomenys::getmediana() const
{
    return mediana_;
}

string read_line(ifstream& open_f)
{
    string eil;
    try
    {
        getline(open_f, eil);
    }
    catch (const ifstream::failure& e)
    {
        cout << "Klaida nuskaitant duomenis is failo: " << e.what() << endl;
        exit(0);
    }
    return eil;
}

void duomenys::read_and_calc(ifstream& open_f, int nd_count)
{
    string eil;
    eil = read_line(open_f);
    stringstream ss(eil);
    ss >> vardas_;
    ss >> pavarde_;
    string nd;
    int i = 0;
    while (i < nd_count)
    {
        ss >> nd;
        nd_rez_.push_back(stoi(nd));
        i++;
    }
    ss >> egz_rez_;
    ss.str("");
    mediana();
    vidurkis();
}

bool compareByMean(duomenys& data1, duomenys& data2)
{
    return data1.getvidurkis() < data2.getvidurkis();
}

bool compareAscending(duomenys& data1, duomenys& data2)
{
    if (data1.getvardas().compare(data2.getvardas()) == 0)
    {
        if (data1.getpavarde().compare(data2.getpavarde()) <= 0)
            return true;

        else
            return false;
    }
    if (data1.getvardas().compare(data2.getvardas()) < 0)
        return true;

    else
        return false;

}
bool rasti_vargsiukus(duomenys studentas)
{
    return (studentas.getvidurkis() < 5);
}

