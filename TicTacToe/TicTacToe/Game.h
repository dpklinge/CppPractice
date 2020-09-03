#pragma once
#include <map>
#include <string>
#include <vector>
#include <array>

class Game {
public:
	Game();
	void runGame(std::map<std::string, std::string> options);
	
	
private:
	std::array<std::array<std::string, 3>,3> board;
	void displayBoard();
	void getMove(int move[]);
	bool checkForWin(std::string playerToken);
	bool makeMove(int move[], std::string playerToken);
	bool enemyTurn(std::string enemyToken);
	bool playAgain();
	void initializeBoard();
	std::vector<std::vector<int>> getOpenSquares();
};