#pragma once;
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class tdata {
public:
	int w;
	char p;
	tdata* parent;
	tdata* r;
	tdata* l;
	tdata() {
		w = 0;
		parent = NULL;
		r = NULL;
		l = NULL;
		p = '0';
	}
};
class htree {
	tdata* a;
	int n;
	int v;
public:
	htree(int, int[], char[]);
	tdata* create();
};
void show(tdata*,string);
void find(tdata*,char);
string deco(string,tdata*);