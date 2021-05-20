#include <bits/stdc++.h>

using namespace std;

struct bucket{
	int c, m;
};

void pour(bucket &a, bucket &b){
	b.m += a.m;
	a.m = 0;
	if(b.m > b.c){
		int overflow = b.m - b.c;
		a.m = overflow;
		b.m = b.c;
	}
}

int main(){
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
	bucket b1, b2, b3;
	cin >> b1.c >> b1.m >> b2.c >> b2.m >> b3.c >> b3.m;
	for(int i = 0;i<33;i++){
		pour(b1, b2);
		pour(b2, b3);
		pour(b3, b1);
	}
	pour(b1, b2);
	cout << b1.m << endl << b2.m << endl << b3.m << endl;
}
