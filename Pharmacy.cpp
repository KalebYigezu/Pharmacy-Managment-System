#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct S
{
	string name, line;
	int itemno, quantity, date, month, year;
	float price;
}s;

void intro()
{
	cout << endl << endl << endl << endl;
	cout << "\t\t\t\t\t*-----------------------------------------------------------------*" << endl;
	cout << "\t\t\t\t\t|                         K A L E B                               |" << endl;
	cout << "\t\t\t\t\t|                      P H A R M A C Y                            |" << endl;
	cout << "\t\t\t\t\t|                    M A N A G E M E N T                          |" << endl;
	cout << "\t\t\t\t\t|                        S Y S T E M                              |" << endl;
	cout << "\t\t\t\t\t*-----------------------------------------------------------------*" << endl << endl << endl << endl << endl << endl;
}

void mainmenu()
{
	cout << endl << endl << endl << "\t\t\t                  ------ Main Menu--------\n" << endl << endl;
	cout << "\t\t\t    1. Add Medicen  " << endl << endl;
	cout << "\t\t\t    2. View All Medicen " << endl << endl;
	cout << "\t\t\t    3. Search for a Medicen " << endl << endl;
	cout << "\t\t\t    4. Modify Medicen " << endl << endl;
	cout << "\t\t\t    5. About " << endl << endl;
	cout << "\t\t\t    6. Exit " << endl << endl;
}

void add_Medicen()
{
	ofstream wof;
	int yn;
	wof.open("pharm_sys.txt", ios::app);
	cout << "Enter the name of the Medicine = ";
	cin >> s.name;
	wof << s.name << "\t\t\t\t";
here:
	cout << "Enter item number of the Medicine = ";
	try
	{
		cin >> s.itemno;
		if (!cin)
			throw runtime_error("\t\tPlease enter only numbers for item number.");
	}
	catch (runtime_error &er)
	{
		cout << er.what();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "\t\t    You have entered character now." << endl << endl;
		system("pause");
		goto here;
	}
	wof << s.itemno << "\t\t\t\t";
yep:
	cout << "Enter the quantity of the Medicine = ";
	try
	{
		cin >> s.quantity;
		if (!cin)
			throw runtime_error("\t\tPlease enter only numbers for quantity.");
	}
	catch (runtime_error &er)
	{
		cout << er.what();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "\t\t    You have entered character now." << endl << endl;
		system("pause");
		goto yep;
	}
	wof << s.quantity << "\t\t\t\t";
kero:
	cout << "Enter the price of the Medicine = ";
	try
	{
		cin >> s.price;
		if (!cin)
			throw runtime_error("\t\tPlease enter only numbers for price.");
	}
	catch (runtime_error &er)
	{
		cout << er.what();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "\t\t    You have entered character now." << endl << endl;
		system("pause");
		goto kero;
	}
	wof << "$" << s.price << "\t\t\t\t";
	cout << "Enter the expiration date of the Medicine" << endl;
fano:
	cout << "\t Date  = ";
	try
	{
		cin >> s.date;
		if (!cin)
			throw runtime_error("\t\tPlease enter only numbers for date.");
	}
	catch (runtime_error &er)
	{
		cout << er.what();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "\t\t    You have entered character now." << endl << endl;
		system("pause");
		goto fano;
	}
ginbot:
	cout << "\t Month = ";
	try
	{
		cin >> s.month;
		if (!cin)
			throw runtime_error("\t\tPlease enter only numbers for month.");
	}
	catch (runtime_error &er)
	{
		cout << er.what();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "\t\t    You have entered character now." << endl << endl;
		system("pause");
		goto ginbot;
	}
hamle:
	cout << "\t year = ";
	try
	{
		cin >> s.year;
		if (!cin)
			throw runtime_error("\t\tPlease enter only numbers for year.");
	}
	catch (runtime_error &er)
	{
		cout << er.what();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "\t\t    You have entered character now." << endl << endl;
		system("pause");
		goto hamle;
	}
	wof << s.date << "-" << s.month << "-" << s.year << endl;
	cout << "Do you have more to add ? 1 for yes and 2 for no = "; cin >> yn;
	if (yn == 1)
	{
		system("cls");
		add_Medicen();
	}
	else
	{
		system("cls");
		mainmenu();
	}
}
void list_all_medicen()
{
	ifstream rff;
	rff.open("pharm_sys.txt");
	string line;
	while (rff.good())
	{
		getline(rff, line);
		cout << line << endl;
	}
	system("pause");
	system("cls");
	mainmenu();
}
void search_for_medicen()
{
	int ans, onetwo = 0;
	string nameofMed, line, MeditemNum;
	ifstream rff;
	rff.open("pharm_sys.txt");
kiki:
	cout << "Do you want to search by Item number or Medicen Name ? \n 1 for By Medicine Name and 2 for By Item Number ";
	try
	{
		cin >> ans;
		if (!cin)
			throw runtime_error("\t\tPlease enter only 1 or 2.");
	}
	catch (runtime_error &er)
	{
		cout << er.what();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "\t    You have entered character now." << endl << endl;
		system("pause");
		goto kiki;
	}
	if (ans == 1)
	{
		cin >> nameofMed;
		system("cls");
		cout << "Medicine Name\t\t\tQuantity\t\t\tExpiration Date\t\t\tPrice For 1\t\t\tItem Number" << endl << endl;
		while (rff.good())
		{
			getline(rff, line);
			if (line.find(nameofMed) != string::npos)
			{
				onetwo = 1;
				cout << line << endl;
			}
		}
		cout << endl << endl << endl;
		system("pause");
		system("cls");
		mainmenu();
		if (onetwo == 0)
		{
			cout << "Nothing Found" << endl;
			system("pause");
			system("cls");
			mainmenu();
		}
	}
	else if (ans == 2)
	{
		cin >> MeditemNum;
		system("cls");
		cout << "Medicine Name\t\t\tPrice for 1\t\t\tExpiration Date\t\t\tQuantity\t\t\tItem Number" << endl << endl;
		while (rff.good())
		{
			getline(rff, line);
			if (line.find(MeditemNum) != string::npos)
			{
				onetwo = 1;
				cout << line << endl;
			}
		}
		cout << endl << endl << endl;
		system("pause");
		system("cls");
		mainmenu();
		if (onetwo == 0)
		{
			cout << "Nothing Found" << endl;
			system("pause");
			system("cls");
			mainmenu();
		}
	}
	else if (ans > 2 || ans <1)
	{
		cout << "\t\tPlease enter only 1 or 2." << endl;
		cout << "You have entered a number lessthan 1 or greaterthan 2 now." << endl;
		system("pause");
		system("cls");
		cout << "\n\n\t\t    ------ SEARCH FOR A MEDICINE ------\n\n\n";
		goto kiki;
	}

}
void modify_medicen()
{
	ofstream wof;
	ifstream rff;
	wof.open("temp.txt");
	rff.open("pharm_sys.txt");
	ifstream rff2;
	rff2.open("pharm_sys.txt");
	string line, eline, name;
	cout << "Enter Medicine Name or Item Number ? " << endl;
	cin >> name;
	while (getline(rff, line))
	{
		string line2;
		string medNaem, iNum, qtt, price, expDate;
		if ((line.find(name)) == string::npos)
		{
			wof << line << endl;
			rff2 >> medNaem;
			rff2 >> iNum;
			rff2 >> qtt;
			rff2 >> price;
			rff2 >> expDate;
		}
		else if ((line.find(name)) != string::npos)
		{
			int ot;
			cout << "what do you want to change?\n";
		last:
			cout << "1 for Medicen Name\n2 for Medicin Item Number\n3 for Quantity\n4 for Price\n5 for Exp_Date ";
			try
			{
				cin >> ot;
				if (!cin)
					throw runtime_error("\t\tPlease enter only numbers between 1 to 5.");
			}
			catch (runtime_error &er)
			{
				cout << er.what();
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << "\t\t    You have entered character now." << endl << endl;
				system("pause");
				system("cls");
				cout << "\n\n\t\t    ------ MODIFY MEDICINE ------\n\n\n";
				cout << "what do you want to change ? " << endl << endl;
				goto last;
			}
			rff2 >> medNaem;
			rff2 >> iNum;
			rff2 >> qtt;
			rff2 >> price;
			rff2 >> expDate;
			if (ot == 1)
			{
				cout << "enter the new medicine name ";
				cin >> medNaem;
				wof << medNaem << "\t\t\t\t" << iNum << "\t\t\t\t" << qtt << "\t\t\t\t" << price << "\t\t\t\t" << expDate << endl;
				cout << " Medicine name modified " << endl;
				system("pause");
			}
			else if (ot == 2)
			{
				cout << "enter the new medicine item number ";
				cin >> iNum;
				wof << medNaem << "\t\t\t\t" << iNum << "\t\t\t\t" << qtt << "\t\t\t\t" << price << "\t\t\t\t" << expDate << endl;
				cout << " Medicine item number modified " << endl;
				system("pause");
			}
			else if (ot == 3)
			{
				cout << "enter the new quantity ";
				cin >> qtt;
				wof << medNaem << "\t\t\t\t" << iNum << "\t\t\t\t" << qtt << "\t\t\t\t" << price << "\t\t\t\t" << expDate << endl;
				cout << " Medicine quantity modified " << endl;
				system("pause");
			}
			else if (ot == 4)
			{
				cout << "enter the new price ";
				cin >> price;
				wof << medNaem << "\t\t\t\t" << iNum << "\t\t\t\t" << qtt << "\t\t\t\t" << "$" << price << "\t\t\t\t" << expDate << endl;
				cout << " Medicine price modified " << endl;
				system("pause");
			}
			else if (ot == 5)
			{
				string date, month, year;
				cout << "enter month"; cin >> month;
				cout << "enter date"; cin >> date;
				cout << "enter year"; cin >> year;
				expDate = date + "/" + month + "/" + year;
				wof << medNaem << "\t\t\t\t" << iNum << "\t\t\t\t" << qtt << "\t\t\t\t" << price << "\t\t\t\t" << expDate << endl;
				cout << " Medicine Expiration date modified " << endl;
				system("pause");
			}
			else if (ot > 5 || ot < 1)
			{
				cout << "\t\tPlease enter only 1 to 5." << endl;
				cout << "You have entered a number lessthan 1 or greaterthan 5 now." << endl;
				system("pause");
				system("cls");
				cout << "\n\n\t\t    ------ MODIFY MEDICINE ------\n\n\n";
				cout << "what do you want to change ? " << endl << endl;
				goto last;
			}
		}
	}

	wof.close();
	rff.close();
	rff2.close();
	remove("pharm_sys.txt");
	rename("temp.txt", "pharm_sys.txt");
	system("cls");
	mainmenu();
}

void about()
{
	cout << "\t\t This Computer Application is Created on 8/23/2018 by Kaleb Yigezu" << endl << endl;
	cout << "\t\t\t\t UNIVERSITY OF WASHINGTON BOTHELL" << endl << endl;
	system("pause");
	cin.get();
	system("cls");
	mainmenu();
}

int main()
{
	intro();
	system("pause");
	system("CLS");
	mainmenu();
	int option;
	do
	{
	label1:
		try
		{
			cin >> option;
			if (!cin)
				throw runtime_error("\t\tPlease enter only numbers between 1 to 6.");
		}
		catch (runtime_error &er)
		{
			system("cls");
			mainmenu();
			cout << er.what();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "\t\t    You have entered character now." << endl << endl;
			system("pause");
			system("cls");
			mainmenu();
			goto label1;
		}

		if (option == 1)
		{
			system("cls");
			cout << "\n\n\t\t    ------ Add Medicinnnn ------\n\n\n";
			add_Medicen();
		}
		else if (option == 2)
		{
			system("cls");
			cout << "\n\n\t\t    ------ All Medicine ------\n\n\n";
			list_all_medicen();
		}
		else if (option == 3)
		{
			system("cls");
			cout << "\n\n\t\t    ------ SEARCH FOR A MEDICINE ------\n\n\n";
			search_for_medicen();
		}
		else if (option == 4)
		{
			system("cls");
			cout << "\n\n\t\t    ------ MODIFY MEDICINE ------\n\n\n";
			modify_medicen();
		}
		else if (option == 5)
		{
			system("cls");
			cout << "\n\t\t\t\t    ------ ABOUT ------\n\n\n";
			about();
		}
		else if (option == 6)
		{
			break;
		}
		else if (option > 6 || option < 1)
		{
			cout << "\t\tPlease enter only numbers between 1 to 6. " << endl;
			cout << "\tYou have entered a number graterthan 6 or lessthan 1 now." << endl;
			system("pause");
			system("cls");
			mainmenu();
		}
	} while (option != 6);
	system("cls");
	cout << endl << "\t\t--------------------------------------------------------------------" << endl << endl;
	cout << "\t\t\t\t    THANK YOU FOR USING" << endl << endl;
	cout << "\t\t\t       KALEB PHARMACY MANAGMENT SYSTEM" << endl << endl;
	cout << "\t\t--------------------------------------------------------------------" << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	system("pause");
}

