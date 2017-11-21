class Table {
	int * T, H, Q;
	int n;
	public:
		Table();
		Table(int size);
		Table(int * Tab);
		void print();
		void append(int i);
		void swap(int p1, int p2);
		~Table();
};
