#include <iostream>
#include <string>

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
char board[5][5];

bool isRange(int y, int x) {
	if (y < 0 || y > 4 || x < 0 || x > 4)
		return false;
	return true;
}

bool hasWord(int y, int x, const std::string& word) {
	if (!isRange(y, x))
		return false;

	if (board[y][x] != word[0])
		return false;
	
	if (word.size() == 1)
		return true;

	for (int location = 0; location < 8; location++) {
		int next[2] = {y + dy[location], x + dx[location]};

		if (hasWord(next[0], next[1], word.substr(1)))
			return true;
	}
	return false;
}

int main(void) {
	std::string word;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cin >> board[i][j];
		}
	}
	std::cin >> word;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (hasWord(i, j, word)) {
				std::cout << "Find!" << std::endl;
				return 0;
			}
		}
	}
	std::cout << "Not..." << std::endl;
	return 0;
}