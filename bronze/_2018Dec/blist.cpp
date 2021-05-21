#include <bits/stdc++.h>

using namespace std;

struct timeline{
	timeline(int id, int s, int t, int b){
		this->id = id;
		this->s = s;
		this->t = t;
		this->b = b;
	}
	int id, s, t, b;
};

void printTimeline(const timeline& t){
	cout << "id: " << t.id << " s: " << t.s << " t: " << t.t << " b: " << t.b;
	cout << endl;
}

int bucketsUsed(const vector<int>& buckets){
	int count = 0;
	for(auto bucket:buckets)
		if(bucket != 0) count++;
	return count;
}

void useNextBBuckets(int B, int id, vector<int>& buckets){
	//cout << "Used: ";
	for(int i =1;B > 0 && i<=1000;i++){
		if(buckets[i] == 0){
			//cout << i << " ";
			buckets[i] = id;
			B--;
		}
	}
	//cout << endl;
}

void freeBuckets(int id, vector<int>& buckets){
	//cout << "Freed: ";
	for(int i = 1;i<=1000;i++){
		if(buckets[i] == id) {
			//cout << i << " ";
			buckets[i] = 0;
		}
	}
	//cout << endl;
}

int main(){
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);

	int N;
	cin >> N;

	vector<timeline> timelines;
	for(int i = 0;i<N;i++){
		int s, t, b;
		cin >> s >> t >> b;
		timelines.push_back(timeline(i+1, s, t, b));
		//cout << "Added: ";
		//printTimeline(timelines[i]);
	}

	int maxBUsed = -1;
	vector<int> availableBuckets(1001);
	for(int time = 1;time<=1000;time++){
		for(timeline tl: timelines){
			if(time == tl.s){
				useNextBBuckets(tl.b, tl.id, availableBuckets);
			}
			if(time == tl.t){
				freeBuckets(tl.id,  availableBuckets);
			}
		}
		int bUsed = bucketsUsed(availableBuckets);
		if(bUsed > maxBUsed) maxBUsed = bUsed;
	}
	cout << maxBUsed << endl;
}
