#include <iostream>
#include <cstring>

int findMaxValue(int& depth, int cache[101][101], int triangle[101][101], int y, int x) {
	if (y == depth - 1)
		return triangle[y][x];

	int& ret = cache[y][x];

	if (ret != - 1)
		return ret;
	return ret = std::max(findMaxValue(depth, cache, triangle, y + 1, x), findMaxValue(depth, cache, triangle, y + 1, x + 1)) + triangle[y][x];
}

int main(void) {
	int depth;
	int answer;
	int cache[101][101];
	int triangle[101][101];

	std::cin >> depth;
	for (int i = 0; i < depth; i++) {
		std::memset(cache[i], -1, sizeof(cache[i]));
		for (int j = 0; j < i + 1; j++) {
			std::cin >> triangle[i][j];
		}
	}
	answer = findMaxValue(depth, cache, triangle, 0, 0);
	std::cout << answer << std::endl;
	return 0;
}