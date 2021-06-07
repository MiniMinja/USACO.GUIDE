#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	int N, K;
	cin >> N >> K;
	vector<int> sizes;
	for(int i = 0;i<N;i++){
		int s;
		cin >> s;
		sizes.push_back(s);
	}

	sort(sizes.begin(), sizes.end());

	int max_count = -1;
	for(int i = 0;i<N;i++){
		int small = sizes[i];
		int limit_index = i;
		int count = 1;
		int diff = 0;
		for(int j = i+1;j<N;j++){
			if(sizes[j] - small <= K){
				limit_index = j;
				count++;
				diff = sizes[j] - small;
			}
			else{
				break;
			}
		}
		if(count > max_count){
			max_count = count;
		}
	}
	cout << max_count << endl;
}
