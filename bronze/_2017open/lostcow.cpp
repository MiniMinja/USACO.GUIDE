#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);

	int x, y;
	cin >> x >> y;
	int pos = x;
	int factor = 1;
	int destination = x+1;
	int distance = 0;
	while(pos != y){
		//cout << "pos: " << pos << " " << " destination: " << destination << " distance traveled: " << distance << endl;
		if(destination > pos){
			pos += 1;
			distance++;
		}
		else if(destination < pos){
			pos -= 1;
			distance++;
		}
		else{
			factor*= -2;
			destination = x + factor;
			if(destination < 0 || destination > 1000){
				factor *= -2;
				destination = x + factor;
			}
		}
	}
	cout << distance << endl;
}
