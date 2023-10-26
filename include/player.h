#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "board.h"
namespace bang {
	class player {
	private:
		char name_[20];
		char symbol_[20];
		static const int NAMElength = 20;
		int num_sym_;
		char* translate(int sym);
		char* const DEFALUT_name_ = "Administrator";
	public:
		char char_DOT[10] = "dot(o)";
		char char_STAR[10] = "star(*)";
		int DOT = 1;
		int STAR = -1;
		void AskForName();
		void init();
		player(int sym);
		player(char* name,int sym);
		char* getname();
		void move(board* board);
		//debug

	};
}//namespace bang

#endif