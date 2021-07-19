#include <bits/stdc++.h>

struct Point{
	int x, y;
	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
};

int whichquadrant(Point* p, int x, int y){
	if(p->x > x && p->y > y) return 1;
	else if(p->x > x && p->y < y) return 2;
	else if(p->x < x && p->y < y) return 3;
	else if(p->x < x && p->y > y) return 4;
	else {
		std::cout << "Point is on the axis" << std::endl;
		return -1;
	}
}

int main(){
	std::freopen("balancing.in", "r", stdin);
	std::freopen("balancing.out", "w", stdout);

	int N, B;
	std::cin >> N >> B;

	std::vector<int> xs;
	std::vector<int> ys;
	std::vector<Point*> points;
	for(int i = 0;i<N;i++){
		int x, y;
		std::cin >> x >> y;
		xs.push_back(x);
		ys.push_back(y);
		points.push_back(new Point(x, y));
	}

	int smallest_m = 51;
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			int x = xs[i]-1;
			int y = ys[j]-1;
			//std::cout << "making line: (" << x << ", " << y << ")" << std::endl;
			int m1 = 0;
			int m2 = 0;
			int m3 = 0;
			int m4 = 0;
			for(int k = 0;k<N;k++){
				int q = whichquadrant(points[k], x, y);
				if(q == 1) m1++;
				else if(q == 2) m2++;
				else if(q == 3) m3++;
				else if(q == 4) m4++;
			}
			int m = std::max(std::max(m1, m2), std::max(m3, m4));
			if(m < smallest_m) {
				smallest_m = m;
				//std::cout << "found the smallest m to be: " << smallest_m << std::endl;
				//std::cout << "x: " << x << " y: " << y << std::endl;
			}
		}
	}
	std::cout << smallest_m << std::endl;
}
