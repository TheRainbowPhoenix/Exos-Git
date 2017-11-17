struct Node {
	char info;
	Node * ch, * br;
};

class LexTree {
	Node * root;
	public :
		LexTree();
		LexTree(Node * n);
		LexTree(char c);
		~LexTree();
		friend Node * NN(char c, Node * nc, Node * nb);
		void print();
		void append(char * x);
};

