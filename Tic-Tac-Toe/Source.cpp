#include "Board.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int count = 0;
	cout << "**** Welcome to the Game Tic Tac Toe ****" << endl;
	cout << "MAIN MENU\n" << "1. Start Game\n" << "2. Exit\n" << "Enter to start or end: ";
	cin >> count;

	ofstream ofs;
	ofs.open("result.text", ofstream::out | ofstream::trunc);
	ofs.close();

	while (count == 1)
	{
		cout << "Player 1 (X) and Player 2 (O)" << endl << endl;
		cout << "Choose a number from 1 - 9 to fill up your (X)" << endl;
		char mark;
		int player = 1;
		int spot = 0;
		tictactoe game;

		game.boardGame();

		do {
			if (player == 1)
			{
				cout << "Player " << player << " Enter here: ";
				mark = 'X';
				player++;
			}
			else
			{
				cout << "Player " << player << " Enter here: ";
				mark = 'O';
				player--;
			}
			cin >> spot;
			while (spot > 9 || spot < 1)
			{
				cout << "Please enter valid spot for your mark" << endl;
				cin >> spot;
			}
			spot--;
			if (game.arr[spot] != 'O' && game.arr[spot] != 'X')
			{
				game.arr[spot] = mark;
			}
			else
			{
				cout << "Invalid spot";
				if (player == 1) {
					player++; mark = 'X';
				}
				else {
					player--;
					mark = 'O';
				}
			}

			game.boardGame();

		} while (game.winner() != 1 && game.winner() != -1);

		if (game.winner() == 1)
		{
			if (mark == 'X')
				player = 1;
			else player = 2;
			cout << "The winner is player: " << player << "(" << mark << ")! Thank you for playing!" << endl;
			ofstream data;
			data.open("result.text", ios::app);
			data << "Winner: player " << player;
			data << endl;
			data.close();
		}
		else if (game.winner() == -1) {
			cout << " The game is draw! Thank you for playing!" << endl;
			ofstream data;
			data.open("result.text", ios::app);
			data << "GameDraw";
			data << endl;
			data.close();
		}

		cout << "Press 1 to restart or 2 to view result or 3 to exit" << ": \n";
		cin >> count;
		while (count == 2)
		{
			cout << "Result is shown below game by game: \n";
			string viewResult;
			ifstream dataRead;
			dataRead.open("result.text");
			while (!dataRead.eof())
			{
				getline(dataRead, viewResult);
				if (dataRead.eof())
					break;
				cout << viewResult << endl;
			}
			dataRead.close();
			cout << "Press 1 to restart or 2 to view result or 3 to exit" << ": \n";
			cin >> count;
		}
		while (count > 3 || count < 1)
		{
			cout << "Please enter valid option: ";
			cin >> count;
		}
	}
	return 0;
}


