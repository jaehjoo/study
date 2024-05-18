#include <iostream>
#include <cstring>
#include <cmath>

# define MAX 200001

int getMaxFenceSpace(int *boardSet, int lo, int hi) {
	if (lo == hi) {
		return boardSet[lo];
	}
	int mid = (lo + hi) / 2;
	int ret = std::max(getMaxFenceSpace(boardSet, lo, mid), getMaxFenceSpace(boardSet, mid + 1, hi));
	int left = mid;
	int right = mid + 1;
	int height = std::min(boardSet[left], boardSet[right]);
	int width = 2;

	ret = std::max(ret, height * width);

	while (lo < left || right < hi) {
		if (right < hi && (lo == left || boardSet[left - 1] < boardSet[right + 1])) {
			right++;
			height = std::min(height, boardSet[right]);
		}
		else {
			left--;
			height = std::min(height, boardSet[left]);
		}
		width++;
		ret = std::max(height * width, ret);
	}
	return ret;
}

int main(void) {
	int testCase;
	int boardNum;
	int answer;
	int *boardSet = new int[MAX];

	std::cin >> testCase;
	while (testCase--) {
		memset(boardSet, 0, MAX);
		std::cin >> boardNum;

		for (int i = 0; i < boardNum; i++) {
			std::cin >> boardSet[i];
		}
		answer = getMaxFenceSpace(boardSet, 0, boardNum - 1);
		std::cout << answer << std::endl;
	}
	delete[] boardSet;
	return 0;
}
