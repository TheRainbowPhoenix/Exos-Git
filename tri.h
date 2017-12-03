class Table {
	int * T, H, Q;
	int n;
	private:
		int * TFus(int h, int q);
		int * Merge(int h, int q, int m);
		int * TQui(int h, int q);
		int Part(int h, int q);
		int * heapyfit(int sz, int i);
	public:
		Table();
		Table(int size);
		Table(int * Tab, int s);
		void print();
		void append(int i);
		void swap(int p1, int p2);
		void TBull();
		void TInsr();
		void TFusn();
		void TQuik();
		void THeap();
		void Tests();
		~Table();
};
