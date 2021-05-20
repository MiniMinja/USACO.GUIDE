#include <bits/stdc++.h>

using namespace std;

void unshuffle(const vector<int>& cows, vector<int>& ids){
	vector<int> prev(ids.size());
	int lastPos = 1;
	for(auto newPos : cows){
		prev[lastPos-1] = ids[newPos-1];
		lastPos++;	
	}
	for(int i = 0;i<ids.size();i++){
		ids[i] = prev[i];
	}
}

int main(){
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	int N;
	cin >> N;
	vector<int> cows;
	cows.reserve(N);
	for(int i = 0;i<N;i++){
		int pos;
		cin >> pos;
		cows.push_back(pos);
	}
	vector<int> ids;
	cows.reserve(N);
	for(int i = 0;i<N;i++){
		int id;
		cin >> id;
		ids.push_back(id);
	}
	for(int i = 0;i<3;i++){
		unshuffle(cows, ids);
	}
	for(auto id: ids){
		cout << id << endl;
	}
	
}
