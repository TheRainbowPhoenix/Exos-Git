#include <cstring>
#include <string>
using namespace std;
string color(int i);
string drink(int i);
string pet(int i);
string smoke(int i);
string natn(int i);
/*{ red, blue, green, white, yellow };
enum drink{ coffee, milk, wine, water, thea };
enum pet{ doggo, snail, fox, horse, zebra };
enum smoke{ OldGold, Kool, Chest, Craven, Git};
enum natn{ en, es, uk, no, jp};
*/

class Mat {
	int ** G;
	public:
		Mat();
		~Mat();
		void malloc();
		void print();
		void pprint();
		void insert(int x, int y, int v);
		void insertx(int * x, int y, int sz);
		void inserty(int x, int *y, int sz);
		void insertxy(int **xy, int xs, int ys);
		void bfill(int sz);
};
