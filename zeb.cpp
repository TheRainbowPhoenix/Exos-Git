#include "zeb.h"
#include <iostream>

using namespace std;

Mat::Mat() {
	G = new int*[5];
	for(int i=0; i<5; i++) G[i]=new int[5];
}

Mat::~Mat() {
	for(int i=0; i<5; i++) 	delete G[i];
	delete [] G;
}

void Mat::print() {
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) cout<<G[j][i]<< " ";
		cout<<endl;
	}
}

void Mat::insert(int x, int y, int v) {
	G[x][y]=v;
}

// insert code :
// [1-5] code in enum
// 6 = SkipValue
// 0 = reset

void Mat::insertx(int * x, int y, int sz) {
	for(sz; sz>0; sz--) if(x[sz-1]<6) G[y-1][sz-1]=x[sz-1];
}

void Mat::inserty(int x, int * y, int sz) {
	for(sz; sz>0; sz--) if(y[sz-1]<6) G[sz-1][x-1]=y[sz-1];
}

void Mat::insertxy(int **xy, int xs, int ys) {
	int i = ys;
	for(xs; xs>0; xs--) for(ys=i; ys>0; ys--) if(xy[ys-1][xs-1]<6) G[ys-1][xs-1]=xy[ys-1][xs-1];
}

string color(int i) {
	switch(i) {
		case 0: return "red"; break;
		case 1: return "green"; break;
		case 2: return "white"; break;
		case 3: return "yellow"; break;
		case 4: return "blue"; break;
	}
}

int main() {
	Mat M;
	int x1[5] = {1,2,3,4,5};
	int x2[5] = {2,3,4,5,1};
	int x3[5] = {3,4,5,1,2};
	int x4[5] = {4,5,1,2,3};
	int x5[5] = {5,1,2,3,4};
	int y3[5] = {3,4,5,1,2};
	int **m;
	m=new int*[3];
	for(int i=0; i<3; i++) m[i]=new int[3];
	m[0][0]=6;
	m[0][1]=4;
	m[0][2]=3;
	m[1][0]=4;
	m[1][1]=3;
	m[1][2]=2;
	m[2][0]=3;
	m[2][1]=2;
	m[2][2]=1;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) cout << m[j][i]<< " ";
		cout << endl;
	}
	M.insertx(x1, 1, 5);
	M.insertx(x2, 2, 5);
	M.insertx(x4, 4, 5);
	M.insertx(x3, 3, 5);
	M.insertx(x5, 5, 5);

	M.inserty(3, y3, 4);
	M.print();
	cout << endl;
	M.insertxy(m, 3, 3);
	M.print();
	//cout << endl << color(3) << drink(2) << pet(4) << smoke(5) << natn(1)<<endl;
	return 0;
}
