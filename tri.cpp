#include "tri.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

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
/*
void Table::TBull() {
	for(int i=0; i<n; i++) {
		for(int j=n; j>i; j--) {
			if (T[j]<T[j-1]) swap(j, j-1);
		}
	}
}*/

void Table::TBull() {
	if (n<2) return;
	for(int i=n; i>0; i--) if (T[i]<T[i-1]) swap(i, i-1);
	n--;
	TBull();
	n++;
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
int Table::Part(int h, int q) {
	int l = h-1;

	for (int i = h; i+1 <= q; i++) {
		if(T[i]<=T[q]) {
			swap(++l, i);
		}
	}
	swap(++l,q);
	return l;
}
int * Table::TQui(int h, int q) {
	if(h<q) {
		int m = Part(h, q);
		TQui(h, m-1);
		TQui(m+1, q);
	}
return T;
}

int * Table::heapyfit(int sz, int i) {
	int m = i;
	int h = 1 + i*2;
	int q = 2 + i*2;

	if (sz>h && T[m]<T[h]) m=h;
	if(sz>q && T[m]<T[q]) m=q;
	if(i!=m) {
		swap(i, m);
		heapyfit(sz, m);
	}
	return T;
}

void Table::TFusn() {
	T=TFus(0, n);
}

void Table::TQuik() {
	T=TQui(0, n);
}

void Table::THeap() {
	for (int i = n/2; i >0; i--) {
		heapyfit(n, i-1);
	}
	for (int i = n; i >0; i--) {
		swap(0, i-1);
		heapyfit(i-1, 0);
	}
}

int * RFill(int n) {
	int * T = new int[n];
	for (int i=0; i<n; i++) T[i]=(rand() % n)+1;
	return T;
}

int * RandomArray(int n) {
	int *A = new int[n];
	for(int i=0; i<n;i++) A[i]=rand()%(n+1);
	return A;
}

void Table::Tests() {
	int n = 0;
	time_t b,e;
	for(n=10000; n<=100000; n+=10000) {
		Table B(RFill(n),n);
		Table I(RFill(n),n);
		Table F(RFill(n),n);
		Table Q(RFill(n),n);
		Table H(RFill(n),n);

		cout << n << "\t";
		time(&b);
		B.TBull();
		time(&e);
		double d = difftime(e,b);
		cout << d << "\t";

		time(&b);
		I.TInsr();
		time(&e);
		d = difftime(e,b);
		cout<< d << "\t";

		time(&b);
		F.TFusn();
		time(&e);
		d = difftime(e,b);
		cout << d << "\t";

		time(&b);
		Q.TQuik();
		time(&e);
		d = difftime(e,b);
		cout << d << "\t";

		time(&b);
		H.THeap();
		time(&e);
		d = difftime(e,b);
		cout << d <<endl;
	}
}


int main() {
	int AT[]={4, 7, 8, 1, 9, 2};
	Table T(12);
	Table U(AT, 6);
	Table V(RFill(9), 9);
	//V.print();
	//U.print();
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
	//T.TQuik();
	T.THeap();
	U.TQuik();
	V.TQuik();
	U.print();
	T.print();
	V.print();
	cout << endl;
	int *A=RandomArray(7);
	for(int i=0; i<7;i++) cout << A[i]<< " ";
	cout << endl;
	T.Tests();
	return 0;
}
