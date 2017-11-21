#include "tri.h"
#include <iostream>

using namespace std;

Table::Table() {
	T = NULL;
	H = NULL;
	Q = NULL;
	n = 0;
}

Table::Table(int size) {
	n = 0;
	T = new int[size];
	H = *T;
	Q = T[size-1];
}

Table::Table(int * Tab) {
	int i=0;
	n = 0;
	while(Tab[i]) i++;
	T= new int[i];
	H = *T;
	while(n<i) {
		T[n]=Tab[n];
		n++;
	}
	Q=*Tab;
}

Table::~Table() {
	delete [] T;
}

void Table::print() {
	for(int i=0; i<n; i++) cout << T[i]<<" ";
	cout<<endl;
}	

void Table::append(int i) {
	T[n]=i;
	Q = T[n];
	n++;
}

void Table::swap(int p1, int p2) {
	if (!T[p1] || ! T[p2]) return;
	int i = T[p1];
	T[p1]=T[p2];
	T[p2]=i;
}

int main() {
	int AT[]={4, 7, 8, 1, 9, 2};
	Table T(12);
	Table U(AT);
	U.print();
	T.append(4);
	T.append(7);
	T.append(8);
	T.append(1);
	T.append(9);
	T.append(2);
	T.swap(0, 1);
	T.print();
	return 0;
}

