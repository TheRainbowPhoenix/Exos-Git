#include <cstring>
#include <string>
using namespace std;
/*
string color(int i);
string drink(int i);
string pet(int i);
string smoke(int i);
string natn(int i);
*/
/*{ red, blue, green, white, yellow };
enum drink{ coffee, milk, wine, wather, thea };
enum pet{ doggo, snail, fox, horse, zebra };
enum smoke{ OldGold, Kool, Chest, Caven, Git};
enum natn{ en, es, uk, no, jp};
*/

class Mat {
	int ** G;
	public:
		Mat();
		~Mat();
		void print();
		void insert(int x, int y, int v);
		void insertx(int * x, int y, int sz);
		void inserty(int x, int *y, int sz);
		void insertxy(int **xy, int xs, int ys);
};
