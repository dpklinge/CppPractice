#include "Game.h"
#include <iostream>



Game::Game() {
	initializeBoard();
}
void Game::runGame(std::map<std::string, std::string> options) {
	while (true) {
		displayBoard();
		int move[2];
		getMove(move);
		if (makeMove(move, "X")) {
			displayBoard();
			std::cout << "You win! Congratulations!" << std::endl;
			if (playAgain()) {
				initializeBoard();
				continue;
			}
			else {
				return;
			}
		}

		if (enemyTurn("O")) {
			displayBoard();
			std::cout << "You lose! Sorry :(" << std::endl;
			if (playAgain()) {
				initializeBoard();
				continue;
			}
			else {
				return;
			}
		}
	}
}
void Game::displayBoard() {
	std::cout << "  0 1 2 " << std::endl;
	std::cout << "0 " << board[0][0] << "|" << board[1][0] << "|" << board[2][0] << std::endl;
	std::cout << "  _____" << std::endl;
	std::cout << "1 " << board[0][1] << "|" << board[1][1] << "|" << board[2][1] << std::endl;
	std::cout << "  _____" << std::endl;
	std::cout << "2 " << board[0][2] << "|" << board[1][2] << "|" << board[2][2] << std::endl;
}

void Game::getMove(int move[])
{
	while (true) {
		std::cout << "Please input the coordinates of the square you would like to play, separated by a space." << std::endl;
		std::string input;
		getline(std::cin, input);
		if (input.length() == 3) {
			if (input[0] <= '3' && input[0] >= '0' && input[1] == ' ' && input[2] <= '3' && input[2] >= '0') {
				std::string square = board[input[0] - '0'][input[2] - '0'];
				if (square != "-") {
					std::cout << "Square already occupied" << std::endl;
				}
				else {
					std::cout << "Inputs in ints: " << input[0] - '0' << "," << input[2] - '0' << std::endl;
					int coord1 = input[0] - '0';
					int coord2 = input[2] - '0';
					move[0] = coord1;
					move[1] = coord2;
					std::cout << "Array returned is : " << move[0] << "," << move[1] << std::endl;
					return;
				}
			}
		}
	}
}

bool Game::checkForWin(std::string playerToken)
{
	if (board[0][0] == playerToken && board[1][0] == playerToken && board[2][0] == playerToken) {
		return true;
	}
	else if (board[0][0] == playerToken && board[0][1] == playerToken && board[0][2] == playerToken) {
		return true;
	}
	else if (board[0][0] == playerToken && board[1][1] == playerToken && board[2][2] == playerToken) {
		return true;
	}
	else if (board[1][0] == playerToken && board[1][1] == playerToken && board[1][2] == playerToken) {
		return true;
	}
	else if (board[2][0] == playerToken && board[2][1] == playerToken && board[2][2] == playerToken) {
		return true;
	}
	else if (board[0][1] == playerToken && board[1][1] == playerToken && board[2][1] == playerToken) {
		return true;
	}
	else if (board[0][2] == playerToken && board[1][2] == playerToken && board[2][2] == playerToken) {
		return true;
	}
	else if (board[2][0] == playerToken && board[1][1] == playerToken && board[0][2] == playerToken) {
		return true;
	}
	return false;
}

bool Game::makeMove(int move[], std::string playerToken)
{
	std::cout << "Making move : " << move[0] << "," << move[1] << std::endl;
	board[move[0]][move[1]] = playerToken;

	return checkForWin(playerToken);
}

bool Game::enemyTurn(std::string enemyToken)
{
	std::vector<std::vector<int>> options = getOpenSquares();
	int selection = rand() % (options.size() - 1);
	int move[] = { options[selection][0], options[selection][1] };
	makeMove(move, enemyToken);
	return checkForWin(enemyToken);
}

bool Game::playAgain()
{
	std::cout << "Would you like to play again? ('y' to play again)" << std::endl;
	std::string input;
	getline(std::cin, input);
	if (input.size() > 0 && input[0] == 'y') {
		return true;
	}
	return false;
}

void Game::initializeBoard()
{
	for (int i = 0; i < board.size();i++) {
		for (int j = 0; j < board[0].size(); j++) {
			std::cout << "defaulting array at " << i << "," << j << std::endl;
			board[i][j] = "-";
		}
	}
}

std::vector<std::vector<int>> Game::getOpenSquares()
{
	std::vector<std::vector<int>> squares;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] == "-") {
				std::vector<int> coordinate;
				coordinate.push_back(i);
				coordinate.push_back(j);
				squares.push_back(coordinate);
			}
		}
	}
	return squares;
}

