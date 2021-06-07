#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);

	int X, Y, M;
	cin >> X >> Y >> M;

	int min_diff = 1001;
	int max_fill = -1;
	for(int i = 0;i<=1000;i++){
		for(int j = 0;j<=1000;j++){
			if(X * i + Y * j <= M){
				if(M - (X * i + Y * j) < min_diff){
					min_diff = M - (X * i + Y * j);
					max_fill = X * i + Y * j;
				}
			}
		}
	}
	cout << max_fill << endl;
}
