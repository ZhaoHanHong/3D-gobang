#include "game.h"

#include <stdio.h>
namespace bang {
	game::game(board* board, player* p_1, player* p_2) {
		this->gameboard_ = board;
		this->p_1_ = p_1;
		this->p_2_ = p_2;
	}

	void game::startgame()
	{
		printf("Welcome to 3D-gobang with gravity!\n");
		printf("Game began!Type a positive integer to decide the size of board.\n");
		int size; scanf("%d", &size);
		gameboard_->setsize(size);
		gamesize_ = size;
		in_game_ = size * size * size;
		bool p_1_move = 1;
		p_1_->AskForName();
		p_2_->AskForName();
		while (in_game_--) {
			if (p_1_move) {
				p_1_->move(gameboard_);
			}
			else {
				p_2_->move(gameboard_);
			}
			p_1_move=!p_1_move;
			int result=judge();
			if (result) {
				printf("Game Ended!\n");
				if (result == gameboard_->DOT)printf("Winner is %s\n", p_1_->getname());
				else printf("Winner is %s\n", p_2_->getname());
				return;
			}
		}
		printf("Game Ended! No one winned!\n");
	}
	
	int game::checkline(int type) {
		switch (type)
		{
		case I: {
			int i = 0, j = 0, k = 0, sum = 0;
			for (j=0; (j < gamesize_); j++) {
				for (k=0; (k < gamesize_); k++) {
					sum = 0;
					for (i = 0; i < gamesize_; i++) {
						sum += gameboard_->getstate(i + 1, j + 1, k + 1);
					}
					if (sum == gamesize_ * 1)return gameboard_->DOT;
					if (sum == gamesize_ * (-1))return gameboard_->STAR;
				}
			}
			return 0;
			break;
		}
		case J: {
			int i = 0, j = 0, k = 0, sum = 0;
			for (k=0; (k < gamesize_); k++) {
				for (i=0; (i < gamesize_); i++) {
					sum = 0;
					for (j = 0; j < gamesize_; j++) {
						sum += gameboard_->getstate(i+1, j+1, k+1);
					}
					if (sum == gamesize_ * gameboard_->DOT)return gameboard_->DOT;
					if (sum == gamesize_ * gameboard_->STAR)return gameboard_->STAR;
				}
			}
			return 0;
			break;
		}
		case K: {
			int i = 0, j = 0, k = 0, sum = 0;
			for (i=0; (i < gamesize_); i++) {
				for (j=0; (j < gamesize_); j++) {
					sum = 0;
					for (k = 0; k < gamesize_; k++) {
						sum += gameboard_->getstate(i+1, j+1, k+1);
					}
					if (sum == gamesize_ * gameboard_->DOT)return gameboard_->DOT;
					if (sum == gamesize_ * gameboard_->STAR)return gameboard_->STAR;
				}
			}
			return 0;
			break;
		}
		default: {return 0; break; }
		}
		return 0;
	}
	int game::checkdiag(int type)
	{
		switch (type)
		{
		case I: {
			for (int i = 0; i < gamesize_; i++) {
				int sum = 0;
				for (int j = 0, k = gamesize_ - 1; k >= 0; j++, k--) {
					sum += gameboard_->getstate(i+1, j+1, k+1);
				}
				if (sum == gamesize_ * gameboard_->DOT)return gameboard_->DOT;
				if (sum == gamesize_ * gameboard_->STAR)return gameboard_->STAR;

				sum = 0;
				for (int j = gamesize_ - 1, k = 0; j >= 0; j--, k++) {
					sum += gameboard_->getstate(i + 1, j + 1, k + 1);
				}
				if (sum == gamesize_ * gameboard_->DOT)return gameboard_->DOT;
				if (sum == gamesize_ * gameboard_->STAR)return gameboard_->STAR;
			}
			break;
		}
		case J: {
			for (int j = 0; j < gamesize_; j++) {
				int sum = 0;
				for (int k = 0, i = gamesize_ - 1; i >= 0; k++, i--) {
					sum += gameboard_->getstate(i + 1, j + 1, k + 1);
				}
				if (sum == gamesize_ * gameboard_->DOT)return gameboard_->DOT;
				if (sum == gamesize_ * gameboard_->STAR)return gameboard_->STAR;
				sum = 0;
				for (int k = gamesize_ - 1, i = 0; k >= 0; k--, i++) {
					sum += gameboard_->getstate(i + 1, j + 1, k + 1);
				}
				if (sum == gamesize_ * gameboard_->DOT)return gameboard_->DOT;
				if (sum == gamesize_ * gameboard_->STAR)return gameboard_->STAR;
			}
			break;
		}
		case K: {
			for (int k = 0; k < gamesize_; k++) {
				int sum = 0;
				for (int i = 0, j = gamesize_ - 1; j >= 0; i++, j--) {
					sum += gameboard_->getstate(i + 1, j + 1, k + 1);
				}
				if (sum == gamesize_* gameboard_->DOT)return gameboard_->DOT;
				if (sum == gamesize_ * gameboard_->STAR)return gameboard_->STAR;
				sum = 0;
				for (int i = gamesize_ - 1, j = 0; i >= 0; i--, j++) {
					sum += gameboard_->getstate(i + 1, j + 1, k + 1);
				}
				if (sum == gamesize_ * gameboard_->DOT)return gameboard_->DOT;
				if (sum == gamesize_ * gameboard_->STAR)return gameboard_->STAR;
			}
			break;
		}
		}
		return 0;
	}
	int game::checksuperdiag()
	{
		int sum;
		sum = 0;
		for (int i = 0, j = gamesize_-1, k = gamesize_-1; j >= 0; i++, j--, k--) {
			sum += gameboard_->getstate(i+1, j+1, k+1);
		}
		if (sum == gamesize_ * gameboard_->DOT)return gameboard_->DOT;
		if (sum == gamesize_ * gameboard_->STAR)return gameboard_->STAR;
		sum = 0;
		for (int i = 0, j = gamesize_-1, k = 0; j >= 0; i++, j--, k++) {
			sum += gameboard_->getstate(i + 1, j + 1, k + 1);
		}
		if (sum == gamesize_ * gameboard_->DOT)return gameboard_->DOT;
		if (sum == gamesize_ * gameboard_->STAR)return gameboard_->STAR;
		sum = 0;
		for (int i = gamesize_-1, j = gamesize_-1, k = 0; j >= 0; i--, j--, k++) {
			sum += gameboard_->getstate(i + 1, j + 1, k + 1);
		}
		if (sum == gamesize_ * gameboard_->DOT)return gameboard_->DOT;
		if (sum == gamesize_ * gameboard_->STAR)return gameboard_->STAR;
		sum = 0;
		for (int i = gamesize_-1, j = gamesize_-1, k = gamesize_-1; j >= 0; i--, j--, k--) {
			sum += gameboard_->getstate(i + 1, j + 1, k + 1);
		}
		if (sum == gamesize_ * gameboard_->DOT)return gameboard_->DOT;
		if (sum == gamesize_ * gameboard_->STAR)return gameboard_->STAR;
		return 0;
	}
	int game::judge()
	{
		for (int i = 0; i < 3; i++) {
			int answer = checkline(i);
			if (answer) {
				return answer;
			}
			answer = checkdiag(i);
			if (answer) {
				return answer;
			}
		}
		int answer = checksuperdiag();
		if (answer)return answer;
		return 0;
	}
}//namespace bang