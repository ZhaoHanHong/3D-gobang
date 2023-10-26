#include "board.h"
#include "board.h"
#include <stdio.h>
namespace bang {
	void board::init()
	{
		int n = size_;
		a_ = new int[n * n * n] {};
	}
	board::board(int n) {
		this->size_ = n;
		init();
	}
	board::board() {
		this->size_ = DEFAULT_size;
		init();
	}
	int board::getsize()
	{
		return size_;
	}
	int board::getstate(int x, int y, int z) {
		x--, y--, z--;//input should be positive int
		if (x >= size_ || y >= size_ || z >= size_ || x < 0 || y < 0 || z < 0)return ERR;
		return a_[x + y * size_ + z * size_ * size_];
	}
	bool board::setstate(int x, int y, int z, int person) {
		x--, y--, z--;
		if (x >= size_ || y >= size_ || z >= size_ || x < 0 || y < 0 || z < 0) {
			printf("ERROR:place out of bound\n");
			return false;
		}
		else if (a_[x + y * size_ + z * size_ * size_]) {
			printf("ERROR:can't put on existed node\n");
			return false;
		}
		else if(z&&(a_[x + y * size_ + (z-1) * size_ * size_]==0)) {
			printf("ERROR:violating gravity laws\n");
			return false;
		}
		a_[x + y * size_ + z * size_ * size_] = person;//defination for the 3D list
		return true;
	}
	void board::prtsc() {
		for (int i = size_ - 1; i >= 0; i--) {
			printf("\nThe %d th floor:\n", i+1);
			for (int j = size_ - 1; j >= 0; j--) {
				printf("%d ", j+1);
				for (int k = 0; k < size_; k++) {
					char c= board::translate(a_[k + j * size_ + i * size_ * size_]);
					printf("%c ", c);
				}
				printf("\n");
			}
			printf("  ");
			for (int k = 0; k < size_; k++) {
				printf("%d ", k+1);
			}
			printf("\n");
		}
	}
	char board::translate(int val) {
		switch (val)
		{
		case DOT: {return 'o'; break; }
		case STAR: {return '*'; break; }
		default: {return '.'; break; }
		}
	}
	void board::setsize(int n)
	{
		if (n <= 0)return;
		delete[] a_;
		size_ = n;
		init();
	}
	board::~board() {
		delete[] a_;
	}
}//namespace bang
