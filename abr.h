class node {
	public:
	int key;
	node *fg;
	node *fd;
	node *pere;
	public:
		node(int k);
		void add(int k);
		void print();
		bool search(int n);
		node * min();
		node * max();
		node * succ();
		node * searchp(int n);
		void rm(int n);
		int get();
		int height();
};
class arbre {
	node * r;

	public:
		arbre();
		void add(int c);
		void print();
		bool search(int k);
		node * max();
		node * min();
		node * searchp(int n);
		node * succ(int k);
		node * succ(node * n);
		int height();
		void rm(node *n);
};
