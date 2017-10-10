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
		~Arbre();
		friend Node * NN(int i, Node * g, Node * f);
		void alength();
		int plength(Node * N);
};
