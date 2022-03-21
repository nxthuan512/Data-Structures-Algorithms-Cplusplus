/*
 * island_explore.h
 *
 *  Created on: May 7, 2021
 *      Author: Thomas Nguyen
 */

#ifndef ISLAND_EXPLORE_H_
#define ISLAND_EXPLORE_H_

#include <iostream>
using namespace std;

#define MAX_ROW 5
#define MAX_COL 5

int island_area(int arr[][MAX_COL], int m, int n, int i0, int j0);
void test_island_area();

#endif /* ISLAND_EXPLORE_H_ */
