#include <bits/stdc++.h>
using namespace std;

void reset(array<int, 26>& letters){
	for(int i =0;i<26;i++){
		letters[i] = 0;
	}
}

int main(){
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);

	int N;
	cin >> N;

	vector<string> side1;
	vector<string> side2;
	for(int i =0 ;i<N;i++){
		string s1, s2;
		cin >> s1 >> s2;
		side1.push_back(s1);
		side2.push_back(s2);
	}

	array<int, 26> lettersF {0};

	array<int, 26> letters1;
	array<int, 26> letters2;
	for(int i = 0;i<N;i++){
		reset(letters1);
		reset(letters2);
		string word1 = side1[i];
		string word2 = side2[i];
		for(char c: word1){
			letters1[c-'a']++;
		}
		for(char c: word2){
			letters2[c-'a']++;
		}
		for(int i = 0;i<26;i++){
			//cout << (char)('a'+i) << " " << letters1[i] << " " << letters2[i] << endl;
			lettersF[i] += max(letters1[i], letters2[i]);
		}
	}
	for(int i = 0;i<26;i++){
		cout << lettersF[i] << endl;
	}
}
