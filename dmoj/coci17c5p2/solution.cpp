#include <bits/stdc++.h>

using namespace std;

class spiral{
public:
	int x, y;
	int t;
	int needsToMove;
	int stepsTaken;
	char dir;
	int val;

	spiral(int x, int y, int t){
		this->x = x;
		this->y = y;
		this->t = t;
		this->dir = 'L';
		this->needsToMove = 0;
		this->stepsTaken = 0;
		this->val = 1;
	}

	void move(int N, int M, int** board);
	
	void printState(){
		cout << "\tdir: " << dir << " t: " << t << endl << 
			"\tx: " << x << " y: " << y << endl << 
			"\tval: " << val << endl << 
			"\tneedsToMove: " << needsToMove << " stepsTaken: " << stepsTaken << endl;	

	}
};
void spiral::move(int N, int M, int** board){
	if(0 <= x && x < N && 0 <= y && y < M && board[x][y] == 0){
		board[x][y] = val;
	}
	val++;
	if(dir == 'L'){
		x--;
		dir = 'E';
		needsToMove += 1;
	}
	else if(dir == 'E'){
		if(!t)y++;
		else y--;
		stepsTaken++;
		if(stepsTaken == needsToMove){
			dir = 'S';
			stepsTaken = 0;
			needsToMove++;
		}
	}
	else if(dir == 'S'){
		x++;
		stepsTaken++;
		if(stepsTaken == needsToMove){
			dir = 'W';
			stepsTaken = 0;
		}
	}
	else if(dir == 'W'){
		if(!t) y--;
		else y++;
		stepsTaken++;
		if(stepsTaken == needsToMove){
			dir = 'N';
			stepsTaken = 0;
		}
	}
	else if(dir == 'N'){
		x--;
		stepsTaken++;
		if(stepsTaken == needsToMove){
			dir = 'L';
			stepsTaken = 0;
		}
	}
}

void printBoard(int N, int M, int** board){
	for(int i = 0;i<N;i++){
		for(int j = 0;j<M;j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int N, M, K;
	cin >> N >> M >> K;

	int** board;
	board = new int* [N];
	for(int i = 0;i<N;i++){
		board[i] = new int[M];
	}
	//cout << "Empty: " << endl;
	//printBoard(N, M, board);

	vector<spiral*> spirals;
	for(int i = 0;i<K;i++){
		int x, y, t;
		cin >> x >> y >> t;
		spirals.push_back(new spiral(x-1, y-1, t));
	}
	for(int i = 0;i<(2*N-1)*(2*M-1);i++){
		for(spiral* s: spirals){
			//s->printState();
			s->move(N, M, board);
			//cout << "Spiral moved:" << endl;
			//printBoard(N, M, board);
		}
	}
	printBoard(N, M, board);
}
