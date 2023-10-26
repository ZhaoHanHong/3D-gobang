#include "board.h"
#include "game.h"
#include "player.h"
using namespace bang;
int main() {
	board newboard;
	player player1(newboard.DOT);
	player player2(-1);
	game newgame(&newboard, &player1, &player2);
	newgame.startgame();
	return 0;
}