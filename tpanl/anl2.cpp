#include "anl.h"
#include <iostream>

using namespace std;

LexTree::LexTree() {
	root=NULL;
}

Node * NN(char c, Node *nc, Node * nb) {
	Node * n = new Node();
	n->info = c;
	n->ch = nc;
	n->br = nb;
	return n;
}

void afree(Node * n) {
	if (n) {
		afree(n->br);
		afree(n->ch);
		delete n;
	}
}

LexTree::~LexTree() {
	afree(root);
}

LexTree::LexTree(Node * n) {
	root=n;
}

LexTree::LexTree(char c) {
	root=NN(c, NULL, NULL);
}

void aprint(Node * n, int sig) {
	// sig :
	// 0 = no brothers (print next char)
	// 1 = haz bro (print next char without checking bro)
	// 2 = print whole word (skip check)
	if (n) {
		cout << n->info << endl;
		aprint(n->ch, 0);
		return;
	} else {
		cout <<"no n" << endl;
	}
	return;
	if (sig == 0) {
		cout<<"sig0\n";
		if(n->br) {
			cout << "= "<<endl;
			aprint(n->br, 1); // prints bro
		}
		if (n) {
			cout<< "1" << endl;
			cout<<n->info;
		}
		if(n->ch) {
			cout << "2" << endl;
			aprint(n->ch, 0); // prints whole word
		}
		else if(! n->ch) cout<< "3" <<endl;
	} else if (sig == 1) {
		if(n->br) {
			cout << "4" << endl;
			aprint(n->br,1);

		}
		cout << "5" << endl;
		cout<<"\n\t"<<n->info;
		aprint(n->ch,2);
		//TODO:do stuff
	} else {
		cout << "6" << endl;
		cout<<n->info;
		if(n->ch) aprint(n->br, 2);
		else cout<<endl;
		//TODO:do other stuff
	}
}

Node * aappendc(Node * N, char c, bool ch) {
	if (!N) return NN(c, NULL, NULL);
	if (ch) N->ch=NN(c, NULL, NULL);
	else N->br=NN(c, NULL, NULL);
	return N;
}

Node * aappends(Node * N, char * s) {
	//int i = 0;
	if(*s) {
		if(!N) {
		//	N=NN(*s, NULL, NULL);
			//cout << *s << endl;
		//	N->ch=aappends(N->ch, s+1);
		}
		//return N;

		cout << *s << endl;
		aappends(N, s+1);
	}
	//cout << c << &c++ << &c++ << endl;
	//while (s[i]) i++;
	//cout << i << endl;
	//char * x = &s[1];
	/*if (p<3) {
		cout << s << p << "\n";
		//if (s[1]) cout <<  &s[1] << " " <<  s[1] << "\n";
		 aappends(N, s, p+1);
	} else {
		return N;
	}*/
	//if (s[0]) cout << s[0];
	/*if (!N && s[0]) {
		cout << s;
		//N=NN(s[0], aappends(N->ch, &s[1]), NULL);
	}*/
	/*if (N && s[0]) {
		//if (N->info==s[0]) aappends(N->ch, &s[1]);
		//else aappends(N->br, s);
		cout << N->info;
	}*/
}

void LexTree::print() {
	aprint(root, 0);
}

void LexTree::append(char * x) {
	if (!x) return;
	aappends(root, x);
}

int main() {
	LexTree L;
	char ly[] = "hewwo";
	char s1[] = {'h', 'e', 'w', 'w', 'o', '\0'};
	L.append(ly);
	cout << "appended\n";
	L.print();
	return 0;
}
