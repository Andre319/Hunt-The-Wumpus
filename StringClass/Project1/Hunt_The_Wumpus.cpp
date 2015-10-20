#include <time.h>
#include <iostream>
#include <sstream>


typedef unsigned char byte;

enum gameResult {FINISH, PLAY_NEW, PLAY_SAME};
enum object : byte {NOTHING, WUMPUS = 1, BAT = 2, PIT = 4, PLAYER = 8};

const unsigned S_PLAYER = 0, S_WUMPUS = 1, S_BAT1 = 2, S_BAT2 = 3, S_PIT1 = 4, S_PIT2 = 5,
MAX_ROOMS = 20, SAVED = 6, MAX_EXITS = 3, A_PATH_LEN = 5, MAX_ARROWS = 5;

class inOut
{
public:
	int getLetter(std::string s, int a, int b)
	{
		int c;
		do {
			msg(s);
			std::string r; std::cin >> r;
			std::cin.clear(); std::cin.ignore();
			c = toupper(r[0]);
		} while (c != a && c != b);
		return c;
	}
	int getNumber(std::string s)
	{
		int n = 0; std::string c;
		while (true)
		{
			msg(s);
			std::getline(std::cin, c);
			std::stringstream strm(c);
			if (strm >> n) break;
		}
		return n;
	}
	void  msg(std::string s) { std::cout << s; }
	void  msg(int i) { std::cout << i; }
	void  wait() { std::cin.get(); }
};

class room
{
public:
	int  getExit(int i)      { return exits[i]; }
	byte contains()          { return obj; }
	void clear(object o) { obj ^= o; }
	void
};