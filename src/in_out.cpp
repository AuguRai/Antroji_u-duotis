#include "Studentas.h"
#include "in_out.h"
#include "functions.h"

/**
* Vykdomas vartotojo duomenu ivedimas
* @return grazinama gauta informacija apie studenta
*/

studentas ivedimas()
{
    studentas asmuo;
    string pavarde, vardas;
    vector <int> nd_rez;
    nd_rez.reserve(1000);
    int nd_rezultatai = 0;
    int random_sk;
    string choice;
    cout << "Parasykite varda (iveskite 0, jei norite baigti ivedima): ";
    cin >> vardas;
    tikrinti_str(vardas);
    asmuo.setvardas(vardas);

    if (asmuo.getvardas() == "0")
        return asmuo;

    cout << "Parasykite pavarde: ";
    cin >> pavarde;
    tikrinti_str(pavarde);
    asmuo.setpavarde(pavarde);
    cout << "Ar norite, kad namu darbu rezultatai butu ivedami uz jus atsitiktinai?(Jei taip, iveskite t, jei ne - n) ";
    cin >> choice;
    const string t = "t"; const string n = "n";
    string pasirinkimas = tikrinti_ivesti(choice, t, n);

    if (pasirinkimas == "t")
    {
        cout << "Kiek atsitiktiniu namu darbu rezultatu norite, kad butu sukurta? ";
        cin >> random_sk;
        tikrinti_int(random_sk);
        random_paz_generavimas(asmuo, random_sk);
    }

    if (pasirinkimas == "n")
    {
        cout << "Atskirdami su enter parasykite namu darbu rezultatus (noredami uzbaigti namu darbu rez. ivedima, irasykite 0) " << endl;
        while (true)
        {
            if (pasirinkimas == "n")
            {
                cin >> nd_rezultatai;
                tikrinti_int(nd_rezultatai);
                if (nd_rezultatai == 0)
                    break;
            }
            if (nd_rezultatai >= 1 && nd_rezultatai <= 10)
            {
                nd_rez.push_back(nd_rezultatai);
            }
            else
                cout << "Balas turi buti desimtbaleje sistemoje! Iveskite is naujo" << endl;
            asmuo.setnd(nd_rez);
            nd_rez.clear();
        }
        cout << "Parasykite egzamino rezultata: ";
        while (true)
        {
            int egz_rez;
            cin >> egz_rez;
            if (egz_rez >= 1 && egz_rez <= 10)
            {
                tikrinti_int(egz_rez);
                break;
            }
            else
                cout << "Balas turi buti desimtbaleje sistemoje! Iveskite is naujo" << endl;
            asmuo.setegzaminas(egz_rez);
        }
    }
    asmuo.getnd().shrink_to_fit();
    return asmuo;
}
/**
* Vektoriaus uzpildymas duomenis nuskaitant nuo failo
* @param data saugo nuskaityta informacija apie studentus
* @param file_name saugo failo pavadinima
*/
void read_and_fill_vector(vector<studentas>& data, string file_name)
{
    ifstream open_f;
    open_f.open(file_name);
    int nd_count = 0;
    nd_count = get_nd_count(open_f);
    while (open_f)
    {
        if (!open_f.eof())
        {
            studentas temp_data;
            temp_data.read_and_calc(open_f, nd_count);
            data.push_back(temp_data);
            temp_data.getnd().clear();
        }
        else
            break;
    }
    open_f.close();
}
/**
* List uzpildymas duomenis nuskaitant nuo failo
* @param data saugo nuskaityta informacija apie studentus
* @param file_name saugo failo pavadinima
*/

void read_and_fill_list(list <studentas>& data, string file_name)
{
    ifstream open_f;
    open_f.open(file_name);
    int nd_count = 0;
    nd_count = get_nd_count(open_f);
    while (open_f)
    {
        if (!open_f.eof())
        {
            studentas temp_data;
            temp_data.read_and_calc(open_f, nd_count);
            data.push_back(temp_data);
            temp_data.getnd().clear();
        }
        else
            break;
    }
    open_f.close();
}
/**
* Atsitiktiniu duomenu sukurimas
* @param sar_size saugo informacija, kiek atsitiktiniu duomenu bus norima sukurti
* @param buffer skirtas uzpildyti visus sukurtus atsitiktinius duomenis
*/
void random_data_gen(int sar_size, stringstream& buffer)
{
    studentas rand_student;

    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int> (hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(4, 8);

    
    int nd_sk = 5;

    buffer << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
    for (int idx = 0; idx < nd_sk; idx++)
        buffer << std::setw(10) << "ND" + to_string(idx + 1);

    buffer << std::setw(10) << "Egzaminas" << endl;

    for (int idx = 0; idx < sar_size; idx++)
    {
        buffer << std::left << std::setw(20) << "Vardas" + to_string(idx + 1) << std::setw(20) << "Pavarde" + to_string(idx + 1);
        random_paz_generavimas(rand_student, nd_sk);

        for (int i = 0; i < nd_sk; i++)
        {
            buffer << std::setw(10) << rand_student.getnd()[i];
        }

        buffer << std::setw(10) << rand_student.getegzaminas();
        if (idx < sar_size - 1)
            buffer << endl;
        rand_student.getnd().clear();
    }
}
/**
* Irasymas i faila
* @param buffer kintamasis saugo visa informacija, kuri bus irasoma i faila
* @param pavadinimas kintmasis saugo failo pavadinima
*/
void write_buffer(stringstream& buffer, string pavadinimas)
{
    ofstream out_f(pavadinimas);
    out_f << buffer.str();
    out_f.close();
}
/**
* Duomenu uzpildymas stringstream tipo kintamajame nuo list
* @param data list'e saugo informacija apie studentus
* @param buffer kintamajame uzpildomi duomenys
*/
void fill_buffer(list<studentas> data, stringstream& buffer)
{
    buffer << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << endl;
    buffer << "-----------------------------------------------------------------------" << endl;
    for (studentas& entry : data)
        buffer << std::left << std::setw(20) << entry.getvardas() << std::setw(20) << entry.getpavarde() << std::setw(20) << fixed << setprecision(2) << entry.getvidurkis() << std::setw(20) << entry.getmediana() << endl;
}
/**
* Vyksta list duomenu isvedimas i faila
* @param data saugo informacija apie studentus
* @param result_file saugo failo pavadinima
*/
void write_to_file(list<studentas>& data, string result_file)
{
    stringstream out_buff;
    fill_buffer(data, out_buff);
    data.clear();
    write_buffer(out_buff, result_file);
    out_buff.str("");
}
/**
* Duomenu uzpildymas stringstream tipo kintamajame nuo vector
* @param data saugo informacija apie studentus
* @param buffer kintamajame uzpildomi duomenys
*/
void fill_buffervec(vector<studentas> data, stringstream& buffer)
{
    buffer << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << endl;
    buffer << "-----------------------------------------------------------------------" << endl;
    for (studentas& entry : data)
        buffer << std::left << std::setw(20) << entry.getvardas() << std::setw(20) << entry.getpavarde() << std::setw(20) << fixed << setprecision(2) << entry.getvidurkis() << std::setw(20) << entry.getmediana() << endl;
}
/**
* Vyksta vector duomenu isvedimas i faila
* @param data saugo informacija apie studentus
* @param result_file saugo failo pavadinima
*/
void write_to_filevec(vector<studentas>& data, string result_file)
{
    stringstream out_buff;
    fill_buffervec(data, out_buff);
    data.clear();
    write_buffer(out_buff, result_file);
    out_buff.str("");
}
/**
* Vyksta vector grupavimas pagal pirma strategija
* @param visi saugo informacija apie studenta
* @return grazina rastus "vargsiukus" (studentus, gavusiuos galutini bala maziau nei 5)
*/

vector<studentas> grouping_by_vec_1_strategija(vector<studentas>& visi)
{
    vector<studentas> vargsiukai;
    vector<studentas> galvociai;

    sort(visi.begin(), visi.end(), compareByMean);

    for (auto itr = visi.begin(); itr != visi.end(); itr++)
    {
        if ((*itr).getvidurkis() < 5)
            vargsiukai.push_back(*itr);

        else
            galvociai.push_back(*itr);
    }
    visi.clear();
    visi = galvociai;

    return vargsiukai;
}
/**
* Vyksta list grupavimas pagal pirma strategija
* @param visi saugo informacija apie studenta
* @return grazina rastus "vargsiukus" (studentus, gavusiuos galutini bala maziau nei 5)
*/

list <studentas> grouping_by_list_1_strategija(list<studentas>& visi)
{
    list<studentas> vargsiukai;
    list<studentas> galvociai;

    visi.sort(compareByMean);

    for (auto itr = visi.begin(); itr != visi.end(); itr++)
    {
        if ((*itr).getvidurkis() < 5)
            vargsiukai.push_back(*itr);

        else
            galvociai.push_back(*itr);
    }
    visi.clear();
    visi = galvociai;

    return vargsiukai;
}
/**
* Vyksta vector grupavimas pagal antra strategija
* @param visi saugo informacija apie studenta
* @return grazina rastus "vargsiukus" (studentus, gavusiuos galutini bala maziau nei 5)
*/
vector<studentas> grouping_by_vec_2_strategija(vector<studentas>& visi)
{
    vector<studentas> vargsiukai;
    sort(visi.begin(), visi.end(), compareByMean);
    vector<studentas>::iterator it = visi.begin();
    while (it != visi.end())
    {
        if ((*it).getvidurkis() < 5)
        {
            vargsiukai.push_back(*it);
            it = visi.erase(it);
        }
        else
            ++it;
    }
    return vargsiukai;
}
/**
* Vyksta list grupavimas pagal antra strategija
* @param visi saugo informacija apie studenta
* @return grazina rastus "vargsiukus" (studentus, gavusiuos galutini bala maziau nei 5)
*/
list <studentas> grouping_by_list_2_strategija(list<studentas>& visi)
{
    list<studentas> vargsiukai;
    visi.sort(compareByMean);
    list<studentas>::iterator it = visi.begin();
    while (it != visi.end())
    {
        if ((*it).getvidurkis() < 5)
        {
            vargsiukai.push_back(*it);
            it = visi.erase(it);
        }
        else
            ++it;
    }
    return vargsiukai;
}
/**
* Vyksta vector grupavimas pagal trecia strategija
* @param visi saugo informacija apie studenta
* @return grazina rastus "vargsiukus" (studentus, gavusiuos galutini bala maziau nei 5)
*/
vector<studentas> grouping_by_vec_3_strategija(vector<studentas>& visi)
{
    vector <studentas> vargsiukai;
    sort(visi.begin(), visi.end(), compareByMean);

    copy_if(visi.begin(), visi.end(), back_inserter(vargsiukai), rasti_vargsiukus);
    visi.erase(remove_if(visi.begin(), visi.end(), rasti_vargsiukus), visi.end());

    return vargsiukai;
}
/**
* Vyksta list grupavimas pagal trecia strategija
* @param visi saugo informacija apie studenta
* @return grazina rastus "vargsiukus" (studentus, gavusiuos galutini bala maziau nei 5)
*/
list<studentas> grouping_by_list_3_strategija(list<studentas>& visi)
{
    list <studentas> vargsiukai;
    visi.sort(compareByMean);

    copy_if(visi.begin(), visi.end(), back_inserter(vargsiukai), rasti_vargsiukus);
    visi.erase(remove_if(visi.begin(), visi.end(), rasti_vargsiukus), visi.end());

    return vargsiukai;
}
/**
* Vyksta failu sukurimas su atsitiktiniais duomenimis
* @param file_name saugo failo pavadinima
* @param file_size saugo failo dydi
*/
void failu_sukurimas(string file_name, int file_size)
{
    stringstream buffer;
    random_data_gen(file_size, buffer);
    write_buffer(buffer, file_name);
    buffer.str("");
}
/**
* Vyksta duomenu isvedimas i ekrana
* @param st_sar saugo informacija apie studentus
* @param txt saugo vartotojo pasirinkima, pagal kuri isvedami studentu galutinio balo duomenys
*/
void isvedimas_i_ekrana(vector <studentas>& st_sar, string txt)
{
    cout << std::left << std::setw(20) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << fixed << setprecision(2) << "Galutinis " + txt << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    if (txt == "vidurkis")
    {
        for (int i = 0; i < st_sar.size(); i++)
            cout << std::left << std::setw(20) << st_sar[i].getpavarde() << std::setw(20) << st_sar[i].getvardas() << std::setw(20) << st_sar[i].getvidurkis() << endl;
    }
    if (txt == "mediana")
    {
        for (int i = 0; i < st_sar.size(); i++)
            cout << std::left << std::setw(20) << st_sar[i].getpavarde() << std::setw(20) << st_sar[i].getvardas() << std::setw(20) << st_sar[i].getmediana() << endl;
    }
}
