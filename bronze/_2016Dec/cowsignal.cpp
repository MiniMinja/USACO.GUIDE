#include <bits/stdc++.h>
using namespace std;

void scaleLine(const string& line, int K){
	for(int i = 0;i<K;i++){
		for(auto c: line){
			for(int j = 0;j<K;j++){
				cout << c;
			}
		}
		cout << endl;
	}
}

int main(){
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);
	
	int M, N, K;
	cin >> M >> N >> K;
	vector<string> signal;
	signal.reserve(M);
	for(int i = 0;i<M;i++){
		string line;
		getline(cin >> ws, line);
		signal.push_back(line);
	}
	/*
	for(auto line: signal){
		cout << line << endl;
	}
*/
	for(vector<string>::iterator it = signal.begin();it!= signal.end();it++){
		scaleLine(*it, K);
	}

}
