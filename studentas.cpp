#include "Studentas.h"


zmogus::zmogus(string vardas, string pavarde)
{
    vardas_ = vardas;
    pavarde_ = pavarde;
}

void zmogus::setvardas(string vardas)
{
    this->vardas_ = vardas;
}

void zmogus::setpavarde(string pavarde)
{
    this->pavarde_ = pavarde;
}

string const studentas::getvardas() const
{
    return vardas_;
}

string const studentas::getpavarde() const
{
    return pavarde_;
}

studentas::studentas(string vardas, string pavarde, vector<int> nd, int egzaminas)
{
    vardas_ = vardas;
    pavarde_ = pavarde;
    nd_rez_ = nd;
    egz_rez_ = egzaminas;
}
studentas::studentas(const studentas& studentas)
{
    vardas_ = studentas.vardas_;
    pavarde_ = studentas.pavarde_;
    nd_rez_ = studentas.nd_rez_;
    egz_rez_ = studentas.egz_rez_;
    vidurkis_ = studentas.vidurkis_;
    mediana_ = studentas.mediana_;
}

studentas& studentas::operator =(const studentas& studentas)
{
    if (&studentas == this)
    {
        return *this;
    }

    vardas_ = studentas.vardas_;
    pavarde_ = studentas.pavarde_;
    nd_rez_ = studentas.nd_rez_;
    egz_rez_ = studentas.egz_rez_;
    mediana_ = studentas.mediana_;
    vidurkis_ = studentas.vidurkis_;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const studentas& st) 
{
    out << st.vardas_ << " " << st.pavarde_ << " ";
    for (int k : st.nd_rez_) 
    {
        out << k << ' ';
    }
    out << st.egz_rez_ << endl;
    return out;
}

std::istream& operator>>(std::istream& in, studentas& st) 
{
    int nd_sk, nd;
    in >> st.vardas_ >> st.pavarde_ >> nd_sk;
    for (int i = 0; i < nd_sk; i++)
    {
        in >> nd;
        st.nd_rez_.push_back(nd);
    }
    in >> st.egz_rez_;
    return in;
}

studentas::~studentas()
{
    this->nd_rez_.clear();
}

void studentas::setnd(vector <int> nd)
{
    this->nd_rez_ = nd;
}
vector <int> studentas::getnd() const
{
    return nd_rez_;
}
void studentas::setegzaminas(int egzaminas)
{
    this->egz_rez_ = egzaminas;
}

int studentas::getegzaminas() const
{
    return egz_rez_;
}

void studentas::vidurkis()
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

double studentas::getvidurkis() const
{
    return vidurkis_;
}

void studentas::mediana()
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

double studentas::getmediana() const
{
    return mediana_;
}

void studentas::read_and_calc(ifstream& open_f, int nd_count)
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

bool compareByMean(studentas& data1, studentas& data2)
{
    return data1.getvidurkis() < data2.getvidurkis();
}

bool compareAscending(studentas& data1, studentas& data2)
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
bool rasti_vargsiukus(studentas studentas)
{
    return (studentas.getvidurkis() < 5);
}

