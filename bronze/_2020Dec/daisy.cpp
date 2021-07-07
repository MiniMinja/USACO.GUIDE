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
			//cout << "Pair: " << i << " " << j << endl;
			int sum = 0;
			for(int index = i;index<=j;index++){
				sum += petals[index];
			}
			//cout << "sum is: " << sum << endl;
			if(sum % (j - i + 1) == 0){
				int avg = sum/(j - i + 1);
				//cout << "avg is: " << avg << endl;
				for(int index = i;index<=j;index++){
					if(petals[index] == avg){
						p++;
						break;
					}
				}
			}
			//cout << endl;
		}
	}
	cout << p + N << endl;
}
