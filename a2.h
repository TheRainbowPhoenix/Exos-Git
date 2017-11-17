#include <iostream>
using namespace std;
class Node {
	public:
	string name;
	Node * pere;
	Node * fg;
	Node * fd;
	Node(string &s);
	~Node();
};
class Arbre {
	Node *R;
	Node *C;
	public:
		Arbre();
		~Arbre();
		void mkdir(string &s);
		void rmkdir(string &s);
		bool hasdir(string &s);
		string fullpath();
		void clean();
		void cd(string &s);
		Node * mkNode(string &s);
		void print();
		void cprint();
		string pwd();
		bool find(string n);
		void insert(Node * X, Node * Y);
		void cins(string &n);
		void rins(string &s);
};
