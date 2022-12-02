#include "Studentas.h"



void duomenys::setvardas(string vardas)
{
    vardas_ = vardas;
}
void duomenys::setpavarde(string pavarde)
{
    pavarde_ = pavarde;
}
void duomenys::setnd(vector <int> nd)
{
    nd_rez_ = nd;
}
void duomenys::setegzaminas(int egzaminas)
{
    egz_rez_ = egzaminas;
}


string duomenys::getvardas()
{
    return vardas_;
}

string duomenys::getpavarde()
{
    return pavarde_;
}

int duomenys::getegzaminas()
{
    return egz_rez_;
}

vector <int> duomenys::getnd()
{
    return nd_rez_;
}

double duomenys::getvidurkis()
{
    return vidurkis_;
}

double duomenys::getmediana()
{
    return mediana_;
}

void duomenys::vidurkis()
{
    double rez = 0;
    double vid = 0;
    double galutinis = 0;

    if (nd_rez_.size() == 0)
        vidurkis_ = 0;

    for (int j = 0; j < nd_rez_.size(); j++)
        rez = rez + nd_rez_[j];


    vid = rez / nd_rez_.size();
    vidurkis_ = 0.4 * vid + 0.6 * egz_rez_;
}

void duomenys::mediana()
{
    double rez = 0;
    double med = 0;
    double galutinis = 0;

    if (nd_rez_.size() == 0)
        mediana_ = 0;

    sort(nd_rez_.begin(), nd_rez_.end());
    med = int(nd_rez_.size() / 2);

    if (nd_rez_.size() % 2 != 0)
        med = nd_rez_[med];

    else
        med = double(nd_rez_[med] + nd_rez_[med - 1]) / 2;

    mediana_ = 0.4 * med + 0.6 * egz_rez_;
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

