#include <bits/stdc++.h>

using namespace std;

void swap(array<int, 4>& pebbles, int a, int b){
	int temp = pebbles[a];
	pebbles[a] = pebbles[b];
	pebbles[b] = temp;
}

void printPebbles(const array<int, 4>& pebbles){
	for(int i = 1;i<=3;i++)
		cout << pebbles[i] << " ";
	cout << endl;
}

int main(){
	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);

	int N;
	cin >> N;

	array pebblesAt {0, 1, 2, 3};
	array pebbleScore {0, 0, 0, 0};
	for(int i = 0;i<N;i++){
		int a, b, g;
		cin >> a >> b >> g;
		swap(pebblesAt, a, b);
		pebbleScore[pebblesAt[g]]++;
	}
	int max = -1;
	for(int i = 1;i<=3;i++)
		if(pebbleScore[i] > max)
			max = pebbleScore[i];
	cout << max << endl;
}

