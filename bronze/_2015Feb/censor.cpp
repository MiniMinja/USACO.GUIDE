#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);

	string s;
	cin >> s;
	string t;
	cin >> t;
	
	string r;
	for(int i = 0;i<s.length();i++){
		r.push_back(s[i]);
		if(r.length() > t.length()){
			int matches = 1;
			for(int j = 0;j<t.length();j++){
				if(r[r.length()-j-1] != t[t.length()-j-1]){
					matches = 0;
					break;
				}
			}
			if(matches){
				r.erase(r.length()-t.length(), t.length());
			}
		}
	}

	cout << r << endl;
}
