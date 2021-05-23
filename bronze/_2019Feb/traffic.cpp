#include <bits/stdc++.h>

using namespace std;

struct segment{
	string ramp;
	int low, high;
};

int speedWorks(int speed, const vector<segment>& road){
	int speedLow = speed;
	int speedHigh = speed;
	for(auto s: road){
		if(s.ramp.compare("on") == 0){
			speedLow += s.low;
			speedHigh += s.high;
		}
		else if(s.ramp.compare("off") == 0){
			speedLow-=s.low;
			speedHigh-=s.high;
		}
		else{
			if(!( (s.low <= speedLow && speedLow <= s.high) ||
				(s.low <= speedHigh && speedHigh <= s.high) ||
				(speedLow <= s.low && s.low <= speedHigh) ||
				(speedLow <= s.high && s.high <= speedHigh) )){
				return 0;
			}
		}
	}
	return 1;
}

int getFinalSpeed(int speed, const vector<segment>& road, int low){
	int factor = 0;
	for(auto s: road){
		if(s.ramp.compare("on") == 0){
			if(low)
				factor+=s.low;
			else
				factor+=s.high;
		}
		else if(s.ramp.compare("off") == 0){
			if(low)
				factor-=s.high;
			else
				factor-=s.low;
		}
	}
	return speed+factor;
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
	for(int trySpeed = 1;trySpeed <= 1000;trySpeed++){
		if(speedWorks(trySpeed, road)){
			if(trySpeed < low) low = trySpeed;
			if(trySpeed > high) high = trySpeed;
			int finalSpeedLow = getFinalSpeed(trySpeed, road, 1);
			int finalSpeedHigh = getFinalSpeed(trySpeed, road, 0);
			if(finalSpeedLow < lowF) lowF = finalSpeedLow;
			if(finalSpeedHigh > highF) highF = finalSpeedHigh;
		}	
	}
	cout << low << " " << high << endl;
	cout << lowF << " " << highF << endl;
}
