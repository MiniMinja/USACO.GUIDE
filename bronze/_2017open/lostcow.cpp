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
	int furthestLeft = x;
	int furthestRight = x;
	while(pos != y){
		//cout << "pos: " << pos << " " << " destination: " << destination << " distance traveled: " << distance << endl;
		if(destination > pos){
			if(pos < 1000){
				pos += 1;
				distance++;
				furthestRight = max(furthestRight, pos);
			}
			else{
				factor *=-2;
				destination = x + factor;
				if(furthestLeft == 0 && destination < furthestLeft) {
					factor *= -2;
					destination = x + factor;
				}
			}
		}
		else if(destination < pos){
			if(pos > 0){
				pos -= 1;
				distance++;
				furthestLeft = min(furthestLeft, pos);
			}
			else {
				factor *=-2;
				destination = x + factor;
				if(furthestRight == 1000 && destination > furthestRight){
					factor *= -2;
					destination = x + factor;
				}
			}
		}
		else{
			factor*= -2;
			destination = x + factor;
		}
	}
	cout << distance << endl;
}
