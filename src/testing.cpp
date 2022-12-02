#include "testing.h";
#include "Studentas.h"
#include "in_out.h"
#include "functions.h"

void failu_sukurimas_test(string file_name, int size)
{
    auto start = std::chrono::high_resolution_clock::now();
    failu_sukurimas(file_name, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo sukurimas truko: " << diff.count() << endl;
}

void nuskaitymo_test_vec(string file_name, vector<duomenys>& duom_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    read_and_fill_vector(duom_sar, file_name);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo nuskaitymas truko: " << diff.count() << endl;
}

void nuskaitymo_test_list(string file_name, list<duomenys>& duom_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    read_and_fill_list(duom_sar, file_name);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo nuskaitymas truko: " << diff.count() << endl;
}

void grouping_test_vec_1strategija(vector <duomenys>& vargsiukai, vector <duomenys>& stud_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    vargsiukai = grouping_by_vec_1_strategija(stud_sar);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo surusiavimas pagal vector truko: " << diff.count() << endl;
}

void grouping_test_list_1_strategija(list <duomenys>& vargsiukai, list <duomenys>& stud_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    vargsiukai = grouping_by_list_1_strategija(stud_sar);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo surusiavimas pagal list truko: " << diff.count() << endl;
}

void grouping_test_vec_2_strategija(vector <duomenys>& vargsiukai, vector <duomenys>& stud_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    vargsiukai = grouping_by_vec_2_strategija(stud_sar);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo surusiavimas pagal vector truko: " << diff.count() << endl;
}

void grouping_test_list_2_strategija(list <duomenys>& vargsiukai, list <duomenys>& stud_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    vargsiukai = grouping_by_list_2_strategija(stud_sar);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo surusiavimas pagal list truko: " << diff.count() << endl;
}

void grouping_test_vec_3strategija(vector <duomenys>& vargsiukai, vector <duomenys>& stud_sar)
{
    auto start = std::chrono::high_resolution_clock::now();
    vargsiukai = grouping_by_vec_3_strategija(stud_sar);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo surusiavimas pagal vector truko: " << diff.count() << endl;
}

void isvedimas_i_failus_test(vector <duomenys>& vargsiukai, vector <duomenys>& stud_sar)
{
    int size = stud_sar.size() + vargsiukai.size();
    auto start = std::chrono::high_resolution_clock::now();
    write_to_filevec(stud_sar, "Galvociai" + std::to_string(size) + ".txt");
    write_to_filevec(vargsiukai, "Vargsiukai" + std::to_string(size) + ".txt");
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Isvedimas i 2 naujus failus truko: " << diff.count() << endl;
}

void strategiju_testavimas(string file_name, string data_gen_choice, int size)
{
    cout << size << "duomenu: " << endl;
    vector <duomenys> stud_sar, vargsiukai, tempstud_sar;
    list <duomenys> list_stud_sar, list_vargsiukai, temp_list_stud_sar;


    if (data_gen_choice == "t")
        failu_sukurimas(file_name, size);

    read_and_fill_list(list_stud_sar, file_name);
    read_and_fill_vector(stud_sar, file_name);

    cout << endl;

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

void list_ir_vector_testavimas(string file_name, string data_gen_choice, int size)
{
    cout << size << "duomenu: " << endl;
    vector <duomenys> stud_sar, vargsiukai;
    list <duomenys> list_stud_sar, list_vargsiukai;

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

void vector_testavimas(string file_name, string data_gen_choice, int size)
{
    cout << size << "duomenu: " << endl;
    vector <duomenys> stud_sar, vargsiukai;

    if (data_gen_choice == "t")
        failu_sukurimas_test(file_name, size);

    nuskaitymo_test_vec(file_name, stud_sar);
    grouping_test_vec_1strategija(vargsiukai, stud_sar);
    isvedimas_i_failus_test(vargsiukai, stud_sar);
    cout << endl;
}



