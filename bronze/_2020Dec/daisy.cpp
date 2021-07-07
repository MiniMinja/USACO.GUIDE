#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> petals;
	for(int i =0;i<N;i++){
		int a;
		cin >> a;
		petals.push_back(a);
	}
	int p = 0;
	for(int i = 0;i<N-1;i++){
		for(int j = i+1;j<N;j++){
			int sum = 0;
			for(int index = i;index<=j;index++){
				sum += petals[index];
			}
			if(sum % N == 0){
				int avg = sum/N;
				for(int index = i;index<=j;index++){
					if(petals[index] == avg){
						p++;
					}
				}
			}
		}
	}
	cout << p + N << endl;
}
