#include <iostream>
#include "l.h"
using namespace std;
liste::liste() {
	tete = NULL;
	queue = NULL;
}
maillon::maillon(int x) {
	succ = NULL;
	pred = NULL;
	val = x;
}
maillon::~maillon() {
	if(succ!=NULL) { 
		delete succ;
	}
}

liste::~liste() {
	if(tete!=NULL) {
		delete tete;
	}
}
bool liste::vide() {
	return (tete==NULL)?true:false;
}
void liste::print() {
	/*
	maillon *x = tete;
	while(x) {
		cout << x->val << endl;
		x=x->succ;
	}*/
	maillon * x = tete;
	while(x != NULL) {
		cout << x->val << " <=> ";
		x=x->succ;
	}
	cout << "NULL\n";
}
void liste::InsertionEnTete(maillon * x) {
	x->succ = tete;
	if(!vide()) {
		tete->pred = x;
	}
	tete = x;
	tete->pred = NULL;
}
void liste::InsertionEnQueue(maillon * x) {
	if(vide()) {
		tete = queue = x;
	} else {
		queue->succ = x;
		x->pred = queue;
		queue = x;
	}
}
void liste::insertt(maillon * x) {
	if(vide()) {
		tete = queue = x;
	} else {
		queue->succ = x;
		x->pred = queue;
		queue = x;
	}
}
maillon * liste::Recherche(int k) {
	maillon * x = tete;
	if(!vide()) {
		while((x->val != k)&&(x)) x=x->succ;
	}
	return x;
}

int main() {
	liste L;
	maillon *v = new maillon(6);
	maillon *w = new maillon(4);
	maillon *x = new maillon(2);
	maillon *y = new maillon(3);
	maillon *z = new maillon(5);
	if(L.vide()) cout<<"empty\n";
	L.InsertionEnQueue(z);
	L.print();
	L.InsertionEnTete(x);
	L.print();
	L.InsertionEnQueue(w);
	L.print();
	L.InsertionEnTete(y);
	L.InsertionEnQueue(v);	
	L.print();
	cout << L.Recherche(5)->val << endl;
}
