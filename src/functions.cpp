#include "Studentas.h"
#include "functions.h"
#include "in_out.h"

/**
* Atsitiktiniu pazymiu generavimas
* @param asmuo kintamasis, kuriame saugoma informacija apie studenta
* @param random_sk kintamajame saugoma inforamcija, kiek skirtingu namu darbu rezultatu norima sukurti
*/

void random_paz_generavimas(studentas& asmuo, int random_sk)
{
    vector <int> nd;
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int> (hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(0, 10);
    for (int i = 0; i < random_sk; i++)
    {
        nd.push_back(dist(mt));
    }
    asmuo.setnd(nd);
    asmuo.setegzaminas(dist(mt));
}

/**
* Namu darbu skaiciaus ieskojimas faile
* @param open_f naudojamas failo pirmos eilutes nuskaitymui
* @return grazina suskaiciuotu namu darbu skaiciu
*/

int get_nd_count(ifstream& open_f)
{
    string temp, word;
    temp = read_line(open_f);
    stringstream ss(temp);
    int count = 0;
    while (ss >> word)
    {
        if (word.find("ND") != string::npos)
            count++;
    }
    return count;
}

/**
* String tipo kintamojo visu raidziu sumazinimas
* @param input yra kintamasis, kuriame saugoma zodzio raides bus norima sumazinti
* @return grazina sumazinta string tipo kintamajame saugoma informacija
*/

string to_lower(string input)
{
    string choice = "";
    for (int i = 0; i < input.length(); i++)
    {
        choice.push_back(tolower(input[i]));
    }
    return choice;
}

/**
* Patikrinimas, ar kintamajame yra skaiciu
* @param str saugomas string tipo kintamojo informacija - paduotas zodis, kuriame bus tikrinama ar yra skaiciu
* @return grazina false arba true priklausomai nuo to ar rado skaiciu zodyje
*/

bool ar_skaicius(string str)
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == 0)
            return false;
    return true;
}

/**
* Patikrinimas, ar string tipo kintamajame saugomos tik raides
* @param str saugomas string tipo kintamojo informacija - paduotas zodis, kuriame bus tikrinama ar ji sudaro tik raides
* @return grazina true arba false priklausomai nuo to ar kintamajame buvo saugomos tik raides
*/

bool ar_raide(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
        if (isalpha(s[i]) != 0)
            count++;

    if (count == s.length())
        return false;

    return true;
}

/**
* Failo tikrinimas
* @param eil_isskaidyta kintamajame saugoma nuo failo nuskaityta eilute
* @return griztama, jei nebuvo rasta klaidu
*/

void tikrinti_failo_vidu(string eil_isskaidyta)
{
    string msg = "Neteisingai ivesti studentas faile ";
    try
    {
        if (ar_skaicius(eil_isskaidyta) == false)
        {
            throw msg;
        }
        else
            return;
    }
    catch (string msg)
    {
        cout << msg;
        exit(0);
    }
}

/**
* Failo pavadinimo ivedinimas ir jo patikrinimas
* @param file_name saugo failo pavadinima
*/

void ivesti_ir_tikrinti_failo_pav(string& file_name)
{
    ifstream open_f;
    open_f.exceptions(ifstream::failbit | ifstream::badbit);

    try
    {
        cout << "Iveskite failo pavadinima ";
        cin >> file_name;
        open_f.open(file_name);
    }
    catch (const ifstream::failure& e)
    {
        cout << "Neatidare failo. Klaida: " << e.what() << endl;
        exit(0);
    }
    open_f.close();
}

/**
* Tikrinamos galimos failo klaidos
* @param file_name kintamajame saugomas failo pavadinimas
*/

void tikrinti_failo_pav(string file_name)
{
    ifstream open_f;
    open_f.exceptions(ifstream::failbit | ifstream::badbit);
    try
    {
        open_f.open(file_name);
    }
    catch (const ifstream::failure& e)
    {
        cout << "Neatidare failo. Klaida: " << e.what() << endl;
        exit(0);
    }
    open_f.close();
}
/**
* Tikrinima ivestis
* @param ats string tipo kintamasis, kuriame bus saugomas tam tikras ivestas zodis
* @param var_1 kintamajame saugomas vienas is zodziu, su kuriuo tures sutapti vartotojo ivestas zodis
* @param var_2 kintamajame saugomas vienas is zodziu, su kuriuo tures sutapti vartotojo ivestas zodis
* @return grazina pasirinkta vartotojo varianta
*/
string tikrinti_ivesti(string ats, const string var_1, const string var_2)
{
    string maz_raid;
    string msg = "Ivedete neteisingai! Iveskite tik ";
    while (true)
    {
        try
        {
            if (to_lower(ats).compare(var_1) == 0 || to_lower(ats).compare(var_2) == 0)
            {
                maz_raid = to_lower(ats);
                return maz_raid;
            }
            else
            {
                cin.clear();
                throw msg;
            }
        }
        catch (string msg)
        {
            cout << msg << var_1 << " arba " << var_2 << endl;
            cin >> ats;
        }
    }
}
/**
* Tikrinima vartotojo string tipo ivestis
* @param input saugoma vartotojo ivestis

*/
void tikrinti_str(string& input)
{
    bool tikrinti;
    string msg = "Pasitikrinkite savo ivesta atsakyma!";
    while (true)
    {
        try
        {
            if (input == "0")
                break;
            tikrinti = ar_raide(input);
            if (tikrinti == true)
            {
                cin.clear();
                throw msg;
            }
            if (tikrinti == false)
                break;
        }
        catch (string msg)
        {
            cout << msg << endl;
            cin >> input;
        }
    }
}
/**
* Tikrinima int tipo ivestis
* @param input kintamajame saugomas vartotojo pasirinkimas
*/

void tikrinti_int(int& input)
{
    string msg = "Pasitikrinkite savo ivesta atsakyma!";
    while (true)
    {
        try
        {
            if (cin.fail() || input < 0)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw msg;
            }
            if (!cin.fail())
                break;
        }
        catch (string msg)
        {
            cout << msg << endl;
            cin >> input;
        }
    }
}
