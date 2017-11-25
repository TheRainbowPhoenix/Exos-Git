#include "zeb.h"
#include <iostream>

using namespace std;

string color(int i) {
	switch(i) {
		case 1: return "red"; break;
		case 2: return "green"; break;
		case 3: return "white"; break;
		case 4: return "yellow"; break;
		case 5: return "blue"; break;
	}
	return "NULL";
}

string drink(int i) {
	switch(i) {
		case 1: return "coffee"; break;
		case 2: return "milk"; break;
		case 3: return "wine"; break;
		case 4: return "water"; break;
		case 5: return "thea"; break;
	}
	return "NULL";
}

string pet(int i) {
	switch(i) {
		case 1: return "doggo"; break;
		case 2: return "snail"; break;
		case 3: return "fox"; break;
		case 4: return "horse"; break;
		case 5: return "zebra"; break;
	}
	return "NULL";
}

string smoke(int i) {
	switch(i) {
		case 1: return "OldGold"; break;
		case 2: return "Kool"; break;
		case 3: return "Chest"; break;
		case 4: return "Craven"; break;
		case 5: return "Git"; break;
	}
	return "NULL";
}

string natn(int i) {
	switch(i) {
		case 1: return "en"; break;
		case 2: return "es"; break;
		case 3: return "uk"; break;
		case 4: return "no"; break;
		case 5: return "jp"; break;
	}
	return "NULL";
}


Mat::Mat() {
	G = new int*[5];
	for(int i=0; i<5; i++) G[i]=new int[5];
}

void Mat::malloc() {
	for(int i=0; i<5; i++) for(int j=0; j<5; j++) G[j][i]=0;
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

void Mat::pprint() {
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			switch(i+1) {
				case 1: cout<<color(G[j][i])<<"\t"; break;
				case 2: cout<<drink(G[j][i])<<"\t"; break;
				case 3: cout<<pet(G[j][i])<<"\t"; break;
				case 4: cout<<smoke(G[j][i])<<"\t"; break;
				case 5: cout<<natn(G[j][i])<<"\t"; break;
			}
		}
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

int main() {
	Mat M;
	M.malloc();
	int x1[5] = {1,2,3,4,5};
	int x2[5] = {2,3,4,5,1};
	int x3[5] = {3,4,5,1,2};
	int x4[5] = {4,5,1,2,3};
	int x5[5] = {5,1,2,3,4};
	//int y3[5] = {3,4,5,1,2};
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
	// M.insertx(x1, 1, 5);
	// M.insertx(x2, 2, 5);
	// M.insertx(x4, 4, 5);
	// M.insertx(x3, 3, 5);
	// M.insertx(x5, 5, 5);

	//M.inserty(3, y3, 4);
	// M.print();
	// cout << endl;
	// M.insertxy(m, 3, 3);
	// M.print();
	//M.pprint();
	//cout << endl << color(3) << drink(2) << pet(4) << smoke(5) << natn(1)<<endl;

	/* Init Infos */

	/* linear */
	int l1[5] = {1,6,6,6,1}; // !c1			!l3	!l4	l5	!l6	l7
	//int l2[5] = {6,6,1,6,2};
	int l3[5] = {3,1,6,6,6}; // !c1 !l1			!l4	l5	l6	!l7
	int l4[5] = {6,5,6,6,3}; // !c1 !l1	!l3			l5	!l6	!l7
	int l5[5] = {6,6,2,1,6}; // !c1 l1	l3	l4	l5	!l6	!l7
	int l6[5] = {6,6,6,4,5}; // !c1 !l1	l3	!l4	!l5			!l7
	int l7[5] = {6,3,6,5,6}; // !c1 l1	!l3	!l4	!l5	!l6
	//int l8[5] = {5,6,6,6,2};
	//int l9[5] = {5,6,6,2,6};

	int a1[5] = {6,6,6,6,4}; // absolute condition
	int a2[2] = {6,2};

	/* floating condition 1 */

	int **f1;
	f1=new int*[3];
	for(int i=0; i<3; i++) f1[i]=new int[5];
	for(int i=0; i<5; i++) for(int j=0; j<3; j++) f1[j][i]=6;

	f1[0][2]=3;
	f1[2][2]=3;
	f1[1][3]=3;

	/* floating condition 2 */

	int **f2;
	f2=new int*[3];
	for(int i=0; i<3; i++) f2[i]=new int[5];
	for(int i=0; i<5; i++) for(int j=0; j<3; j++) f2[j][i]=6;

	f2[0][2]=4;
	f2[2][2]=4;
	f2[1][3]=2;


	/* floating condition 3 */

	int **f3;
	f3=new int*[3];
	for(int i=0; i<3; i++) f3[i]=new int[5];
	for(int i=0; i<5; i++) for(int j=0; j<3; j++) f3[j][i]=6;

	f3[0][2]=4;
	f3[2][2]=4;
	f3[1][3]=2;

	// for(int i=0; i<5; i++) {
	// 	for(int j=0; j<3; j++) cout << f1[j][i]<< " ";
	// 	cout << endl;
	// }

	/* compressed condition */
	int c1[5] = {5,6,1,2,2}; // l2 + l8 + l9

	/* potential compressed condition */
	int c2[5] = {1,3,0,5,1}; // l1 + l7
	int c3[5] = {3,1,2,1,0}; // l3 + l5
	int c4[5] = {0,5,2,1,3}; // l4 + l5
	int c5[5] = {1,0,2,1,1}; // l1 + l5
	int c6[5] = {3,1,0,4,5}; // l3 + l6

	/* potential solutions groups */
	// g1 = c1 + c2 + c3 + l4 + l6
	int g1_1[5] = {5,0,1,2,2};
	int g1_2[5] = {1,3,0,5,1};
	int g1_3[5] = {3,1,2,1,0};
	int g1_4[5] = {6,5,6,6,3};
	int g1_5[5] = {6,6,6,4,5};
	// g2 = c1 + c2 + c4 + c6
	int g2_1[5] = {1,3,0,5,1};
	int g2_2[5] = {0,5,2,1,3};
	int g2_3[5] = {3,1,0,4,5};
	int g2_4[5] = {5,0,1,2,2};


	M.insertx(a1, 1, 5);
	M.insertx(a2, 3, 2);

	M.print();

	return 0;
}
