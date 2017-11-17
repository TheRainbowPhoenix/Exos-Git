#include "a2.h"
#include <iostream>
using namespace std;

string * ft_strtok(string str, string del) {
	string * rtn = new string[40];
	int it = 0;
	int id = 0;
	int sz = 0;
	while(str[it] <= ' ') it++;
	if(str[it]=='/') {
		rtn[id]+="/\0";
		id++;
		it++;
	}
	for(it; it<str.size(); it++) {
		if(str[it]=='/' || str[it] == ' ' || str[it] == '\t') {
			if (sz>0) {
				if(str[it]=='/' && str[it+1] != '\0') {
					rtn[id]+='\0';
					sz=0;
					id++;
				}
			}
		} else {
			if(!(str[it] & ~0x7F) && str[it] >= '(') {
				rtn[id]+=str[it];
				sz++;
			}
		}
	}
	return rtn;
}

int	ft_strcmp(string s1, string s2)
{
	int i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return ((char)s1[i] - (char)s2[i]);
}

Node::Node(string &s) {
	name=s;
	pere=NULL;
	fg=NULL;
	fd=NULL;
}
Node::~Node() {
	pere=NULL;
	fd=NULL;
	fg=NULL;
}
Arbre::Arbre() {
	string h = "/";
	R = mkNode(h);
	C=R;
}
Arbre::~Arbre() {
//	delete R;
//	delete C;
	std::cout<<"free\n";
}

Node * Arbre::mkNode(string &s) {
	Node *n = new Node(s);
	string h = ".";
	n->fg = new Node(h);
	h="..";
	n->fg->fd=new Node(h);
	return n;
}
void Arbre::mkdir(string &s) {
	if(ft_strcmp(s,"/")==0 || ft_strcmp(s,"")==0 || s[0] == '/') return;
	Node *p = mkNode(s);
	Node *a = C->fg;
	p->fd=a;
	C->fg=p;
	p->pere=C;
}

string pathbuilder(Node * N, string &p) {
	if(N->pere && ! (N->pere->name[0] == '/')) pathbuilder(N->pere, p);
	if(! (N->name[0] == '/')) p+="/";
	p+=N->name;
	return p;
}

string Arbre::fullpath() {
	string p;
	pathbuilder(C, p);
	return p;
}

bool Arbre::hasdir(string &s) {
	Node * N = C;
	if(C->fg) N=C->fg;
	while(N->fd) {
		//std::cout << N->name << " ";
		if(ft_strcmp(N->name ,s)==0) return true;
		 N=N->fd;
	}
	return false;
}

void Arbre::rmkdir(string &s) {
	if(ft_strcmp(s,"/")==0 || ft_strcmp(s,"")==0) return;
	string opath=fullpath();
	string * spath;
	Node * n;
	int spc = 0;
	string r = "/";
	//std::cout << s << "\n\n";
	spath = ft_strtok(s, "/");
	if(s[0]=='/') {
		cd(r);
		spc++;
		/*std::cout << pwd() << '\n';
		if(hasdir(spath[spc])) {
			std::cout << "hasdir " << spath[spc];
			cd(spath[spc]);
		} else {
			mkdir(spath[spc]);
			cd(spath[spc]);
			std::cout << "mkdir " << spath[spc];
		}
		spc++;*/
	}
	while(spath[spc][0]) {
		//std::cout << spath[spc] << " " << pwd() << " " << spc << '\n';
		if (ft_strcmp(spath[spc],".") == 0) spc++;
		if (ft_strcmp(spath[spc],"..") == 0) {
			cd(spath[spc]);
		} else {
			if(hasdir(spath[spc])) {
				//std::cout << "hasdir " << spath[spc];
				cd(spath[spc]);
			} else {
				mkdir(spath[spc]);
				std::cout << "[ + ] " << spath[spc] << '\n';
				cd(spath[spc]);
			}
		}
		spc++;
	}
	cd(opath);
}

void Arbre::cins(string &n) {
	if(ft_strcmp(n,"/")==0 || ft_strcmp(n,"")==0 || n[0] == '/') return;
	Node *X = mkNode(ft_strtok(n, "/")[0]);
	insert(X,C);
}
void Arbre::rins(string &s) {
	if(ft_strcmp(s,"/")==0 || ft_strcmp(s,"")==0 || s[0] == '/') return;
	Node *X = mkNode(ft_strtok(s, "/")[0]);
	insert(X,R);
}
void Arbre::insert(Node * X, Node * N) {
	if (!X || !N) return;
	if (hasdir(X->name)) return;
	if (N->fg) {
		X->fd=N->fg;
	}
	N->fg=X;
	X->pere=N;

	/*
	if (N->fg) {
		N=N->fg;
		while(N->fd) N=N->fd;
		N->fd=X;
	}
	while(N->fg) N=N->fg
	N->fg=X;
	*/
}
void Arbre::cd(string &s) {
	string * spath;
	Node * n;
	int spc = 0;
	spath = ft_strtok(s, "/");
	while(spath[spc][0]) {
		if(spc == 0 && spath[spc][0]=='/' && spath[spc][1] == '\0'){
			//spc++;
			C=R;
		}
		if(spath[spc][0]=='.') {
			if (spath[spc][1]=='.' /*&& spath[spc][2] == '\0'*/) {
				if (C->pere) C=C->pere;
				//std::cout << spath[spc] << " " << C->name << '\n';
				spc++;
			} else {
				spc++;
			}
		} else {
			n=C->fg;
			while(n!=NULL) {
				//std::cout << spath[spc] << " " << n->name << " " << ft_strcmp(n->name,spath[spc]) << '\n';
				if(ft_strcmp(n->name,spath[spc])==0) break;
				n=n->fd;
			}
			if(n) C=n;
			spc++;
		}

		//std::cout << spath[spc] << " " << C->name << '\n';
		//spc++;
	}
}

/*

Node * n;
if(s=="..") {
	C=C->pere;
	return;
}
n=C->fg;
while(n!=NULL) {
	if(n->name==s) break;
	n=n->fd;
}
if(n) C=n;


*/

void Suppression(Node * N) {
	Node * B = N;
	if(N && N->fg && N->name[0] != '.') {
		std::cout << "[ - ] " << N->name << '\n';
		Suppression(N->fg);
		if(N->fd && N->fd->name[0] != '.') {
			Suppression(N->fd);
		}
		N->fg=NULL;
		if(N->fd && N->fd->name[0] != '.') N->fd=NULL;
	}
	if(B->fg && B->fg->name[0] != '.') B->fg=NULL;
	//N=N->pere;
	//N->fg = NULL;
}

void Arbre::clean() {
	Suppression(C);
	string h = ".";
	C->fg = new Node(h);
	h="..";
	C->fg->fd=new Node(h);
}

void aprint(Node * N, int sp) {
	int spc = sp;
	//bool last = false;
	if(N) {
		while(spc>0) {
			//last = (N->fg && N->fg->name[0] == '.')?true:false;
			//if (N->fg) std::cout << N->fg->name << " ";
			//if (N->fd) std::cout << N->fd->name << " ";
			//if (N->fd && N->fd->name[1] == '.' && spc+1==sp) std::cout << "_";
			//std::cout << "-";
			//std::cout << spc << sp <<"-";
			if(N->name[0] != '.') (spc==1)?(((!N->fg && !N->fd) || (N->fd->name[0] == '.'))?(std::cout<<"└ "):(std::cout<<"├ ")):(false)?(std::cout<<"│ "):(std::cout<<"  ");
			//(spc==1)?((!N->fg && !N->fd)?(std::cout<<"└ "):(std::cout<<"├ ")):(std::cout<<"│ ");
			//std::cout << spc << sp << "-";
			spc--;
		}
		//std::cout<<N->name<<"\n";
		if(N->name[0] != '.') std::cout<<N->name<<"\n";
		aprint(N->fg, sp+1);
		if(sp>0) aprint(N->fd, sp);
	}
}
string Arbre::pwd() {
	return C->name;
}

bool afind(Node * N, string n) {
	return (N)?((N->name==n || afind(N->fg,n) || afind(N->fd,n))?(true):(false)):(false);
}

bool Arbre::find(string n) {
	return afind(C,n);
}

void Arbre::print() {
	aprint(R, 0);
}

void Arbre::cprint() {
	aprint(C, 0);
}

string getline() {
	string S;
	//std::cout << "... ";
	std::cin >> S;
	return S;
}

void help() {
	std::cout << "Arbre Commander\n";
	std::cout << "----------------\n";
	std::cout << "\nAvaible commands:\n";
	std::cout << "\texit\t\texit the commander\n";
	std::cout << "\tmkdir\t...\tcreate a new directory\n";
	std::cout << "\tcd\t...\tchange working directory\n";
	std::cout << "\tpwd\t\tprints working directory\n";
	std::cout << "\tls\t\tlists sub-directories\n";
	std::cout << "\ttree\t\tprints the whole Arbre\n";
	std::cout << "\tfind\t...\tsearches for a directory\n";
	std::cout << "\thelp\t\tprints this message\n";
	std::cout << "\tmkroot\t...\tcreate a root directory\n";
	std::cout << "\tclean\t...\tdeletes directories from the current working\n";
	std::cout << "\tfp\t\tget full path of the current working directory";
	std::cout << "\n (...) mean that the function needs arguments which have to be input after the function or in a newline.\n";


}

string sh(int &F) {
	string S;
	std::cout << "> ";
	std::cin >> S;
	if(ft_strcmp("exit",S)==0) F=1;
	if(ft_strcmp("mkdir",S)==0) {
		F=2;
		return getline();
	}
	if(ft_strcmp("cd",S)==0) {
		F=3;
		return getline();
	}
	if(ft_strcmp("pwd",S)==0) F=4;
	if(ft_strcmp("ls",S)==0) F=5;
	if(ft_strcmp("tree",S)==0) F=6;
	if(ft_strcmp("find",S)==0) {
		F=7;
		return getline();
	}
	if(ft_strcmp("help",S)==0) F=8;
	if(ft_strcmp("mkroot",S)==0) {
		F=9;
		return getline();
	}
	if(ft_strcmp("hasdir",S)==0) {
		F=10;
		return getline();
	}
	if(ft_strcmp("clean",S)==0) F=11;
	if(ft_strcmp("fp",S)==0) F=12;

	return S;
}


int main() {
	int Function;
	string * tpath;
	Arbre A;
	string r;
	//A.print();
	string h = "plop";
	A.mkdir(h);
	A.cd(h);
	//std::cout<<A.pwd()<<'\n';
	h="a0";
	A.mkdir(h);
	h="a1";
	A.mkdir(h);
	h="a2";
	A.mkdir(h);
	A.cd(h);
	//std::cout<<A.pwd() << " is here a2 "<<'\n';
	//std::cout<<A.pwd()<<'\n';
	h="a20";
	A.mkdir(h);
	h="cins0";
	A.cins(h);
	h="../a2/a20/";
	A.cd(h);
	//std::cout<<A.pwd() << " is here a20 "<<'\n';
	h="cins1";
	A.cins(h);
	A.cd(h);
	//std::cout<<A.pwd() << " is here cins1 "<<'\n';
	h="c0";
	A.mkdir(h);
	h="c1";
	A.mkdir(h);
	h="c2";
	A.mkdir(h);
	h = "/plop/a2/cins0/";
	A.cd(h);
	//std::cout<<A.pwd() << " is here cins0 "<<'\n';
	h="d0";
	A.mkdir(h);
	h="d1";
	A.mkdir(h);
	h="d2";
	A.mkdir(h);

	h = "/plop/a1/";
	A.cd(h);
	//std::cout<<A.pwd() << " is here a1 "<<'\n';
	h="e0";
	A.mkdir(h);
	h="e1";
	A.mkdir(h);
	h="e2";
	A.mkdir(h);

	h="rins0";
	A.rins(h);

	h = "/rins0";
	A.cd(h);
	//std::cout<<A.pwd() << " is here rins0 "<<'\n';
	h="f0";
	A.mkdir(h);
	h="f1";
	A.mkdir(h);
	h="f2";
	A.mkdir(h);
	//std::cout << A.hasdir(h) << " ze "<< '\n';
	//A.print();
	//std::cout << A.find("plop") << '\n';
	//std::cout << A.pwd() << '\n';
	//h="     	 /// m n  t ///  sd c a r d //  //  // D o  wn  l o a d / / / T P 3///ts   t////  / / //   / a a a// / / // A/";
	//std::cout << cpstring(h) << "\n";
	//h="/mnt/sdcard/Download/TP3/tst/aaa/A/";
	//tpath = ft_strtok(h,"/");
	//std::cout << tpath[0] << " " << tpath[1] << " " << tpath[2] << " " << tpath[3] << '\n';
	h = "/myfile";
	ft_strtok(h, "/");
	h = "/plop/a0";
	A.cd(h);
	//std::cout<<A.pwd() << " now here a0"<<'\n';
	h="b1";
	A.mkdir(h);
	//A.print();
	//std::cout << A.hasdir(h) << " ze "<< '\n';
	h="../a1";
	//std::cout << "======" << '\n';
	A.cd(h);
	//std::cout << A.fullpath() << '\n';
	h = "e2/smd1/anthd1/stuff";
	A.rmkdir(h);
	h = "../a2/cins0/blip/bloup";
	A.rmkdir(h);
	h = "/plop/a0/a30/bruh/bo";
	A.rmkdir(h);
	h = "/plop/a0/a30/bruklin/bro";
	A.rmkdir(h);
	h = "/rins0/f1/tropiko";
	A.rmkdir(h);
	h = "/plop/a0/a30/brumizator/brocher";
	A.rmkdir(h);
	//std::cout << A.fullpath() << '\n';
	//A.print();
	h = "/plop";
	A.cd(h);
	h = "brumeu/brokoli";
	A.rmkdir(h);
	h = "bruyan/brokant";
	A.rmkdir(h);
	//A.print();
	//std::cout << 	ft_strcmp("plopp","ploppp");
	//std::cout <<A.pwd();

	help();
	std::cout << "\n";
	bool inwhile = true;
	while (inwhile) {
		r = sh(Function);
		switch(Function) {
			case 1:
				inwhile=false;
				break;
			case 2:
				A.rmkdir(r);
				break;
			case 3:
				A.cd(r);
				break;
			case 4:
				std::cout << A.pwd() << "\n";
				break;
			case 5:
				A.cprint();
				break;
			case 6:
				A.print();
				break;
			case 7:
				std::cout << "The directory " << r << " is ";
				(A.find(r))?(std::cout << "present\n"):(std::cout << "absent\n");
				break;
			case 8:
				help();
				break;
			case 9:
				A.rins(r);
				break;
			case 10:
				std::cout << r << " has ";
				(A.hasdir(r))?(std::cout << "present\n"):(std::cout << "absent\n");
				break;
			case 11:
				A.clean();
				break;
			case 12:
				std::cout << A.fullpath() << '\n';
				break;
			default:
				std::cout << "Unknown command " << r << ". Try 'help' for more details\n";
				break;
		}
		Function = 0;
		//std::cout<<r<<"\n";
		//if(Function==1) inwhile=false;
	}


	return 0;
}