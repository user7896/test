#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

//������� �������� ��� �������� ������� � ������� *.txt

void main_menu() {
	cout << "������� ����� ����...\n" << "1) ������� �������\n" << "2) ������������� ��� ������������ �������\n" << "3) �����...\n";
}

void f_create() {//�������� �������
	string x, text_name;
	cout << "������� �������� ����� �������:\n";
	cin >> text_name;
	text_name += ".txt";
	ofstream input_line(text_name);
	cout << "������� ����� �������:\n";
	cin >> x;
	input_line << x;
	input_line.close();

	system("pause");
}

void f_change() {//�������������� �������

	string x, text_name;
	cout << "������� �������� ������� ��� ��������������:\n";
	cin >> text_name;
	text_name += ".txt";

	ifstream output_line(text_name);

	if (!output_line.is_open()) { cout << "���� �� ����������"; }
	else {

		system("cls");

		getline(output_line, x);
		cout << "������� �������:\n";
		cout << x;
		output_line.close();
		cout << endl << "�������� �������:\n";

		ofstream input_line(text_name);
		cin >> x;
		input_line << x;
		input_line.close();

		system("pause");
		cout << endl << "��� ����������� ������� Enter\n";
		cin.get();
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int i = 4;
	ofstream test_file("not_empty_file.txt");//������� � ������� ��� 1-��� �������
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
			cout << "�������������� ����� ����. ����������, ��������� ����:";
			break;
		}
	}

	return 0;
}