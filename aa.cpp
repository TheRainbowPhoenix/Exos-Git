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
int Arbre::Rlength(Node * N) {
	if(N==NULL) return 0;
	int hd = Rlength(N->fd);
	int hg = Rlength(N->fg);
	if(hd>hg) return hd+1;
		else return hg+1;
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

void profondeur(Node * R, int p) {
	if (R==NULL) return;
	std::cout << R->info << " est de profondeur : ";
	profondeur(R->fg,p+1);
	profondeur(R->fd,p+1);
}

int amax(Node * N) {
	int d, g;
	if(!N->fd && !N->fg) return N->info;
	d = amax(N->fd);
	g = amax(N->fg);
	return (N->info > d && N->info > g)?(N->info):((d>g)?(d):(g));
}

int Arbre::max() {
	return (root)?(amax(root)):(0);
}

int omax(Node * N) {
	return (N->fd)?(amax(N->fd)):(N->info);
}

Node * append1(Node * N, int v) {
	if(!N) return NN(v, NULL, NULL);
	if(v > N->info) N->fd=append1(N->fd, v);
	if(v < N->info) N->fg=append1(N->fg, v);
	return N;
}

void append2(Node * &N, int v) {
	if(!N) {
		N = NN(v, NULL, NULL);
		return;
	}
	if(v < N->info) append2(N->fg, v);	
	if(v > N->info) append2(N->fd, v);
}

bool cmp(Node * N, Node * M) {
	return (!N)?((!M)?true:false):((!M)?false:(N->info == M->info)?((cmp(N->fg,M->fg) && cmp(N->fd,M->fg))?(true):(false)):false);
}

bool cmp2(Node * N, Node * M) {
	if((!N)||(!M)) {
		if((!N)&&(!M)) return true;
	} else {
		return false;
	}
	if(N->info == M->info)
		return (cmp2(N->fg, M->fg) && cmp2(N->fg, M->fg));
	else
		return false;
}

bool Arbre::cmp(Arbre A) {
	return cmp2(root, A.root);
}

void Arbre::append(int v) {
	root = append1(root, v);
	/* append2(root, v); */
}

Node * cp(Node *N) {
	return (!N)?(NULL):(NN(N->info, cp(N->fg),cp(N->fd)));
}

Node * rev(Node * N) {
	return (!N)?(NULL):(NN(N->info, cp(N->fd),cp(N->fg)));
}

Node * Arbre::cp(Node * N) {
	return cp(N);
}

Arbre::Arbre(Arbre &A) {
	root = cp(A.root);
}

int main() {
	Arbre A;
	return 0;
}
