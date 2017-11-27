#include "zeb.h"
#include <iostream>

using namespace std;

string color(int i) {
	switch(i) {
		case 1: return "red"; break;
		case 2: return "blue"; break;
		case 3: return "green"; break;
		case 4: return "white"; break;
		case 5: return "yellow"; break;
	}
	return "NULL";
}

string drink(int i) {
	switch(i) {
		case 1: return "coffee"; break;
		case 2: return "milk"; break;
		case 3: return "wine"; break;
		case 4: return "water"; break;
		case 5: return "tea"; break;
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

void Mat::bfill(int sz) {
	int x, y = sz;
	int c = 0;
	int bx = 0;
	int by = 0;

	for(x=sz; x>0; x--) {
		for(y=sz; y>0; y--) {
			if(G[y-1][x-1]==0) {
				bx=x;
				by=y;
			} else {
				c+=G[y-1][x-1];
			}
		}
		if(15-c<6 && bx != 0) {
			G[by-1][bx-1]=15-c;
			//cout<<15-c<<" "<<bx<<by<<endl;
		}
		c=0;
		bx=0;
		by=0;
	}
}

bool searchIn(int * ct, int ** cm, int sz)
{
	int i = 0;
	for(int j=0; j<sz; j++) {
		while(cm[j][i]==ct[i]) i++;
		if(i>4) return true; //si i==5 ne marche pas sur certains compilateurs mais remarche après avoir compilé une fois avec i>4.
		i=0;
	}
	return false;
}

int ** lcomp(int ** lm, int sz) {
	//init matrice de retour
	int ** cm;
	cm=new int*[19];
	for(int i=0; i<19; i++) cm[i]=new int[5];

	for(int i=0; i<19; i++) {
		for(int j=0; j<5; j++) {
			cm[i][j]=0;
		}
	}

  cout << "matrice lm" << endl;
	for(int i=0; i<sz; i++) {
		for(int j=0; j<5; j++) {
			cout << lm[i][j] << " ";
		}
		cout << endl;
	}
  cout << endl;

	//compte les 6
	// copier lm dans lm2
	//comparer ligne lm à lignes lm2 (copier lm)
	//lm ligne 1 comparé à lm2 ligne 1 puis 2 puis 3 puis 4
	//ligne suivante, etc
	//si ligne de lm = ligne lm2 on skip.
	//puis afficher les deux matrices.

int x, y = sz;
int c = 0;
int o = 0;
int p = 0;
int ctmp[5] = {0,0,0,0,0};

for(int z=0; z<sz; z++) {
		for(x=0; x<sz; x++) {
			y=0;
			//while (y<5 && ! ( lm[x][y] != 6 && lm[z][y] != 6)) {
			while (y<5 && ((lm[x][y]==6 || lm[z][y]==6) || (lm[x][y]==6 && lm[z][y]==6))) {
				ctmp[y] = lm[x][y]+lm[z][y]-6;
				y++;
			}
			if(y==5) {
				if(! searchIn(ctmp, cm, 19)) {
					for(int i=0; i<5; i++) {
						cm[c][i]=ctmp[i];
					}
					c++;
				}
			}
		}
	}
	return cm;
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
	// M.pprint();
	//cout << endl << color(3) << drink(2) << pet(4) << smoke(5) << natn(1)<<endl;

	/* Init Infos */

	/* linear */
	int l1[5] = {1,6,6,6,1}; // l5	l7
	int l2[5] = {6,6,1,6,2}; // l3	l7	l8
	int l3[5] = {3,1,6,6,6}; // l5	l6
	int l4[5] = {6,5,6,6,3}; // l5 => keep
	int l5[5] = {6,6,2,1,6}; // l1	l3	l4	l5
	int l6[5] = {6,6,6,4,5}; // l3
	int l7[5] = {6,3,6,5,6}; // l1
	int l8[5] = {5,6,6,2,6}; // l2	l4 =>keep


	// lcomp : generate potential compressed condition */
	int ** lm;
	lm=new int*[8];
	for(int i=0; i<8; i++) lm[i]=new int[5];
	lm[0]=l1;
	lm[1]=l2;
	lm[2]=l3;
	lm[3]=l4;
	lm[4]=l5;
	lm[5]=l6;
	lm[6]=l7;
	lm[7]=l8;
	lm = lcomp(lm,8);

	cout << "Potentials conditions :" << endl;

	for(int i=0; i<18; i++) {
		if(lm[i][0]!=0) {
			for(int j=0; j<5; j++) {
				cout << lm[i][j] << " ";
			}
			cout << endl;
		}
	}



	int a1[5] = {6,6,6,6,4}; // absolute condition
	int a2[2] = {6,2};

	/* potential compressed condition */
	int c1[5] = {5,5,6,2,3}; // l4 + l8
	int c2[5] = {1,3,6,5,1}; // l1 + l7
	int c3[5] = {3,1,2,1,6}; // l3 + l5
	int c4[5] = {6,5,2,1,3}; // l4 + l5

	int c5[5] = {1,6,2,1,1}; // l1 + l5 => la seule utile
	int c6[5] = {3,1,6,4,5}; // l3 + l6 => avec elle
	int c7[5] = {6,3,1,5,2}; // l2 + l7 => utile

	int c8[5] = {5,6,1,2,6}; // l2 + l8


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

	// F4 : [1] 4 à coté de [1] 3


	/* potential solutions groups */
	// g1 = l8 + l4 + c5 + c7 + c6
	int g1_1[5] = {5,0,0,2,0};
	int g1_2[5] = {0,5,0,0,3};
	int g1_3[5] = {1,0,2,1,1};
	int g1_4[5] = {0,3,1,5,2};
	int g1_5[5] = {3,1,0,4,5};

/*
=> met les a
0 0 0 0 0
0 0 2 0 0
0 0 0 0 0
0 0 0 0 0
4 0 0 0 0

=> met les g // si plusieurs, plusieurs schémas
5 0 1 0 3
0 5 2 3 1
0 0 2 1 0
2 0 1 5 4
4 3 1 2 5

=> application primaires des f (sures)
5 * 1 *? 3 // 4 ? 2 *
0 5 2 3 1
* ? 2 1 0 // 4 ? 3 *
2 * 1 5 4 // 3 *
4 3 1 2 5

=> application secondaire des f (à partir du schéma précédent)
5 * 1 4 3 // 2 *
0 5 2 3 1
* 4 2 1 0 // 3 *
2 * 1 5 4 // 3 *
4 3 1 2 5

=> bfill de la matrice
5 2 1 4 3
0 5 2 3 1
3 4 2 1 0
2 3 1 5 4
4 3 1 2 5

//------------------

*/

int s1[5] = {5,6,3,2,6};
int s2[5] = {2,5,4,3,3};
int s3[5] = {1,6,2,1,1};
int s4[5] = {4,3,1,5,2};
int s5[5] = {3,1,6,4,5};

/*
=> résultat final, go pprint()
5 2 1 4 3
4 5 2 3 1
3 4 2 1 5
2 3 1 5 4
4 3 1 2 5
*/

	// Insert initial conditions (a1 and a2)
	M.insertx(a1, 1, 5);
	M.insertx(a2, 3, 2);

	// insert lines with a f-processor
	M.insertx(s1, 1, 5);
	M.insertx(s2, 2, 5);
	M.insertx(s3, 3, 5);
	M.insertx(s4, 4, 5);
	M.insertx(s5, 5, 5);


	// replace the 0 by their value
	M.bfill(5);

//TODO: Backtracking plz

	M.pprint();

	return 0;
}
