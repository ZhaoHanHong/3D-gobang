#ifndef __BOARD_H__
#define __BOARD_H__

namespace bang {
	class board {
	private:
		int size_;
		int* a_;
		
	public:
		static const int STAR = -1;
		static const int DOT = 1;
		static const int ERR = 2;
		static const int DEFAULT_size = 4;
		void init();
		board(int n);
		board();
		int getsize();
		int getstate(int x, int y, int z);
		bool setstate(int x, int y, int z, int person);
		void prtsc();
		char translate(int val);
		void setsize(int n);
		~board();
	};
}//namespace bang
#endif // !__BOARD_H__
