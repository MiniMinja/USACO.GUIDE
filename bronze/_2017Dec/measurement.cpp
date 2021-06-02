#include <bits/stdc++.h>

using namespace std;

struct cow{
	string name;
	int productionRate;

	cow(string n, int pR){
		name = n;
		productionRate = pR;
	}

	void changeRate(int dr){
		productionRate += dr;
	}

	void print(){
		cout << "Name: " << name << " production rate: " << productionRate << endl;
	}
};

struct timestamp{
	int day;
	string name;
	int amount;

	timestamp(int day, string n, int a){
		this->day = day;
		name = n;
		amount = a;
	}

	bool operator<(const timestamp &o) const {
		return day < o.day;
	}

	void print(){
		cout << "day: " << day << " name: " << name << " amount: " << amount << endl;
	}
};

int main(){
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);

	int N;
	cin >> N;
	
	unordered_set<string> names;
	unordered_map<int, timestamp*> timeline;

	for(int i =0;i<N;i++){
		int day;
		string name;
		int change;
		cin >> day >> name >> change;
		timeline.insert({day, new timestamp(day, name, change)});
		names.insert(name);
	}

	vector<cow*> cows;
	unordered_map<string, cow*> cowsByName;
	for(string name:names){
		cow* c = new cow(name,  7);
		cows.push_back(c);
		cowsByName.insert({name, c});
	}

	int changes = 0;

	int maxOutput = -1;
	unordered_set<string> *last_winners;
	unordered_set<string> *curr_winners;
	last_winners = new unordered_set<string>();
	for(string name:names){
		last_winners->insert(name);
	}
	curr_winners = new unordered_set<string>();
	for(int i = 1;i<=100;i++){
		//cout << "day: " << i << endl;
		if(timeline.find(i) != timeline.end()){
			//timeline[i]->print();
			timestamp* tp = timeline[i];
			cow* curr = cowsByName[tp->name];
			curr->changeRate(tp->amount);
		}
		maxOutput = -1;
		for(auto c: cows){
			if(c->productionRate > maxOutput){
				maxOutput = c->productionRate;
				curr_winners->clear();
				curr_winners->insert(c->name);
			}
			else if(c->productionRate == maxOutput){
				curr_winners->insert(c->name);
			}
			//c->print();
		}
			
		if(curr_winners->size() != last_winners->size()){
			//cout << "-----------------------------------------------------------------CHANGED---------------------------------------------------------" << endl;
			//for(auto name: *curr_winners){
			//	cout << name;
			//}
			//cout << endl;
			changes++;
		}
		else{
			bool allcurrmatches = true;
			for(string name:*curr_winners){
				if(last_winners->find(name) == last_winners->end()){
					allcurrmatches = false;
				}
			}
			if(!allcurrmatches) {
				//cout << "-----------------------------------------------------------------CHANGED---------------------------------------------------------" << endl;
				//for(auto name: *curr_winners){
				//	cout << name;
				//}
				//cout << endl;
				changes++;
			}
		}
		last_winners->~unordered_set<string>();
		last_winners = curr_winners;
		curr_winners = new unordered_set<string>();
		//cout << endl;
	}
	cout << changes << endl;
}
