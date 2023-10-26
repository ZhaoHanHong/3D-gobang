#ifndef __GAME_H__
#define __GAME_H__
#include "board.h"
#include "player.h"
namespace bang {
	class game
	{
	public:
		game(board *board, player* p_1,player* p_2);
		void startgame();
		int judge();
		int checkline(int type);
		int checkdiag(int type);
		int checksuperdiag();
		static const int I = 0;
		static const int J = 1;
		static const int K = 2;
	private:
		int gamesize_=0;
		int in_game_=0;
		board *gameboard_;
		player *p_1_;
		player *p_2_;
	};

}//namespace bang
#endif // !__GAME_H__
