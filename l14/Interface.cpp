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
		cout << "Некорректный ввод. Попробовать снова: ";
	}
}



void Interface::InterfaceMenu()
{
	int answ;
	Algoritm alg;
	int exit = 1;
	while (exit == 1) {
		cout << "------------------------------" << endl;
		cout << "Введите 1, если хотите ввести с клавиатуры" << endl;
		cout << "Введите 2, если хотите задать текст из файла" << endl;
		cout << "Введите 3, если хотите посмотреть тестовые примеры" << endl;
		cout << "Введите 4 для выхода из программы" << endl;
		answ = ValidateInput();
		enum menu {
			keyboard = 1,
			file,
			test,
			exitAAA
		};
		switch (answ) {
		case (keyboard): {
			cout << "Введите исходную строку " << endl;
			string query;
			getline(cin >> ws, query);
			cin.clear();

			//vector<string> data = alg.Split(query);

			
			string countCharStr;
			int countChar = 0;

			cout << "Введите кол-во символов " << endl;
			cin >> countCharStr;			
			istringstream iss(countCharStr);

			iss >> countChar;
			cin.clear();

			if (iss.fail()) {
				cout << "Неверный формат данных!\n";
				break;
			}
			cout << "Кол-во слов подходящих под условие " << alg.GetCountWords(query, countChar) << "\n";
			break;
		}
		case (file): {
			ifstream file;
			string s;
			string line;
			string  workstr;
			int countChar;
			cout << "Введите полный адрес до файла: ";
			cin >> s;    // создать поточный объект file
			//file.open(s);    // открыть файл на чтение
			//Для тестирования
			file.open("C:\\Users\\admin\\source\\repos\\l14\\x64\\Debug\\tt1.txt");
			if (!file)
				cout << "Файл не может быть открыт!\n";      // возврат по ошибке отрытия
			int i = 0;
			if (file.is_open()) {				
				while (getline(file, line))
				{
					if (i == 0) {
						istringstream iss(line);
						iss >> countChar;
						if (iss.fail()) {
							cout << "Неверный формат данных!\n";
							break;
						}
						i++;
						continue;
					}
					workstr = workstr+" " + line;
				}
			}
			
			if(i != 0)
				cout << "Кол-во слов подходящих под условие " << alg.GetCountWords(workstr, countChar) << "\n";

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
			cout << "\nНекорректный ввод. Введите числа от 1 до 4\n";
			break;

		}
	}
}

//string Interface::ReadKeyboard()
//{
//	return "";
//}


