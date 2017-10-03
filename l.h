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
};
