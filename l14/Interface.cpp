#include "stdafx.h"
#include "Interface.h"
#include "Algoritm.h"
using namespace std;

Interface::Interface()
{

}


Interface::~Interface()
{
}

int Interface::ValidateInput()
{
	while (1) {
		int n;
		if (cin >> n)
			return n;
		if (cin.eof())
			return n;
		cin.clear();
		string e;
		getline(cin, e);
		cout << "������������ ����. ����������� �����: ";
	}
}



void Interface::InterfaceMenu()
{
	int answ;
	Algoritm alg;
	int exit = 1;
	while (exit == 1) {
		cout << "------------------------------" << endl;
		cout << "������� 1, ���� ������ ������ � ����������" << endl;
		cout << "������� 2, ���� ������ ������ ����� �� �����" << endl;
		cout << "������� 3, ���� ������ ���������� �������� �������" << endl;
		cout << "������� 4 ��� ������ �� ���������" << endl;
		answ = ValidateInput();
		enum menu {
			keyboard = 1,
			file,
			test,
			exitAAA
		};
		switch (answ) {
		case (keyboard): {
			cout << "������� �������� ������ " << endl;
			string query;
			getline(cin >> ws, query);
			cin.clear();

			//vector<string> data = alg.Split(query);

			
			string countCharStr;
			int countChar = 0;

			cout << "������� ���-�� �������� " << endl;
			cin >> countCharStr;			
			istringstream iss(countCharStr);

			iss >> countChar;
			cin.clear();

			if (iss.fail()) {
				cout << "�������� ������ ������!\n";
				break;
			}
			cout << "���-�� ���� ���������� ��� ������� " << alg.GetCountWords(query, countChar) << "\n";
			break;
		}
		case (file): {
			ifstream file;
			string s;
			string line;
			string  workstr;
			int countChar;
			cout << "������� ������ ����� �� �����: ";
			cin >> s;    // ������� �������� ������ file
			//file.open(s);    // ������� ���� �� ������
			//��� ������������
			file.open("C:\\Users\\admin\\source\\repos\\l14\\x64\\Debug\\tt1.txt");
			if (!file)
				cout << "���� �� ����� ���� ������!\n";      // ������� �� ������ �������
			int i = 0;
			if (file.is_open()) {				
				while (getline(file, line))
				{
					if (i == 0) {
						istringstream iss(line);
						iss >> countChar;
						if (iss.fail()) {
							cout << "�������� ������ ������!\n";
							break;
						}
						i++;
						continue;
					}
					workstr = workstr+" " + line;
				}
			}
			
			if(i != 0)
				cout << "���-�� ���� ���������� ��� ������� " << alg.GetCountWords(workstr, countChar) << "\n";

			break;
		}
		case (test): {
			//test2();
			break;
		}
		case (exitAAA):
			exit = 0;
			break;
		default:
			cout << "\n������������ ����. ������� ����� �� 1 �� 4\n";
			break;

		}
	}
}

//string Interface::ReadKeyboard()
//{
//	return "";
//}


