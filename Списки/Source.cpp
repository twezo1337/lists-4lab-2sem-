#include <fstream>
#include <iostream>
using namespace std;

struct Date {
	short day;
	short mounth;
	short year;
};

struct Owner {
	char sur[25];
	char name[25];
	char otch[25];
};

struct Fuel {
	short mark;
	double kolLit;
	Date date;
	Owner owner;
};

struct Node {
	Fuel fuel;
	Node* next, * prev;
};

void dataInput(Node* pv) {

	cout << "������� ����� �������: ";
	cin >> pv->fuel.mark;

	cout << "������� ���-�� ������: ";
	cin >> pv->fuel.kolLit;

	cout << "������� ����: ";
	cin >> pv->fuel.date.day;

	cout << "������� �����: ";
	cin >> pv->fuel.date.mounth;

	cout << "������� ���: ";
	cin >> pv->fuel.date.year;

}

Node* first(void) {
	Node* pv = new Node;
	dataInput(pv);
	pv->next = 0;
	pv->prev = 0;
	return pv;
}

Node* add(Node* pend) {
	Node* pv = new Node;
	dataInput(pv);
	pv->next = 0;
	pv->prev = 0;
	pend->next = pv;

	return pv;
}



void print(Node* pbegin) {
	Node* pv = pbegin;
	while (pv) {
		cout << pv->fuel.mark << endl;
		cout << pv->fuel.kolLit << endl;
		cout << pv->fuel.date.day << endl;
		cout << pv->fuel.date.mounth << endl;
		cout << pv->fuel.date.year << endl;
		cout << endl;
		pv = pv->next;
	}
	return;
}


int main(void) {
	setlocale(LC_ALL, "RUSSIAN");
	Node* pbegin, * pend;

	pend = pbegin = first();

	int n;
	cout << "������� ���-�� ����������: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		pend = add(pend);
	}
	print(pbegin);


	system("pause");
	return 0;
}