#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "Studentas.h"

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::string;
using std::vector;

void failu_sukurimas_test(string file_name, int size);
void nuskaitymo_test_vec(string file_name, vector<studentas>& duom_sar);
void grouping_test_vec_1strategija(vector <studentas>& vargsiukai, vector <studentas>& stud_sar);
void grouping_test_list_1_strategija(list <studentas>& vargsiukai, list <studentas>& stud_sar);
void grouping_test_vec_2_strategija(vector <studentas>& vargsiukai, vector <studentas>& stud_sar);
void grouping_test_list_2_strategija(list <studentas>& vargsiukai, list <studentas>& stud_sar);
void grouping_test_vec_3strategija(vector <studentas>& vargsiukai, vector <studentas>& stud_sar);
void isvedimas_i_failus_test(vector <studentas>& vargsiukai, vector <studentas>& stud_sar);
void strategiju_testavimas(string file_name, string data_gen_choice, int size);
void list_ir_vector_testavimas(string file_name, string data_gen_choice, int size);
void vector_testavimas(string file_name, string data_gen_choice, int size);

