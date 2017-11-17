struct Node {
	int info;
	Node * fg, * fd;
};

class Arbre {
	Node * root;
	public :
		Arbre();
		Arbre(Node * N);
		Arbre(int i);
		Arbre(Arbre &A);
		~Arbre();
		friend Node * NN(int i, Node * g, Node * f);
		void alength();
		int plength(Node * N);
		int Rlength(Node * N);
		void profondeur(Node * R, int p);
		int max();
		bool cmp(Arbre A);
		void append(int v);
		Node * cp(Node * N);
};
