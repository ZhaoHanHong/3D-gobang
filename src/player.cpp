#include "player.h"
#include <stdio.h>
#include <string.h>
namespace bang {
	void player::AskForName()
	{
		for (int i = 0; i < NAMElength; i++)name_[i] = 0;
		printf("Please enter the name for the player %s, make sure it is no longer than 15 characters.\n", symbol_);
		char c=1;
		getchar();
		while (!(('a'<=c&&c<='z')||('A'<=c&&c<='Z')||('0'<=c&&c<='9'))) {
			c = getchar();
			if (c == '\n')break;
		}
		if(c!='\n')name_[0] = c;
		int i = 1;
		while (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9')) {
			scanf("%c", &c);
			if (1 <= i && i < 15) {
				name_[i] = c, i++;
			}
		}
		if (!name_[0])strcpy(name_, DEFALUT_name_);
		printf("Your name is %s\n", name_);
	}
	void player::init() {
		strcpy(symbol_, translate(num_sym_));
	}
	player::player(char* name,int sym):num_sym_(sym) {
		strcpy(this->name_, name);
		init();
	}
	char* player::getname()
	{
		return name_;
	}
	player::player(int sym):num_sym_(sym) {
		strcpy(this->name_, DEFALUT_name_);
		init();
	}
	char* player::translate(int sym) {
		if (sym == STAR) {
			return char_STAR;
		}
		else if(sym==DOT){
			return char_DOT;
		}
		else {
			printf("INTERIOR ERROR : translate player fault\n");
			return 0;
		}
	}

	void player::move(board *board) {
		board->prtsc();
		printf("%s, please put a %s \n", name_, symbol_);//edit
		int x, y, z;
		do {
			printf("Type three numbers as \"i j k\" for your move at i th floor, (j,k)coordinate.\n");
			scanf("%d %d %d", &z, &x, &y);
		} while (!(board->setstate(x,y, z,num_sym_)));
	}
	//debug
}