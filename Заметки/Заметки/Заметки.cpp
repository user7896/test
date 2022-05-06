#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

//Простая програма для создания заметок в формате *.txt

void main_menu() {
	cout << "Введите пункт меню...\n" << "1) Создать заметку\n" << "2) Редактировать уже существующую заметку\n" << "3) Выход...\n";
}

void f_create() {//создание заметки
	string x, text_name;
	cout << "Введите название новой заметки:\n";
	cin >> text_name;
	text_name += ".txt";
	ofstream input_line(text_name);
	cout << "Введите текст заметки:\n";
	cin >> x;
	input_line << x;
	input_line.close();

	system("pause");
}

void f_change() {//редактирование заметки

	string x, text_name;
	cout << "Введите название заметки для редактирования:\n";
	cin >> text_name;
	text_name += ".txt";

	ifstream output_line(text_name);

	if (!output_line.is_open()) { cout << "Файл не существует"; }
	else {

		system("cls");

		getline(output_line, x);
		cout << "Текущая заметка:\n";
		cout << x;
		output_line.close();
		cout << endl << "Измените заметку:\n";

		ofstream input_line(text_name);
		cin >> x;
		input_line << x;
		input_line.close();

		system("pause");
		cout << endl << "Для продолжения нажмите Enter\n";
		cin.get();
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int i = 4;
	ofstream test_file("not_empty_file.txt");//заметка с текстом для 1-ого запуска
	test_file << "text";
	test_file.close();

	main_menu();

	while (i != 3) {
		cin >> i;
		switch (i) {

		case 1:
			system("cls");
			f_create();
			system("cls");
			main_menu();
			break;

		case 2:
			system("cls");
			f_change();
			system("cls");
			main_menu();
			break;

		case 3:
			break;

		default:
			cout << "Несуществующий пункт меню. Пожалуйста, повторите ввод:";
			break;
		}
	}

	return 0;
}