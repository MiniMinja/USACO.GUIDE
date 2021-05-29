#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);

	string s;
	cin >> s;
	string t;
	cin >> t;

	bool foundT = 0;
	while(1){
		for(int i = 0;i<=s.length()-t.length();i++){
			if(s[i] == '\0') continue;
			bool currentMatch = 1;
			int sj = i;
			for(int j = 0;j<t.length();j++){
				while(s[sj] == '\0') sj++;
				if(s[sj] != t[j]){
					currentMatch = 0;
					break;
				}
				sj++;
				if(sj >= s.length()) {
					currentMatch = 0;
					break;
				}
			}
			if(currentMatch && t.length() > 0){
				for(int j = i;j<sj;j++){
					s[j] = '\0';
				}	
				foundT = 1;
			}
		}
		if(!foundT) break;
		foundT = 0;
	}

	for(int i = 0;i<s.length();i++){
		if(s[i] != '\0') cout << s[i];
	}
	cout << endl;
}
