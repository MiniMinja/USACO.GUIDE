#include <bits/stdc++.h>

struct data{
	bool on;
	int f;

	data(bool on, int f){
		this->on = on;
		this->f = f;
	}
};

int main(){
	std::freopen("lifeguards.in", "r", stdin);
	std::freopen("lifeguards.out", "w", stdout);

	int N;
	std::cin >> N;

	std::array<std::vector<data*>*, 1001> timeline;
	for(int i = 0;i<1001;i++){
		timeline[i] = new std::vector<data*>();
	}

	for(int i = 0;i<N;i++){
		int startTime, endTime;
		std::cin >> startTime >> endTime;
		timeline[startTime]->push_back(new data(true, i));
		timeline[endTime]->push_back(new data(false, i));
	}

	int maxCovered = -1;
	for(int i = 0;i<N;i++){
		int coveredTime = 0;
		std::unordered_set<int> onduty;
		for(int j = 0;j<1001;j++){
			if(!timeline[j]->empty()){
				for(data* d: *timeline[j]){
					if(d->on && d->f != i){
						onduty.insert(d->f);
					}
					else if(!d->on && d->f != i){
						onduty.erase(d->f);
					}
				}
			}
			if(!onduty.empty()) coveredTime++;
		}
		if(coveredTime > maxCovered) maxCovered = coveredTime;
	}
	std::cout << maxCovered << std::endl;
}

