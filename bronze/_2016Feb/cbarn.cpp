#include <bits/stdc++.h>
using namespace std;

int collectiveDistance(int cow, const vector<int>& cowsToGo){
	int cD = 0;
	for(int i = 0;i<cowsToGo.size();i++){
		if(i < cow){
			cD += cowsToGo[i] * (cowsToGo.size() - cow + i);	
		}
		else {
			cD += cowsToGo[i] * (i - cow);	
		}
	}
	return cD;
}

int main(){
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);

	int n;
	cin >> n;

	vector<int> cowsToGo;
	for(int i = 0;i<n;i++){
		int c;
		cin >> c;
		cowsToGo.push_back(c);
	}

	int min = 10000001;
	for(int i = 0;i<n;i++){
		int cD = collectiveDistance(i, cowsToGo);
		//cout << "distance by " << i << ": " << cD << endl;
		if(cD < min) min = cD;
	}
	cout << min << endl;

}
