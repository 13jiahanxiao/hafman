#include"htree.h"
int main() {
	int c = 0, c1 = 0;
	int i;
	int a[27] = { 0 };
	char b[27] = { 0 };
	ifstream infile("htree.txt");
	for (i = 0; i < 27; i++) {
		infile >> a[i];
	}
	for (i = 0; i < 27; i++) {
		infile.get(b[i]);
	}
	infile.close();
	htree f(27, a, b);
	tdata* h = f.create();
	while (c != 5) {
		cout << "*请选择功能*" << endl
			<< "1.编码" << endl
			<< "2.译码" << endl
			<< "3.打印编码" << endl
			<< "4.打印哈夫曼树" << endl
			<< "5.退出" << endl;
		cin >> c;
		if (c < 1 || c>5) {
			cout << "请选择功能1-5" << endl;
			continue;
		}
		switch (c) {
		case 1: {
			int p = 0;
			string j;
			char k;
			infile.open("tobetran.txt");
			infile.get(k);
			while (k != '\n') {
				j += k;
				infile.get(k);
			}
			infile.close();
			p = 0;
			ofstream outfile("codefile.txt");
			outfile.close();
			while (j[p] != '\0') {
				find(h, j[p]);
				p++;
			}
			cout << "编码已保存到文件中" << endl;
			break;
		}
		case 2: {
			infile.open("codefile.txt");
			infile.seekg(0, ios::beg);
			string s;
			char temp;
			int u = 0;
			infile >> s;
			int len = s.length();
			for (i = 0, u = len - 1; i < u; i++, u--) {
				temp = s[i];
				s[i] = s[u];
				s[u] = temp;
			}
			string l = deco(s, h);
			len = l.length();
			for (i = 0, u = len - 1; i < u; i++, u--) {
				temp = l[i];
				l[i] = l[u];
				l[u] = temp;
			}
			cout << l << endl;
			break;
		}
		case 3: {
			string ov;
			ifstream infile("codefile.txt");
			infile >> ov;
			infile.close();
			cout << ov << endl;
			break;
		}
		case 4: {
			string ss = "    ";
			show(h, ss);
		}
		case 5: {
			break;
		}
		default:continue;
		}
	}
		return 0;
}