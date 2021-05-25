#include <bits/stdc++.h>
using namespace std;

int findSingleWins(char data[3][3]){
	int ret = 0;
	for(char c = 'A'; c<='Z'; c++){
		int canWin = 0;
		for(int i = 0;i<3;i++){
			canWin = canWin || 
				(data[i][0] == data[i][1] && 
				 data[i][1] == data[i][2] &&
				 data[i][0] == c);
			canWin = canWin ||
				(data[0][i] == data[1][i] &&
				 data[1][i] == data[2][i] &&
				 data[0][i] == c);
		}
		canWin = canWin || 
			(data[0][0] == data[1][1] &&
			 data[1][1] == data[2][2] &&
			 data[0][0] == c);
		canWin = canWin ||
			(data[0][2] == data[1][1] &&
			 data[1][1] == data[2][0] &&
			 data[0][2] == c);
		if(canWin) ret++;
	}
	return ret;
}

int findDoubleWins(char data[3][3]){
	int ret = 0;
	for(char c1 = 'A';c1<'Z';c1++){
		for(char c2 = c1+1;c2<='Z';c2++){
			if(c1 == c2){
				continue;
			}
			int canWin = 0;
			for(int i = 0;i<3;i++){
				int c1Count = 0;
				int c2Count = 0;
				for(int j =0;j<3;j++){
					if(data[i][j] == c1) c1Count++;
					if(data[i][j] == c2) c2Count++;
				}
				if(c1Count + c2Count == 3) canWin = 1;
				if(c1Count >=3) canWin = 0;
				if(c2Count >=3) canWin = 0;
				if(canWin)break;
				c1Count = 0;
				c2Count = 0;
				for(int j =0;j<3;j++){
					if(data[j][i] == c1) c1Count++;
					if(data[j][i] == c2) c2Count++;
				}
				if(c1Count + c2Count == 3) canWin = 1;
				if(c1Count >=3) canWin = 0;
				if(c2Count >=3) canWin = 0;
				if(canWin)break;
			}
			if(!canWin){
				int c1Count = 0;
				int c2Count = 0;
				for(int i = 0;i<3;i++){
					if(data[i][i] == c1)c1Count++;
					if(data[i][i] == c2)c2Count++;
				}
				if(c1Count + c2Count == 3) canWin = 1;
				if(c1Count >= 3) canWin = 0;
				if(c2Count >= 3) canWin = 0;
			}
			if(!canWin){
				int c1Count = 0;
				int c2Count = 0;
				for(int i = 0;i<3;i++){
					if(data[i][2-i] == c1) c1Count++;
					if(data[i][2-i] == c2) c2Count++;
				}
				if(c1Count + c2Count == 3) canWin = 1;
				if(c1Count >= 3) canWin = 0;
				if(c2Count >= 3) canWin = 0;
			}
			if(canWin) ret++;
		}
	}
	return ret;
}

int main(){
	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);

	string row1, row2, row3;
	cin >> row1 >> row2 >> row3;
	char data[3][3];
	data[0][0] = row1[0];
	data[0][1] = row1[1];
	data[0][2] = row1[2];
	data[1][0] = row2[0];
	data[1][1] = row2[1];
	data[1][2] = row2[2];
	data[2][0] = row3[0];
	data[2][1] = row3[1];
	data[2][2] = row3[2];
	
	int singleWins = findSingleWins(data);
	int doubleWins = findDoubleWins(data);

	cout << singleWins << endl << doubleWins << endl;
}
