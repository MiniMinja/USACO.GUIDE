#include <bits/stdc++.h>

using namespace std;

struct point{
	int x, y;
	point(int x, int y){
		this->x = x;
		this->y = y;
	}

	void print(){
		cout << "(" << x << "," << y << ")" << endl;
	}
};

int dis_squared(point& a, point& b){
	return pow(a.x - b.x, 2) + pow(a.y - b.y, 2); 
}

int main(){
	int N;
	cin >> N;
	vector<point> points;
	for(int i = 0;i<N;i++){
		points.push_back(*(new point(0, 0)));
	}
	for(int i = 0;i<N;i++){
		cin >> points[i].x;
	}
	for(int i = 0;i<N;i++){
		cin >> points[i].y;
	}
	int max_d = -1;
	for(int i = 0;i<N-1;i++){
		for(int j = i+1;j<N;j++){
			point a = points[i];
			point b = points[j];
			int d = dis_squared(a, b);
			if(d > max_d){
				max_d = d;
			}	
		}
	}
	cout << max_d << endl;
}
