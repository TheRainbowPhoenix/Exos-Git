#include <iostream>
#include "l.h"
using namespace std;

const int M = 1000;

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
void liste::Suppression(maillon * x) {
	if(x->pred != NULL) {
		(x->pred)->succ = x->succ;
	} else {
		tete = x->succ;
	}
	if(x->succ != NULL) {
		(x->succ)->pred = x->pred;
	} else {
		queue = x->pred;
	}
	//delete x;
	free(x);
}
void liste::SuppressionEnQueue() {
	Suppression(queue);
}
void liste::SuppressionEnTete() {
	Suppression(tete);
}

pile::pile() {
	tete = 0;
	tab = new int(max);
}
pile::pile(int n) {
	tete = 0;
	tab = new int(n);
	max = n;
}
pile::~pile() {
	delete [] tab;
}
bool pile::vide() {
	return (tete=0)?false:true;
}
bool pile::empiler(int x) {
	if(tete == max) return false;
	tab[tete] = x;
	tete++;
	return true;
}
int pile::depiler() {
	if(tete == 0) return 0;
	int j = tab[tete-1];
	tab[tete-1] = NULL;
	tete--;
	return j;
}
void pile::print() {
	std::cout << "[ ";
	for(int i=0; i<tete;i++)
		std::cout << tab[i] << " ";
	std::cout << "]" << std::endl;
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
	L.Suppression(x);
	// === x n'existe plus ===
	L.print();
	L.SuppressionEnQueue();
	L.print();
	L.SuppressionEnTete();
	L.print();
	L.SuppressionEnQueue();
	L.print();
	cout << L.Recherche(5)->val << endl;
	pile P(100);
	P.print();
	cout << P.vide() << endl;
	P.print();
	P.depiler();
	P.empiler(6);
	P.empiler(2);
	P.empiler(1);
	P.print();
	//P.depiler();
	cout << P.depiler() << endl;
	cout << P.depiler() << endl;
	cout << P.depiler() << endl;
	P.print();
	cout << P.depiler() << endl;
}
