#include <iostream>
#include <cstdlib>

int students;
int friendsGroup;
bool areFriends[10][10];

void clearFriendsSet() {
	for (int i = 0; i < 10; i++)
		std::memset(areFriends[i], false, sizeof(areFriends[i]));
}

int countPairings(bool taken[10]) {
	int firstFree = -1;

	for (int i = 0; i < friendsGroup; i++) {
		if (!taken[i]) {
			firstFree = i;
			break ;
		}
	}

	int ret = 0;

	for (int pairWith = firstFree + 1; pairWith < friendsGroup; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
	
}

int main(void) {
	int testCase;
	int result;
	bool taken[10];
	
	std::cin >> testCase;

	while (testCase--) {
		int friendShip[2];
		std::cin >> students >> friendsGroup;

		clearFriendsSet();
		std::memset(taken, false, 10);
		for (int i = 0; i < friendsGroup; i++) {
			std::cin >> friendShip[0] >> friendShip[1];
			areFriends[friendShip[0]][friendShip[1]] = true;
			areFriends[friendShip[1]][friendShip[0]] = true;
		}
		result = countPairings(taken);
		std::cout << result << std::endl;
	}
	return 0;
}
