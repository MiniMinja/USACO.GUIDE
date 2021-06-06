#include <bits/stdc++.h>

using namespace std;

struct cow{
	char dir;
	int x, y;
	bool on;
	int stepsTaken;

	cow(char d, int X, int Y){
		dir = d;
		x = X;
		y = Y;
		stepsTaken = 0;
		on = true;
	}

	void move(int steps){
		if(dir == 'N'){
			y += steps;
		}
		else{
			x += steps;
		}
		stepsTaken += steps;
	}

	void turnOff(){
		on = false;
	}
};

void printCow(cow* c){
	cout << "Cow: " << endl;
	if(c->dir == 'N') cout << "\tNorth Cow " << endl;
	else cout << "\tEast Cow " << endl;
	cout << "\tcurrent pos: " << "("<<c->x<<","<<c->y<<")"<<endl;
	if(c->on) cout << "\tOn" << endl;
	else cout << "\tOff" << endl;
	cout << "\tSteps Taken: " << c->stepsTaken << endl;
}

struct distanceData{
	int distance;
	cow* cowFrom;

	distanceData(int d, cow* cf){
		distance = d;
		cowFrom = cf;
	}
};

struct distanceDataSort{
	bool operator() (const distanceData& a, const distanceData& b) {
		return a.distance < b.distance;
	}
};

void printDistances(vector<distanceData>& distances){
	for(distanceData d: distances){
		cout << "distance: " << d.distance << endl;
	}
}

struct crossPoint{
	int x, y;
	bool crossed;

	crossPoint(int X, int Y){
		x = X;
		y = Y;
		crossed = false;
	}

	void cross(){
		crossed = true;
	}
};

int main(){
	freopen("rut.in", "r", stdin);
	int N;
	cin >> N;

	vector<cow*> cows;
	vector<cow*> nCows;
	vector<cow*> eCows;
	for(int i = 0;i<N;i++){
		char d;
		int x, y;
		cin >> d >> x >> y;
		cow* toadd = new cow(d, x, y);
		cows.push_back(toadd);
		if(d == 'N'){
			nCows.push_back(toadd);
		}
		else{
			eCows.push_back(toadd);
		}
	}
	
	vector<crossPoint*> crossPoints;
	vector<distanceData> distances;
	for(cow* nCow:nCows){
		for(cow* eCow: eCows){
			if(eCow->x <= nCow->x && nCow->y <= eCow->y){
				crossPoint* currPoint = new crossPoint(nCow->x, eCow->y);
				crossPoints.push_back(currPoint);
				distances.push_back(*(new distanceData(currPoint->y - nCow->y, nCow)));
				distances.push_back(*(new distanceData(currPoint->x - eCow->x, eCow)));
			}
		}
	}
	//cout << "Size of crossPoints: " << crossPoints.size()<<endl;

	//for(crossPoint* cp: crossPoints){
		//cout << "x: " << cp->x << " y: " << cp->y << endl;
	//}
	
	sort(distances.begin(), distances.end(), distanceDataSort());
	
	queue<crossPoint*> toTurnOff;
	int indexToStart = 0;
	bool willmove = true;
	while(indexToStart < distances.size()){
		//printDistances(distances);
		//cout << "\tNeed to move: ";
		int toMove = distances[indexToStart].distance;
		//cout << toMove << endl;
		for(int i = indexToStart;i<distances.size();i++){
			if(distances[i].distance - toMove == 0){
				indexToStart = i+1;
			}
			distances[i].distance -= toMove;
		}
		for(auto c:cows){
			if(c->on) c->move(toMove);
		}
		for(crossPoint* cp: crossPoints){
			for(auto c: cows){
				if(c->on && cp->x == c->x && cp->y == c->y){
					if(cp->crossed){
						c->turnOff();
					}
					else{
						toTurnOff.push(cp);
					}
				}
			}
		}
		while(!toTurnOff.empty()){
			toTurnOff.front()->cross();
			toTurnOff.pop();
		}
		//for(auto c:cows){
			//printCow(c);
		//}
		//cout << endl;
	}
	for(auto c: cows){
		if(c->on) cout << "Infinity" << endl;
		else cout << c->stepsTaken << endl;
	}
	
}
