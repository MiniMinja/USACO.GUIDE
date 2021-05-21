#include <bits/stdc++.h>

using namespace std;

struct coor{
	int x, y;
	void printCoor(){
		cout << "x: " << x << " y: " << y << endl;
	}
};

int bored(coor& pos, const vector<coor>& boredHoles){
	for(coor boredHole: boredHoles){
		if(pos.x == boredHole.x && pos.y == boredHole.y){
			return 1;
		}
	}
	return 0;
}

int boreHoles(char command, int length, coor& currPos, vector<coor>& boredHoles){
	int danger = 0;
	for(int i = 0;i<length;i++){
		if(command == 'l'){
			currPos.x--;
		}
		else if(command == 'r'){
			currPos.x++;
		}
		else if(command == 'u'){
			currPos.y++;
		}
		else{
			currPos.y--;
		}
		if(bored(currPos, boredHoles)){
			danger = 1;
		}
		else{
			boredHoles.push_back({currPos.x, currPos.y});
		}
		//cout << "Bored: ";
		//currPos.printCoor();
	}
	return danger;
}

int main(){
	vector<coor> boredHoles;
	boredHoles.push_back({0, -1});
	boredHoles.push_back({0, -2});
	boredHoles.push_back({0, -3});
	boredHoles.push_back({1, -3});
	boredHoles.push_back({2, -3});
	boredHoles.push_back({3, -3});
	boredHoles.push_back({3, -4});
	boredHoles.push_back({3, -5});
	boredHoles.push_back({4, -5});
	boredHoles.push_back({5, -5});
	boredHoles.push_back({5, -4});
	boredHoles.push_back({5, -3});
	boredHoles.push_back({6, -3});
	boredHoles.push_back({7, -3});
	boredHoles.push_back({7, -4});
	boredHoles.push_back({7, -5});
	boredHoles.push_back({7, -6});
	boredHoles.push_back({7, -7});
	boredHoles.push_back({6, -7});
	boredHoles.push_back({5, -7});
	boredHoles.push_back({4, -7});
	boredHoles.push_back({3, -7});
	boredHoles.push_back({2, -7});
	boredHoles.push_back({1, -7});
	boredHoles.push_back({0, -7});
	boredHoles.push_back({-1, -7});
	boredHoles.push_back({-1, -6});
	boredHoles.push_back({-1, -5});
	coor currPos;
	currPos.x = -1;
	currPos.y = -5;

	while (1){
		char command;
		int length;
		cin >> command >> length;
		if(command == 'q') break;
		int danger = boreHoles(command, length, currPos, boredHoles);
		cout << currPos.x << " " << currPos.y << " ";
		if(danger) {
			cout << "DANGER" << endl;
			break;
		}else{
			cout << "safe" << endl;
		}
	}
}
