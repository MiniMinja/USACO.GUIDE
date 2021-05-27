#include <bits/stdc++.h>

using namespace std;

struct timestamp{
	int t;
	int x, y;

	timestamp(int t, int x, int y){
		this->t = t;
		this->x = x;
		this->y = y;
	}

	int matchesCoor(int x, int y){
		return this->x == x && this->y == y;
	}

	void printCoor(){
		cout << "t: " << this->t << " x: " << this->x;
		cout << " y: " << this->y << endl;
	}
};

int main(){
	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);

	int N;
	cin >> N;

	vector<timestamp> times;
	int t = 0;
	int currX = 0, currY = 0;
	int smallestDt = 1002;
	int repeatedCell = 0;
	for(int i = 0;i<N;i++){
		char dir;
		cin >> dir;
		int steps;
		cin >> steps;
		for(int j =0;j<steps;j++){
			if(dir == 'N'){
				currY++;
			}else if(dir == 'W'){
				currX--;
			}
			else if(dir == 'E'){
				currX++;
			}
			else{
				currY--;
			}
			t++;
			for(auto time: times){
				if(time.matchesCoor(currX, currY)){
					int dt = t - time.t;
					//cout << "Found Match!" << endl;
					//cout << "Overlap at " << t + 1 << endl;
					smallestDt = min(dt, smallestDt);
					repeatedCell = 1;
				}
			}
			timestamp currTime(t, currX, currY);
			times.push_back(currTime);
			//cout << "Moved to: ";
			//currTime.printCoor();
		}
	}
	if(!repeatedCell) cout << -1 << endl;
	else cout << smallestDt << endl;
}
