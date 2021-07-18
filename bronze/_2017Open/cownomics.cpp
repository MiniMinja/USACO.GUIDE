#include <bits/stdc++.h>

int toNum(char c){
	if(c == 'A') return 0;
	else if(c == 'G') return 1;
	else if(c == 'C') return 2;
	else return 3;
}

int convert(char a, char b, char c){
	return toNum(a) * 16 + toNum(b) * 4 + toNum(c);
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


	int allNums[64] = {0};
	int count = 0;
	for(int i = 0;i<M-2;i++){
		for(int j = i+1;j<M-1;j++){
			for(int k = j+1;k<M;k++){
				bool foundMatch = false;
				for(int s = 0;s<N;s++){
					allNums[convert(spotty[s][i], spotty[s][j], spotty[s][k])] = 1;
				}
				for(int p = 0;p<N;p++){
					if(allNums[convert(plain[p][i], plain[p][j], plain[p][k])]) {
						foundMatch = true;
						break;
					}
				}
				for(int a = 0;a<64;a++) allNums[a] = 0;
				if(!foundMatch) count++;
			}
		}
	}
	std::cout << count << std::endl;
}
