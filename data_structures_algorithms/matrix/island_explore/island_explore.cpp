#include "island.h"

int island_area(int island[][MAX_COL], int m, int n, int i, int j)
{
	// Base case

	// Recursion
	int max_island_cnt = INT_MIN;
	int left = 0;
	int right = 0;
	int up = 0;
	int down = 0;

	if (island[i][j] == 1)
	{
		island[i][j] = -1;

		if ((j >= 1) && (island[i][j-1] == 1))
			left = island_area(island, m, n, i, j-1);
		if ((j < n-1) && (island[i][j+1] == 1))
			right = island_area(island, m, n, i, j+1);
		if ((i >= 1) && (island[i-1][j] == 1))
			up = island_area(island, m, n, i-1, j);
		if ((i < m-1) && (island[i+1][j] == 1))
			down = island_area(island, m, n, i+1, j);

		max_island_cnt = left + right + up + down + 1;
	}

	return (max_island_cnt);
}

void test_island_area()
{
	int island[MAX_ROW][MAX_COL] = {
		{0, 0, 1, 0, 1},
		{0, 0, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{0, 0, 1, 0, 0},
		{1, 1, 1, 1, 1}
	};

	cout << island_area(island, MAX_ROW, MAX_COL, 2, 2) << endl;
}
