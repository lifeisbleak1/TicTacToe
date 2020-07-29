#include <iostream>

using namespace std;

bool gameOver = false;
int turnCount = 0;

string grid[4][4] = {
			{"0","1","2","3"},
			{"1","_","_","_"},
			{"2","_","_","_"},
			{"3","_","_","_"}
		};

void displayGrid(){
	for(int i = 0; i <= 3; i++){ // iterates through rows
		for(int j = 0; j <= 3; j++){ // iterates through columns
			cout << grid[i][j]; // print cells on same line
		}
		cout << endl; // every time a row is finished add a new line
	}
}

void enterLetter(int turnCount){
	if(turnCount % 2 == 0){ // even turn number, let's say O goes first
		int r;
		int c;
		cout << "Place an O\nrow: ";
		cin >> r;
		cout << "column: ";
		cin >> c;

		if (grid[r][c] == "_"){
			grid[r][c] = "O";
		}else{
			cout << "Invalid coordinate" << endl;
			enterLetter(turnCount);
		}
	}else{
		int r;
		int c;
		cout << "Place an X\nrow: ";
		cin >> r;
		cout << "column: ";
		cin >> c;

		if (grid[r][c] == "_"){
			grid[r][c] = "X";
		}else{
			cout << "Invalid coordinate" << endl;
			enterLetter(turnCount);
		}

	}
}

void checkWin(){
	//rows
	for(int i = 0; i<=3; i++){
		if("O" == grid[i][1] && "O" == grid[i][2] && "O" == grid[i][3]){
			cout << "O Wins!" << endl;
			gameOver = true;
		}
	}
}

int main(){

	while(!gameOver){
		displayGrid();
		enterLetter(turnCount);
		checkWin();
		turnCount++;
	}

	return 0;
}