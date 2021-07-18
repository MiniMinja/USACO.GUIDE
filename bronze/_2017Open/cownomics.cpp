#include <bits/stdc++.h>

struct triple{
	char a, b, c;

	triple(char a, char b, char c){
		this->a = a;
		this->b = b;
		this->c = c;
	}

	std::string getString(){
		std::string ret;
		ret += '(';
		ret += a;
		ret += ", ";
		ret += b;
		ret += ", ";
		ret += c;
		ret += ')';
		return ret;
	}
};

struct possible{
	std::vector<triple*> alltriples;

	int size(){
		return alltriples.size();
	}
};

void printCombos(std::vector<possible*>& ac){
	for(int i = 0;i<ac.size();i++){
		std::cout << i << ": ";
		bool fronted = true;
		for(int j = 0;j<ac[i]->alltriples.size();j++){
			if(fronted){
				fronted = false;
			}
			else{
				std::cout << " ";
			}
			std::cout << ac[i]->alltriples[j]->getString();	
		}
		std::cout << std::endl;
	}
}

bool matches(triple* a, triple* b){
	return a->a == b->a && a->b == b->b && a->c == b->c;
}

bool confirms(possible* a, possible* b){
	for(int i = 0;i<a->size();i++){
		for(int j = 0;j<b->size();j++){
			//std::cout << "\tComparing: " << a->alltriples[i]->getString() << " " << b->alltriples[j]->getString() << std::endl;
			if(matches(a->alltriples[i], b->alltriples[j])){
				//std::cout << "fail\n" << std::endl;
				return false;
			}
		}
	}
	//std::cout << "success\n" << std::endl;
	return true;
}

int main(){
	std::freopen("cownomics.in", "r", stdin);
	std::freopen("cownomics.out", "w", stdout);
	
	int N, M;
	std::cin >> N >> M;

	std::vector<std::string> spotty;
       	std::vector<std::string> plain;

	for(int i = 0;i<N;i++){
		std::string genome;
		std::cin >> genome;

		spotty.push_back(genome);
	}

	for(int i = 0;i<N;i++){
		std::string genome;
		std::cin >> genome;

		plain.push_back(genome);
	}

	std::vector<possible*> sallcombos;
	for(int i = 0;i<M-2;i++){
		for(int j = i+1;j<M-1;j++){
			for(int k = j+1;k<M;k++){
				possible* p = new possible();
				for(int s = 0;s<spotty.size();s++){
					triple* t = new triple(spotty[s][i], spotty[s][j], spotty[s][k]);
					p->alltriples.push_back(t);
				}
				sallcombos.push_back(p);
			}
		}
	}
	//printCombos(sallcombos);


	std::vector<possible*> pallcombos;
	for(int i = 0;i<M-2;i++){
		for(int j = i+1;j<M-1;j++){
			for(int k = j+1;k<M;k++){
				possible* p = new possible();
				for(int s = 0;s<plain.size();s++){
					triple* t = new triple(plain[s][i], plain[s][j], plain[s][k]);
					p->alltriples.push_back(t);
				}
				pallcombos.push_back(p);
			}
		}
	}
	//printCombos(pallcombos);


	int count = 0;
	for(int i = 0;i<sallcombos.size();i++){
		//std::cout << "comparing: " << i << std::endl;
		if(confirms(sallcombos[i], pallcombos[i])) count++;
	}
	std::cout << count << std::endl;
}
