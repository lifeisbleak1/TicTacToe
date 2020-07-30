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
	cout << endl;
	for(int i = 0; i <= 3; i++){ // iterates through rows
		for(int j = 0; j <= 3; j++){ // iterates through columns
			cout << " " << grid[i][j]; // print cells on same line
		}
		cout << endl; // every time a row is finished add a new line
	}
	cout << endl;
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
	string winner[2] = {"O", "X"};
	for(int i = 0; i < 2; i++){
		for(int j = 1; j <= 3; j++){ // check rows
			if(grid[j][1] == winner[i] && grid[j][2] == winner[i] && grid[j][3] == winner[i]){
				displayGrid();
				cout << "\n" << winner[i] << " Wins!\n" << endl;
				cout << "3 across, row " << j << endl;
				gameOver = true;
			}
		}
		for(int k = 1; k <= 3; k++){ // check columns
			if(grid[1][k] == winner[i] && grid[2][k] == winner[i] && grid[3][k] == winner[i]){
				displayGrid();
				cout << "\n" << winner[i] << " Wins!\n" << endl;
				cout << "3 down, column " << k << endl;
				gameOver = true;
			}
		}
		if(grid[1][1] == winner[i] && grid[2][2] == winner[i] && grid[3][3] == winner[i]){
				displayGrid();
				cout << "\n" << winner[i] << " Wins!\n" << endl;
				cout << "Diagonal" << endl;
				gameOver = true;
		}
		if(grid[1][3] == winner[i] && grid[2][2] == winner[i] && grid[3][1] == winner[i]){
				displayGrid();
				cout << "\n" << winner[i] << " Wins!\n" << endl;
				cout << "Reverse diagonal" << endl;
				gameOver = true;
		}
	}
}

void resetGame(){
	turnCount = 0;
	gameOver = false;
	for(int i = 1; i<=3; i++){
		for(int j = 1; j<=3; j++){
			grid[i][j] = "_";
		}
	}

}

int main(){
	while(!gameOver){
		displayGrid();
		enterLetter(turnCount);
		checkWin();
		turnCount++;
		cout << "\n----------------" << endl; // 16 dashes
	}
	string yesNo;
	cout << "Would you like to play again? (y/n)\n";
	cin >> yesNo;
	if(yesNo == "y"){
		resetGame();
		main();
	}else{
		cout << "guess you don't like fun then\n" << endl;
	}
	return 0;
}
