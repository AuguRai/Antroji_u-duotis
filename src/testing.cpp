#include "testing.h";
#include "Studentas.h"
#include "in_out.h"
#include "functions.h"
/**
* Failu sukurimo greicio testavimas
* @param file_name failo pavadinimas
* @param size failo dydis
*/
void failu_sukurimas_test(string file_name, int size)
{
    auto start = std::chrono::high_resolution_clock::now();
    failu_sukurimas(file_name, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo sukurimas truko: " << diff.count() << endl;
}
/**
* Failu nuskaitymo su vektoriumi greicio testavimas
* @param file_name failo pavadinimas
* @param duom_sar vector tipo kintamajame saugomi duomenys apie studentus
*/
void nuskaitymo_test_vec(string file_name, vector<studentas>& duom_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    read_and_fill_vector(duom_sar, file_name);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo nuskaitymas truko: " << diff.count() << endl;
}
/**
* Failu nuskaitymo su list greicio testavimas
* @param file_name failo pavadinimas
* @param duom_sar list tipo kintamajame saugomi duomenys apie studentus
*/
void nuskaitymo_test_list(string file_name, list<studentas>& duom_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    read_and_fill_list(duom_sar, file_name);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo nuskaitymas truko: " << diff.count() << endl;
}
/**
* Duomenu grupavimas pagal pirma strategija su vektoriumi
* @param vargsiukai sugrupavus saugomi duomenys apie studentus "vargsiukus"
* @param stud_sar saugomi duomenys apie studentus, sugrupavus vektoriuje lieka "galvociai" studentai
*/
void grouping_test_vec_1strategija(vector <studentas>& vargsiukai, vector <studentas>& stud_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    vargsiukai = grouping_by_vec_1_strategija(stud_sar);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo surusiavimas pagal vector truko: " << diff.count() << endl;
}
/**
* Duomenu grupavimas pagal pirma strategija su list
* @param vargsiukai sugrupavus saugomi duomenys apie studentus "vargsiukus"
* @param stud_sar saugomi duomenys apie studentus, sugrupavus list'e lieka "galvociai" studentai
*/
void grouping_test_list_1_strategija(list <studentas>& vargsiukai, list <studentas>& stud_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    vargsiukai = grouping_by_list_1_strategija(stud_sar);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo surusiavimas pagal list truko: " << diff.count() << endl;
}
/**
* Duomenu grupavimas pagal antra strategija su vektoriumi
* @param vargsiukai sugrupavus saugomi duomenys apie studentus "vargsiukus"
* @param stud_sar saugomi duomenys apie studentus, sugrupavus vektoriuje lieka "galvociai" studentai
*/
void grouping_test_vec_2_strategija(vector <studentas>& vargsiukai, vector <studentas>& stud_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    vargsiukai = grouping_by_vec_2_strategija(stud_sar);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo surusiavimas pagal vector truko: " << diff.count() << endl;
}
/**
* Duomenu grupavimas antra pirma strategija su list
* @param vargsiukai sugrupavus saugomi duomenys apie studentus "vargsiukus"
* @param stud_sar saugomi duomenys apie studentus, sugrupavus list'e lieka "galvociai" studentai
*/
void grouping_test_list_2_strategija(list <studentas>& vargsiukai, list <studentas>& stud_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    vargsiukai = grouping_by_list_2_strategija(stud_sar);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo surusiavimas pagal list truko: " << diff.count() << endl;
}
/**
* Duomenu grupavimas pagal trecia strategija su vektoriumi
* @param vargsiukai sugrupavus saugomi duomenys apie studentus "vargsiukus"
* @param stud_sar saugomi duomenys apie studentus, sugrupavus vektoriuje lieka "galvociai" studentai
*/
void grouping_test_vec_3strategija(vector <studentas>& vargsiukai, vector <studentas>& stud_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    vargsiukai = grouping_by_vec_3_strategija(stud_sar);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo surusiavimas pagal vector truko: " << diff.count() << endl;
}
/**
* Duomenu isvedimo i failus greicio testavimas
* @param vargsiukai saugomi duomenys apie studentus "vargsiukus"
* @param stud_sar saugomi duomenys apie studentus "galvocius"
*/

void isvedimas_i_failus_test(vector <studentas>& vargsiukai, vector <studentas>& stud_sar)
{
    int size = stud_sar.size() + vargsiukai.size();
    auto start = std::chrono::high_resolution_clock::now();
    write_to_filevec(stud_sar, "Galvociai" + std::to_string(size) + ".txt");
    write_to_filevec(vargsiukai, "Vargsiukai" + std::to_string(size) + ".txt");
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Isvedimas i 2 naujus failus truko: " << diff.count() << endl;
}
/**
* Vykdomas visu strategiju testavimas
* @param file_name saugo failo pavadinima
* @param data_gen_choice saugo vartotojo pasirinkima (ar jis nori, kad duomenys butu generuojami)
* @param size saugo norimo sukurti failo dydi
*/
void strategiju_testavimas(string file_name, string data_gen_choice, int size)
{
    cout << size << "duomenu: " << endl;
    vector <studentas> stud_sar, vargsiukai, tempstud_sar;
    list <studentas> list_stud_sar, list_vargsiukai, temp_list_stud_sar;


    if (data_gen_choice == "t")
        failu_sukurimas(file_name, size);

    read_and_fill_list(list_stud_sar, file_name);
    read_and_fill_vector(stud_sar, file_name);

    cout << "1 strategija: " << endl;
    temp_list_stud_sar = list_stud_sar;
    grouping_test_list_1_strategija(list_vargsiukai, temp_list_stud_sar);
    list_vargsiukai.clear(); temp_list_stud_sar.clear();

    tempstud_sar = stud_sar;

    grouping_test_vec_1strategija(vargsiukai, tempstud_sar);
    vargsiukai.clear(); tempstud_sar.clear();

    cout << endl;

    cout << "2 strategija: " << endl;
    temp_list_stud_sar = list_stud_sar;
    grouping_test_list_2_strategija(list_vargsiukai, temp_list_stud_sar);
    list_vargsiukai.clear(); temp_list_stud_sar.clear();

    tempstud_sar = stud_sar;
    grouping_test_vec_2_strategija(vargsiukai, tempstud_sar);
    vargsiukai.clear(); tempstud_sar.clear();

    cout << endl;

    cout << "3 strategija: " << endl;
    grouping_test_vec_3strategija(vargsiukai, stud_sar);
    write_to_filevec(stud_sar, "Galvociai" + std::to_string(size) + ".txt");
    stud_sar.clear();
    write_to_filevec(vargsiukai, "Vargsiukai" + std::to_string(size) + ".txt");
    vargsiukai.clear();
    cout << endl;
}
/**
* Vykdomas list ir vector greiciu palyginimas pagal nuskaityma ir grupavima
* @param file_name saugo failo pavadinima
* @param data_gen_choice saugo vartotojo pasirinkima (ar jis nori, kad duomenys butu generuojami)
* @param size saugo norimo sukurti failo dydi
*/
void list_ir_vector_testavimas(string file_name, string data_gen_choice, int size)
{
    cout << size << "duomenu: " << endl;
    vector <studentas> stud_sar, vargsiukai;
    list <studentas> list_stud_sar, list_vargsiukai;

    if (data_gen_choice == "t")
        failu_sukurimas(file_name, size);

    cout << "Su list: " << endl;
    nuskaitymo_test_list(file_name, list_stud_sar);
    grouping_test_list_1_strategija(list_vargsiukai, list_stud_sar);
    list_stud_sar.clear();
    list_vargsiukai.clear();
    cout << endl;

    cout << "Su vektorium: " << endl;
    nuskaitymo_test_vec(file_name, stud_sar);
    grouping_test_vec_1strategija(vargsiukai, stud_sar);
    cout << endl;

    write_to_filevec(stud_sar, "Galvociai" + std::to_string(size) + ".txt");
    write_to_filevec(vargsiukai, "Vargsiukai" + std::to_string(size) + ".txt");
}
/**
* Vykdomas testavimas pagal failu sukurima, nuskaityma, grupavima, isvedima i faila
* @param file_name saugo failo pavadinima
* @param data_gen_choice saugo vartotojo pasirinkima (ar jis nori, kad duomenys butu generuojami)
* @param size saugo norimo sukurti failo dydi
*/
void vector_testavimas(string file_name, string data_gen_choice, int size)
{
    cout << size << "duomenu: " << endl;
    vector <studentas> stud_sar, vargsiukai;

    if (data_gen_choice == "t")
        failu_sukurimas_test(file_name, size);

    nuskaitymo_test_vec(file_name, stud_sar);
    grouping_test_vec_1strategija(vargsiukai, stud_sar);
    isvedimas_i_failus_test(vargsiukai, stud_sar);
    cout << endl;
}



