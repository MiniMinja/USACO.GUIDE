#include <bits/stdc++.h>

void printVector(std::vector<int>& arr){
	for(int a: arr){
		std::cout << a << " ";
	}
	std::cout << std::endl;
}

/*
 * This is Heap's algorithm to come up with every perumtation. Typically the 
 * algorithm is recursive: 
 */
void generate(int k, std::vector<int>& arr, int level){
	for(int i = 0;i<level;i++) std::cout << "\t";
	std::cout << "At level: " << level << std::endl;
	for(int i = 0;i<level;i++) std::cout << "\t";
	std::cout << "k: " << k << " Arr: ";
	printVector(arr);
	if(k == 1){
		printVector(arr);
	}
	else{
		generate(k-1, arr, level+1);
		for(int i = 0;i<level;i++) std::cout << "\t";
		std::cout << "For looping..." << std::endl;
		for(int i = 0;i<k-1;i++){
			for(int j = 0;j<level+1;j++) std::cout << "\t";
			std::cout << "i: " << i << std::endl;
			for(int j = 0;j<level+2;j++) std::cout << "\t";
			if(k % 2 == 0){
				std::cout << "Swapping: " << arr[i] << " and " << arr[k-1] << std::endl;
				std::swap(arr[i], arr[k-1]);
			}
			else{
				std::cout << "Swapping: " << arr[0] << " and " << arr[k-1] << std::endl;
				std::swap(arr[0], arr[k-1]);
			}
			generate(k-1, arr, level+1);
		}
	}
}


struct generator{
private:
	std::vector<int>* arr;
	int k;

public:
	generator(std::vector<int>* arr){
		this->arr = arr;
		k = arr->size();
	}

};

int main(){
	std::vector<int> arr = {1, 2, 3, 4, 5};
	printVector(arr);
	generate(arr.size(), arr, 0);
}
