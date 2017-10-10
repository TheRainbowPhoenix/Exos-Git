#include "aa.h"
#include <iostream>

using namespace std;

Arbre::Arbre() {
	root = NULL;
}
Node * NN(int i, Node * g, Node * d) {
	Node * n = new Node;
	n->info = i;
	n->fg = g;
	n->fd = d;
	return n;
}
void afree(Node * n) {
	if(n) {
		afree(n->fg);
		afree(n->fd);
		delete n;
	}
}
Arbre::~Arbre() {
	afree(root);
}

Arbre::Arbre(Node * N) {
	root = N;
}
Arbre::Arbre(int i) {
	root = NN(i, NULL, NULL);
}
int Arbre::plength(Node * N) {
	int p;
	if (N) {
		int pg = plength(N->fg);
		int pd = plength(N->fd);
		int p = (pd>pg)?pd:pg;
		/*int p = pg;
		if (pd >pg) p=pd;*/
		p++;
		cout << N->info << " length: " << p;
		return p;
	}
	return 0;
}
void Arbre::alength() {
	plength(root);
}



int main() {
	Arbre A;
	return 0;
}
