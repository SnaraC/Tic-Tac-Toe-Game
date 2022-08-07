#include "Board.h"
#include <iostream>

using namespace std;

void tictactoe::boardGame() {

	cout << "     |     |     " << endl;
	cout << "  " << arr[0] << "  |  " << arr[1] << "  |  " << arr[2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << arr[3] << "  |  " << arr[4] << "  |  " << arr[5] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << arr[6] << "  |  " << arr[7] << "  |  " << arr[8] << endl;

	cout << "     |     |     " << endl << endl;
}

int tictactoe::winner() {
	if (arr[0] == arr[4] && arr[4] == arr[8])
		return 1;
	else if (arr[2] == arr[4] && arr[4] == arr[6])
		return 1;
	else if (arr[0] == arr[1] && arr[1] == arr[2])
		return 1;
	else if (arr[3] == arr[4] && arr[4] == arr[5])
		return 1;
	else if (arr[7] == arr[6] && arr[7] == arr[8])
		return 1;
	else if (arr[0] == arr[3] && arr[3] == arr[6])
		return 1;
	else if (arr[1] == arr[4] && arr[4] == arr[7])
		return 1;
	else if (arr[2] == arr[5] && arr[5] == arr[8])
		return 1;
	else if (arr[0] != '1' && arr[1] != '2' && arr[2] != '3' && arr[3] != '4' && arr[4] != '5' && arr[5] != '6' && arr[7] != '8' && arr[8] != '9')
		return -1;
	else return 0;
}