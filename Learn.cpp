#include <iostream>
using namespace std;

char bord[3][3] = {
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}
};

void drawBoard(char bord[3][3]) {
	for (int i = 0; i < 3; i++) {
		cout << "| ";
		for (int j = 0; j < 3; j++) {
			if (bord[i][j] == 'X' || bord[i][j] == 'O') {
				cout << bord[i][j] << " | ";
			}
			else {
				cout << "# | ";
			}
		}
		cout << endl;
	}
}

bool isValidMove(char bord[3][3], int choice) {
	if (choice < 1 || choice > 9) return false;

	int row = (choice - 1) / 3;
	int col = (choice - 1) % 3;

	return (bord[row][col] != 'X' && bord[row][col] != 'O');
}

void putX(char bord[3][3], int choice, char player) {
	int row = (choice - 1) / 3;
	int col = (choice - 1) % 3;
	bord[row][col] = player;
}

int main() {
	char currentPlayer = 'X';
	int choice;

	while (true) {
		drawBoard(bord);
		cout << "\nPlayer " << currentPlayer << ", enter (1-9): ";
		cin >> choice;

		if (isValidMove(bord, choice)) {
			putX(bord, choice, currentPlayer);

			currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
		}
		else {
			cout << "Invalid move!";
			cin.ignore();
			cin.get();
		}
	}
	return 0;
}