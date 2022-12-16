#include "Studentas.h"
#include "in_out.h"
#include "functions.h"
#include "testing.h"

int main()
{
	string ats1;
	vector <studentas> stud_sar;
	cout << "Ar norite, kad programos veikimas butu testuojamas? Jei taip - iveskite t, jei ne - n ";
	cin >> ats1;
	ats1 = tikrinti_ivesti(ats1, "t", "n");
	if (ats1 == "t")
	{
		string file1 = "Kursiokai1000.txt";
		string file2 = "Kursiokai10000.txt";
		string file3 = "Kursiokai100000.txt";
		string file4 = "Kursiokai1000000.txt";
		string file5 = "Kursiokai10000000.txt";

		string ats3, ats4, ats5, ats6;
		cout << "Ar norite, kad butu sukuriami 5 atsitiktinai sugeneruoti failai? Jei taip, iveskite t, jei ne - n ";
		cin >> ats3;
		ats3 = tikrinti_ivesti(ats3, "t", "n");

		if (ats3 == "n")
		{
			tikrinti_failo_pav(file1);
			tikrinti_failo_pav(file2);
			//tikrinti_failo_pav(file3);
			//tikrinti_failo_pav(file4);
			//tikrinti_failo_pav(file5);
		}

		cout << "Ar norite, kad programa butu testuojama pagal strategijas (zr. i aprasyma)? Jei taip - parasykite t, jei ne - n. ";
		cin >> ats4;
		ats4 = tikrinti_ivesti(ats4, "t", "n");
		if (ats4 == "t")
		{
			strategiju_testavimas(file1, ats3, 1000);
			strategiju_testavimas(file2, ats3, 10000);
			//strategiju_testavimas(file3, ats3, 100000);
			//strategiju_testavimas(file4, ats3, 1000000);
			//strategiju_testavimas(file5, ats3, 10000000);
		}

		if (ats4 == "n")
		{
			cout << "Ar norite, kad list ir vector tipo konteineriai butu palyginti pagal grupavima? Jei ne, iveskite n, jei norite, jei taip - t ";
			cin >> ats5;
			ats5 = tikrinti_ivesti(ats5, "t", "n");
			if (ats5 == "t")
			{
				list_ir_vector_testavimas(file1, ats3, 1000);
				list_ir_vector_testavimas(file2, ats3, 10000);
				//list_ir_vector_testavimas(file3, ats3, 100000);
				//list_ir_vector_testavimas(file4, ats3, 1000000);
				//list_ir_vector_testavimas(file5, ats3, 10000000);
			}
			if (ats5 == "n")
			{
				cout << "Ar norite, kad butu testuojamas tik list grupavimo greitis pagal 2 strategija? Jei norite, iveskite t, jei ne - n. ";
				cin >> ats6;;
				ats6 = tikrinti_ivesti(ats6, "t", "n");
				if (ats6 == "t")
				{
					if (ats3 == "t")
					{
						failu_sukurimas(file3, 100000);
						failu_sukurimas(file4, 1000000);
					}
					cout << "100000 duomenu: " << endl;
					list <studentas> vargsiukai, stud_sar_list;
					read_and_fill_list(stud_sar_list, file3);
					grouping_test_list_2_strategija(vargsiukai, stud_sar_list);
					write_to_file(vargsiukai, "Vargsiukai100000.txt");
					write_to_file(stud_sar_list, "Galvociai100000.txt");
					vargsiukai.clear();
					stud_sar_list.clear();
					cout << "1000000 duomenu: " << endl;
					read_and_fill_list(stud_sar_list, file4);
					grouping_test_list_2_strategija(vargsiukai, stud_sar_list);
					write_to_file(vargsiukai, "Vargsiukai1000000.txt");
					write_to_file(stud_sar_list, "Galvociai1000000.txt");

				}
				else
				{
					vector_testavimas(file1, ats3, 1000);
					vector_testavimas(file2, ats3, 10000);
					//vector_testavimas(file3, ats3, 100000);
					//vector_testavimas(file4, ats3, 1000000);
					//vector_testavimas(file5, ats3, 10000000);
				}
			}
		}
	}
	else
	{
		string ats2;
		cout << "Ar norite ivesti duomenis, ar juos nuskaityti is failo? Jei nuskaityti - iveskite n, jei ivesti - iveskite i " << endl;
		cin >> ats2;
		ats2 = tikrinti_ivesti(ats2, "i", "n");
		if (to_lower(ats2) == "n")
		{
			string file_name = "";
			ivesti_ir_tikrinti_failo_pav(file_name);
			read_and_fill_vector(stud_sar, file_name);
			sort(stud_sar.begin(), stud_sar.end(), compareAscending);
			write_to_filevec(stud_sar, "Rezultatai.txt");
		}
		if (to_lower(ats2) == "i")
		{
			int st_sk = 0;
			string txt, galut_choice;
			while (true)
			{
				stud_sar.push_back(ivedimas());
				if (stud_sar[st_sk].getvardas() == "0")
				{
					stud_sar.erase(stud_sar.begin() + st_sk);
					break;
				}
				st_sk++;
			}
			if (st_sk != 0)
			{
				cout << "Pasirinkite, koki galutini rezultata norite suzinoti. Iveskite mediana arba vidurkis " << endl;
				while (true)
				{
					cin >> galut_choice;
					if (to_lower(galut_choice) == "mediana" || to_lower(galut_choice) == "vidurkis")
						break;
					else
						cout << "Ivedete neteisingai! Iveskite tik 'mediana' arba 'vidurkis'" << endl;
				}
				if (to_lower(galut_choice) == "vidurkis")
				{
					txt = "vidurkis";
					for (int i = 0; i < stud_sar.size(); i++)
						stud_sar[i].vidurkis();
				}
				if (to_lower(galut_choice) == "mediana")
				{
					txt = "mediana";
					for (int i = 0; i < stud_sar.size(); i++)
						stud_sar[i].mediana();
				}
				isvedimas_i_ekrana(stud_sar, txt);
			}
			else
				cout << "Programos pabaiga" << endl;
		}
	}
	return 0;
}