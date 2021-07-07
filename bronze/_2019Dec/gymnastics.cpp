#include <bits/stdc++.h>

template <typename T, std::size_t size>
void printArray(const std::array<T, size>& row, size_t N){
	for(size_t i = 0;i<N;i++){
		std::cout << row[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T, std::size_t size>
bool consistent(int num1, int num2, std::array<T, size>& pRow, int N){
	//printArray(pRow, N);
	//std::cout << "Checking: " << num1 << " " << num2 << std::endl;
	int i1 = -1;
	for(int i =0;i<N;i++){
		if(pRow[i] == num1){
			i1 = i;
			break;
		}
	}

	int i2 = -1;
	for(int i =0 ;i<N;i++){
		if(pRow[i] == num2){
			i2 = i;
			break;
		}
	}

	assert(i1 > -1 && i2 > -1);
	return i1 < i2;
}

struct Pair{
	int a, b;
	Pair(int a, int b){
		this->a = a;
		this->b = b;
	}
};

int main(){
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);

	int K, N;
	std::cin >> K >> N;

	std::array<int, 20> firstRow;
	for(int i = 0;i<N;i++) std::cin >> firstRow[i];
	//printArray(firstRow, N);

	std::vector<Pair*> pairs;
	for(int i = 0;i<N-1;i++){
		for(int j = i+1;j<N;j++){
			pairs.push_back(new Pair(firstRow[i], firstRow[j]));
		}
	}
	///for(Pair* p: pairs){
	//	std::cout << p->a << " " << p->b << std::endl;
	//}
	//std::cout << std::endl;
	std::vector<int> consistencyCount (pairs.size());
	for(int i = 0;i<pairs.size();i++) consistencyCount[i] = 1;
	//std::cout << "Consistencies: ";
	//for(int i = 0;i<pairs.size();i++) std::cout << consistencyCount[i] << " ";
	//std::cout << std::endl;

	std::array<int, 20> row;
	for(int i = 0;i<K-1;i++){
		for(int j = 0;j<N;j++) std::cin >> row[j];
		for(int j = 0;j<pairs.size();j++){
			Pair* p = pairs[j];
			consistencyCount[j] = consistencyCount[j] && consistent(p->a, p->b, row, N);
		}
	}

	//std::cout << "Consistencies: ";
	//for(int i = 0;i<pairs.size();i++) std::cout << consistencyCount[i] << " ";
	//std::cout << std::endl;
	
	int cc = 0;
	for(int i = 0;i<pairs.size();i++){
		if(consistencyCount[i]) cc++;
	}
	std::cout << cc << std::endl;
}
