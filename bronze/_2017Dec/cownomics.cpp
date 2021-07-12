#include <bits/stdc++.h>

struct genome{
	/* A - 0
	 * C - 1
	 * G - 2
	 * T - 3
	 */
	int genomes[4];

	genome(){
		genomes[0] = 0;
		genomes[1] = 0;
		genomes[2] = 0;
		genomes[3] = 0;
	}

	void addGene(char gene){
		if(gene == 'A') genomes[0] = 1;
		else if(gene == 'C') genomes[1] = 1;
		else if(gene == 'G') genomes[2] = 1;
		else genomes[3] = 1;
	}

	bool contains(char gene){
		if(gene == 'A') return genomes[0];
		else if(gene == 'C') return genomes[1];
		else if(gene == 'G') return genomes[2];
		else return genomes[3];
	}

	bool overlapping(genome* other){
		for(int i =0;i<4;i++){
			if(genomes[i] + other->genomes[i] == 2) return true;
		}
		return false;
	}
};

int main(){
	std::freopen("cownomics.in", "r", stdin);
	std::freopen("cownomics.out", "w", stdout);

	int N, M;
	std::cin >> N >> M;
	std::cin.ignore(100, '\n');
	std::vector<genome*> spotty_genomes;
	for(int i = 0;i<M;i++) spotty_genomes.push_back(new genome());

	for(int i = 0;i<N;i++){
		std::string line;
		std::getline(std::cin, line);
		//std::cout << "Line " << i << ": " << line << std::endl;
		for(int j = 0;j<M;j++){
			//std::cout << "Adding: " << line[j] << std::endl;
			spotty_genomes[j]->addGene(line[j]);
		}
	}
		
	std::vector<genome*> plain_genomes;
	for(int i = 0;i<M;i++) plain_genomes.push_back(new genome());

	for(int i = 0;i<N;i++){
		std::string line;
		std::getline(std::cin, line);
		//std::cout << "Line " << i << ": " << line << std::endl;
		for(int j = 0;j<M;j++){
			//std::cout << "Adding: " << line[j] << std::endl;
			plain_genomes[j]->addGene(line[j]);
		}
	}
		
	int count = 0;
	for(int i = 0;i<M;i++){
		if(spotty_genomes[i]->overlapping(plain_genomes[i]))
				count++;
	}
	std::cout << M-count << std::endl;
}
