class maillon {
	public:
		int val;
		maillon * succ;
		maillon * pred;
		maillon(int x);
		~maillon();
};
class liste {
	maillon * tete;
	maillon * queue;
	public:
		liste();
		~liste();
		bool vide();
		void print();
		void InsertionEnTete(maillon * x);
		void InsertionEnQueue(maillon * x);
		void insertt(maillon * x);
		maillon * Recherche(int k);
		void Suppression(maillon * x);
		void SuppressionEnQueue();
		void SuppressionEnTete();
};
class pile {
	int tete;
	int * tab;
	int max;
	public:
		pile();
		pile(int n);
		~pile();
		bool vide();
		bool empiler(int x);
		int depiler();
		void print();
};
class file {
	int tete;
	int queue;
	int * tab;
	int max;
	public:
		file();
		file(int n);
		~file();
		bool vide();
		bool pleine();
		bool Enfiler(int x);
		int Defiler();
		void print();
};
