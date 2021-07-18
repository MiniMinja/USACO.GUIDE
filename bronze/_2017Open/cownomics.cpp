#include <bits/stdc++.h>

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

	int count = 0;
	for(int i = 0;i<M-2;i++){
		for(int j = i+1;j<M-1;j++){
			for(int k = j+1;k<M;k++){
				bool foundMatch = false;
				for(int s = 0;s<N;s++){
					if(foundMatch) break;
					for(int p = 0;p<N;p++){
						if(foundMatch) break;
						if( (spotty[s][i] == plain[p][i] && spotty[s][j] == plain[s][j] && spotty[s][k] == plain[s][k]) ){
							foundMatch = true;
						}
					}
				}
				if(!foundMatch) count++;
			}
		}
	}
	std::cout << count << std::endl;
}
