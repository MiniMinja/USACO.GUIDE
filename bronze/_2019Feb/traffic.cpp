#include <bits/stdc++.h>

using namespace std;

struct segment{
	string ramp;
	int low, high;
};

vector<int> getFinalRange(int speed, const vector<segment>& road){
	int speedLow = speed;
	int speedHigh = speed;
	vector<int> retSpeed = {-1, -1};
	string output = "entering speed is: " + to_string(speed) + "\n";
	for(auto s: road){
		output.append("road: ").append(s.ramp).append(" low: ").append(to_string(s.low)).append(" high: ").append(to_string(s.high));
		output.append("\n");
		output.append("Speed is: ").append(to_string(speedLow)).append(" ").append(to_string(speedHigh));
		output.append("\n");
		if(s.ramp.compare("on") == 0){
			speedLow += s.low;
			speedHigh += s.high;
		}
		else if(s.ramp.compare("off") == 0){
			speedLow=max(0, speedLow - s.high);
			speedHigh=max(0, speedHigh - s.low);
		}
		else{
			if(	(speedLow <= s.low && s.low <= speedHigh) ||
				(speedLow <= s.high && s.high <= speedHigh) ||
				(s.low <= speedLow && speedLow <= s.high) || 
				(s.low <= speedHigh && speedHigh <= s.high)){
				speedLow = max(speedLow, s.low);
				speedHigh = min(speedHigh, s.high);
			}
			else{
				return retSpeed;
			}
		}
		output.append("after segment: ").append(to_string(speedLow)).append(" ").append(to_string(speedHigh));
		output.append("\n");
	}
	retSpeed[0] = speedLow;
	retSpeed[1] = speedHigh;
	//cout << output;
	return retSpeed;
}

void printRoad(const vector<segment>& road){
	for(auto s: road){
		cout << "segment: " << s.ramp;
		cout << " low: " << s.low << " high: " << s.high << endl;
	}
	cout << endl;
}

int main(){
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);

	int N;
	cin >> N;	

	vector<segment> road;
	for(int i = 0;i<N;i++){
		road.push_back(segment());
		cin >> road[road.size()-1].ramp >> road[road.size()-1].low >> road[road.size()-1].high;
	}
	//printRoad(road);
	int low = 1000;
	int high = 1;
	int lowF = 1000;
	int highF = 1;
	for(int trySpeed = 0;trySpeed <= 1000;trySpeed++){
		vector<int> speedAttempt = getFinalRange(trySpeed, road);
		if(speedAttempt[0] != -1){
			low = min(trySpeed, low);
			high = max(trySpeed, high);
			lowF = min(speedAttempt[0], lowF);
			highF = max(speedAttempt[1], highF);	
		}
	}
	cout << low << " " << high << endl;
	cout << lowF << " " << highF << endl;
}
