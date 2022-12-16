#pragma once
#include <random>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <chrono>
#include <list>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::fixed;
using std::ifstream;
using std::getline;
using std::ofstream;
using std::stringstream;
using std::to_string;
using std::list;
using std::remove_if;

studentas ivedimas();
void read_and_fill_vector(vector<studentas>& data, string file_name);
void read_and_fill_list(list <studentas>& data, string file_name);
void random_data_gen(int sar_size, stringstream& buffer);
void fill_buffer(list<studentas> data, stringstream& buffer);
void fill_buffervec(vector<studentas> data, stringstream& buffer);
void write_to_file(list<studentas>& data, string result_file);
void write_to_filevec(vector<studentas>& data, string result_file);
vector<studentas> grouping_by_vec_1_strategija(vector<studentas>& visi);
list <studentas> grouping_by_list_1_strategija(list<studentas>& visi);
vector<studentas> grouping_by_vec_2_strategija(vector<studentas>& visi);
list <studentas> grouping_by_list_2_strategija(list<studentas>& visi);
vector<studentas> grouping_by_vec_3_strategija(vector<studentas>& visi);
list<studentas> grouping_by_list_3_strategija(list<studentas>& visi);
void failu_sukurimas(string file_name, int file_size);
void isvedimas_i_ekrana(vector <studentas>& st_sar, string txt);
