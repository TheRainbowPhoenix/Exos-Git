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
	x->succ = NULL;
	x->pred = queue;
	if(!vide()) {
		queue->succ=x;
	} else {
		tete = x;
	}
	queue = x;
}
void liste::insertt(maillon * x) {
	x->succ = NULL;
	x->pred = queue;
	if(vide()) {
		tete = x;
	} else {
		queue->succ = x;
	}
	queue = x;
}
maillon * liste::Recherche(int k) {
	maillon * x = tete;
	while((x)&&(x->val!=k)) {
		x=x->succ;
		return x;
	}
	return x;
}

int main() {
	liste L;
	maillon *w = new maillon(4);
	maillon *x = new maillon(2);
	maillon *y = new maillon(3);
	maillon *z = new maillon(5);
	if(L.vide()) cout<<"empty\n";
	L.insertt(z);
	L.print();
	L.InsertionEnTete(x);
	L.print();
	L.insertt(w);
	L.print();
	L.InsertionEnTete(y);
	//L.InsertionEnTete(z);
	//L.insertt(z);	
	L.print();
}
