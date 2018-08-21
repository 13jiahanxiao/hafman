#include"htree.h"
htree::htree(int m, int b[], char c[]) {
	n = m;
	v = 2 * n - 1;
	a = new tdata[v];
	int i = 0;
	for (i = 0; i < n; i++) {
		a[i].w = b[i];
		a[i].p = c[i];
	}
}
tdata* htree::create() {
	int i, j;
	int tw;
	char pw;
	for (j = 0; j < n; j++) {
		for (i = 0; i < n-1; i++) {
			if (a[i].w > a[i + 1].w) {
				tw = a[i].w;
				pw = a[i].p;
				a[i].w = a[i + 1].w;
				a[i].p = a[i + 1].p;
				a[i + 1].w = tw;
				a[i + 1].p = pw;
			}
		}
	}
	a[n ].l = &a[0];
	a[n ].r = &a[1];
	a[n ].parent = &a[n + 1];
	a[n].w = a[0].w + a[1].w;
	a[1].parent = &a[n];
	a[0].parent = &a[n];
	for (i = n + 1, j = 2; i < v-1; i++, j++) {
		a[i].l = &a[i - 1];
		a[i].r = &a[j];
		a[j].parent = &a[i];
		a[i].w = a[i - 1].w + a[j].w;
		a[i].parent = &a[i + 1];
	}
	a[v - 1].l = &a[v-2];
	a[v - 1].r = &a[n - 1];
	a[n - 1].parent = &a[v - 1];
	a[v - 1].w = a[v - 2].w + a[n - 1].w;
	return &a[v - 1];
}
void show(tdata*y,string ss) {
	if (y == NULL)
		return;
	ss += "    ";
	show(y->r, ss);
	cout<<ss << y->w << endl;
	show(y->l,ss);
}
void find(tdata*y,char x) {
	if (y->p != 0)
		if (y->p == x) {
			ofstream outfile("codefile.txt", ios_base::out | ios_base::app);
			while (y->parent != NULL) {

				if (y->parent->l->w == y->w)
					outfile <<	'0';
				if (y->parent->r->w == y->w) 
					outfile << '1';
				y = y->parent;
			}
			outfile.close();
			return;
		}
	if (y->l != NULL) {
		find(y->l,x);
	}
	if (y->r != NULL) {
		find(y->r, x);
	}
}
string deco(string s,tdata* y) {
	int i = 0;
	string l;
	char te;
	tdata*x = y;
	while (i < s.length()) {
		if (s[i] == '0') {
			x=x->l;
		}
		else x = x->r;
		if (x->p != '0') {
			te= x->p;
			l += te;
			x = y;
		}
		i++;
	}
	return l;
}