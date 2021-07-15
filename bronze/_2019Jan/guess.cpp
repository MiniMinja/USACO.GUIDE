#include <bits/stdc++.h>

struct animal{
	std::string a;
	std::unordered_set<std::string> desc;

	animal(std::string& an){
		a = an;
	}

	void addDesc(std::string& d){
		desc.insert(d);
	}
};

int matchingDesc(animal* a, animal* b){
	//std::cout << "Comparing: " << a->a << " with " << b->a << std::endl;
	int count = 0;
	for(std::string d: a->desc){
		if(b->desc.find(d) != b->desc.end()){
			count++;
		}
	}
	//std::cout << "Found " << count << " matches." << std::endl;
	return count;
}

int main(){
	std::freopen("guess.in", "r", stdin);
	std::freopen("guess.out", "w", stdout);

	int N;
	std::cin >> N;
	
	std::vector<animal*> animals;
	for(int i = 0;i<N;i++){
		std::string a;
		int K;
		std::cin >> a >> K;
		animal* na = new animal(a);
		animals.push_back(na);
		for(int j = 0;j<K;j++){
			std::string desc;
			std::cin >> desc;
			na->addDesc(desc);
		}
	}

	int maxMatching = -1;
	for(int i = 0;i<N-1;i++){
		for(int j = i+1;j<N;j++){
			int m = matchingDesc(animals[i], animals[j]);
			if(m > maxMatching) maxMatching = m;
		}
	}
	std::cout << maxMatching+1 << std::endl;
}
