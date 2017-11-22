#include "tri.h"
#include <iostream>

using namespace std;

Table::Table() {
	T = NULL;
	H = NULL;
	Q = NULL;
	n = 0;
}

Table::Table(int size) {
	n = 0;
	T = new int[size];
	H = *T;
	Q = T[size-1];
}

Table::Table(int * Tab, int s) {
	int i=0;
	n = 0;
	T= new int[s];
	H = *T;
	while(n<s) {
		T[n]=Tab[n];
		n++;
	}
	Q=*Tab;
}

Table::~Table() {
	delete [] T;
}

void Table::print() {
	for(int i=0; i<n; i++) cout << T[i]<<" ";
	cout<<endl;
}	

void prn(int * T, int sz) {
	while(sz>0) {
		cout << T[sz]<< " ";
		sz--;
	}
}

void Table::append(int i) {
	T[n]=i;
	Q = T[n];
	n++;
}

void Table::swap(int p1, int p2) {
	if (!T[p1] || ! T[p2]) return;
	int i = T[p1];
	T[p1]=T[p2];
	T[p2]=i;
}

void Table::TBull() {
	for(int i=0; i<n; i++) {
		for(int j=n; j>i; j--) {
			if (T[j]<T[j-1]) swap(j, j-1);
		}
	}
}

void Table::TInsr() {
	if(n) {
		n--;
		TInsr();
		n++;
		int k = n;
		while((k>0)&&(T[k-1]>T[k])) {
			swap(k, k-1);
			k--;
		}
	}
}
int * Table::Merge(int h, int q, int m) {
	int i=h;
	int j = m+1;
	int R[n];
	int k = 0;
	while (i<=m&&j<=n) (T[i]<T[j]&&T[i]!=0)?(R[k++]=T[i++]):(R[k++]=T[j++]);
	while(i<=m) R[k++]=T[i++];
	while(j<=n) R[k++]=T[j++];
	for (int i=n; i>=h; i--) T[i]=R[--k];	
	return T;
	
}
int * Table::TFus(int h, int q) {
	if(h<q) {
		int m = (h+q)/2;
		T = TFus(h, m);
		T = TFus(m+1, q);
		T = Merge(h, q, m);
	}
	return T;
}
int * Table::Part(int h, int q, int m) {
	int l = h+1;
	int k = q;
	while (l <= k) {
		while(T[l] <= T[h]) l++;
		while(T[k] > T[h]) k--;
		if (l<k) swap(l++, k--);
	}
	m = k;
	swap(h, k);
	return T;
}
int * Table::TQui(int h, int q) {
	for(int m=h; m<=q; m++) {
		if(h<q) {
			Part(h, q, m);
			TQui(h, m-1);
			TQui(m+1, q);
		}
	}
	return T;
}

void Table::TFusn() {
	T=TFus(0, n);
}

void Table::TQuik() {
	T=TQui(0, n);
}

int * RFill(int n) {
	int * T = new int[n];
	for (int i=0; i<n; i++) T[i]=(rand() % n)+1;
	return T;
}

void Table::Tests() {
	int n = 0;
	for(n=5; n<=500; n+=100) {
		cout <<n<<"\t...\t...\t...\t...\t..."<<endl;
	}
}


int main() {
	int AT[]={4, 7, 8, 1, 9, 2};
	Table T(12);
	Table U(AT, 6);
	Table V(RFill(9), 9);
	V.print();
	U.print();
	T.append(4);
	T.append(7);
	T.append(8);
	T.append(1);
	T.append(9);
	T.append(2);
	T.append(5);
	T.swap(0, 1);
	T.print();
	//T.TBull();
	//T.TInsr();
	//U.TFusn();
	//T.TFusn();
	T.TQuik();
	U.TQuik();
	V.TQuik();
	U.print();
	T.print();
	V.print();
	T.Tests();
	return 0;
}

