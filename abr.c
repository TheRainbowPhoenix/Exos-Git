#include "abr.h"
#include <iostream>

using namespace std;
node::node(int k) {
	key=k;
	fg=fd=pere=NULL;
}

void node::print() {
	if(fg) {
		fg->print();
		cout<<"<";
	}
	cout<<key;
	if(fd) {
		cout<<">";
		fd->print();
	}
	cout<<" ";
}

void node::add(int k) {
	if(k<key) {
		if (fg) fg->add(k);
		else {
			fg=new node(k);
			fg->pere=this;
		}
	} else {
		if(fd) fd->add(k);
		else {
			fd=new node(k);
			fd->pere=this;
		}
	}
}

bool node::search(int k) {
	if(k==key) return true;
	if(k<key) {
		if(fg) return(fg->search(k));
		else {
			return false;
		}
	} else {
		if(fd) return(fd->search(k));
		else {
			return false;
		}
	}
}

node * node::min() {
	if(fg) return fg->min();
	else return this;
}

node * node::max() {
	if(fd) return fd->max();
	else return this;
}

int node::get() {
	return key;
}

int node::height()
{
	int ng;
	if(fg) ng=fg->height();
	else ng=0;
	int nd;
	if(fd) nd=fd->height();
	else nd=0;
	if(ng>nd) return(ng+1);
	else return(nd+1);

}

void arbre::rm(node * n) {
	if (n->fg==NULL && n->fd==NULL) {
		if(n->pere) {
			if(n->pere->get() > n->get()) {
				n->pere->fg=NULL;
				n->pere=NULL;
			} else {
				cout << "<n "<<endl;
				n->pere->fd=NULL;
			}
			n->pere=NULL;
		} else {
			r=NULL;
		}
		return;
	} else {
		if(n->pere) {
			if(n->pere->get() > n->get()) {
				if(n->fd) {
					node * m = n->fd->min();
					if (n->fg) {
						m->fg=n->fg;
						n->fg->pere=m;
						n->fg=NULL;
					}
					n->fd->pere=n->pere;
					n->pere->fg=n->fd;
					n->fd=NULL;
					n->pere=NULL;
				} else if (n->fg) { 
					n->pere->fg=n->fg;
					n->fg->pere=n->pere;
					n->pere=NULL;
					n->fg=NULL;
				} else {
					n->pere->fg=NULL;
					n->pere=NULL;
				}
			} else {
				if (n->fd) {
					node * m = n->fd->min();
					if (n->fg) {
						m->fg=n->fg;
						n->fg->pere=m;
						n->fg=NULL;	
					}
					//n->fg->pere=m->fg;
					n->fd->pere=n->pere;
					n->pere->fd=n->fd;
					n->fd=NULL;
					n->pere=NULL;
				} else {
					n->pere->fd=n->fg;
					n->fg->pere=n->pere;
					n->pere=NULL;
					n->fg=NULL;
				}
			}
			return;
		} else {
			if (n->fd) {	
				node * m = n->fd->min();
				if (n->fg) {
					m->fg=n->fg;
					n->fg->pere=m;
					n->fg=NULL;
				}
				n->fd->pere=NULL;
				r=n->fd;
				n->fd=NULL;
				return;
			} else if (n->fg) {
				n->fg->pere=NULL;
				r=n->fg;
				n->fg=NULL;
			} else {
				n->pere=NULL;
				r=NULL;
			}
			return;
		}
	return;
	}
}

void node::rm(int n) {
	if (n>key) {
		if (fg) fg->rm(n);
		else return;
	} else if (n<key) {
		if(fd) fd->rm(n);
		else return;
	} else {
		if (fg) {
			if (fd) {
				if (pere) {
					return;

				} else {
					return;
				}

				/* TODO : Multiple add */
				return;
			} else {
				if (pere) {
					if (pere->get() > n) {
						fd->pere=pere;
						pere->fg=fd;
						fd->fg=fg;
						fg->pere=fd;
					} else {
						return;
					}
				} else {
					return;
				}
			}



		} else {
			if (fd) {
				if (pere) {
					if (pere->get() > n) {
						pere->fg=fd;
						return;
					} else {
						pere->fd=fd;
						return;
					}
				} else {
					fd->pere=NULL;
					return;
				}

			} else {
				if (pere) {
					if(pere->get() > n) {
						pere->fg=NULL;
						return;
					} else {
						pere->fd=NULL;
						return;
					}
				} else {
					return;
				}

			}
		}
	}
}

int arbre::height()
{
	if(r==NULL) return 0;
	return(r->height());
}

node * arbre::min() {
	if(r) return r->min();
	else return NULL;
}

node * arbre::max() {
	if(r) return r->max();
	else return NULL;
}

void arbre::print() {
	if(r) r->print();
	else cout<<"Empty.";
	cout<<endl;
}


arbre::arbre() {
	r=NULL;
}

bool arbre::search(int k) {
	if(r) return r->search(k);
	else return false;
}

node * arbre::searchp(int n)
{
	if(r) return(r->searchp(n));
	else return(NULL);
}

node * node::searchp(int n)
{
	if(n==key) return this;
	if(n<key)
	{
		if(fg) return(fg->searchp(n));
		else
		{
			return NULL;	
		}
	}
	else
	{
		if(fd) return(fd->searchp(n));
		else
		{
			return NULL;
		}
	}		
}

node *node::succ()
{
	if(fd) return(fd->min());
	node *y=pere;
	node *x=this;
	while(y and y->fd==x)
	{
		x=y;
		y=y->pere;
	}
	return y;
}

node *arbre::succ(int k)
{
	node *n=searchp(k);
	cout<<"##############"<<endl;
	cout<<n->get()<<endl;
	cout<<"##############"<<endl;
	return(n->succ());

}

void arbre::add(int k) {
	if(r) r->add(k);
	else {
		r=new node(k);
	}
}

int main() {
	int k;
	arbre A;
	k=4;
	A.add(k);
	k=6;
	A.add(k);
	k=2;
	A.add(k);
	k=5;
	A.add(k);
	k=12;
	A.add(k);
	A.add(1);
	A.add(-4);
	A.add(3);
	A.add(11);
	A.print();
	cout << A.search(k) << endl;
	cout << A.min()->get() << endl;
	cout << A.max()->get() << endl;
	cout << A.succ(5)->get()<<endl;
	cout << A.height()<<endl;
	A.rm(A.searchp(5));
	A.print();
	A.rm(A.searchp(6));
	A.print();
	A.rm(A.searchp(12));
	A.print();
	A.rm(A.searchp(2));
	A.print();
	A.rm(A.searchp(4));
	A.print();
	A.rm(A.searchp(1));
	A.print();
	A.rm(A.searchp(11));
	//cout << "noticeMe >o<"<<endl;
	A.print();
	//A.rm(A.searchp(3));
	A.rm(A.searchp(3));
	A.print();
	A.rm(A.searchp(-4));
	A.print();
	A.add(66);
	A.add(50);
	A.add(71);
	A.add(37);
	A.add(56);
	A.add(70);
	A.add(81);
	A.add(36);
	A.add(44);
	A.add(55);
	A.add(68);
	A.add(80);
	A.add(97);
	A.add(35);
	A.add(52);
	A.add(67);
	A.add(69);
	A.add(94);
	A.add(51);
	A.add(88);
	A.print();
	//A.rm(A.searchp(51));
	//A.rm(A.searchp(55));
	A.rm(A.searchp(71));
	/*
	A.add(5);
	A.add(4);
	A.add(2);
	A.add(6);
	A.add(12);
	A.add(1);
	A.add(11);
	A.add(3);
	A.add(-4);
	*/
	A.print();
}
