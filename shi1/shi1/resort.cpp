#include "resort.h"
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;


resort::resort()
{
}


resort::~resort()
{
}

bool check(int sodu[10][10], int n, int m)
{
	int heng = n / 9;
	int zong = n % 9;
	int a = heng / 3, b = zong / 3;
	a *= 3, b *= 3;
	int i, j;
	for (i = 0; i < 9; i++)
		if (sodu[i][zong] == m)
			return false;
	for (i = 0; i < 9; i++)
		if (sodu[heng][i] == m)
			return false;
	for (i = a; i < a + 3; i++)
	{
		for (j = b; j < b + 3; j++)
		{
			if (sodu[i][j] == m)
				return false;
		}
	}
	return true;
}
void dfs(int sodu[10][10], int n, int &flag)
{
	if (n > 80)
	{
		flag = 1;
		return;
	}
	if (sodu[n / 9][n % 9] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (check(sodu, n, i))
			{
				sodu[n / 9][n % 9] = i;
				dfs(sodu, n + 1, flag);
				if (!flag)
					sodu[n / 9][n % 9] = 0;
				else
					return;
			}
		}
	}
	else
		dfs(sodu, n + 1, flag);
}
void resort(char *s)
{
	int sodu[10][10];
	/*
	int sodu[10][10] = {
	{3,0,4,9,0,0,1,0,0},
	{5,0,0,0,0,0,0,0,8},
	{0,0,0,7,0,0,0,0,0},
	{0,2,0,0,6,8,7,0,5},
	{4,3,0,5,0,0,2,8,0},
	{0,7,0,0,0,9,0,1,6},
	{6,0,0,1,9,3,4,7,2},
	{7,0,1,8,0,0,5,9,3},
	{2,9,3,4,0,5,8,6,1}
	};*/
	/*
	int sodu[10][10] = {
	{6,1,4,5,2,8,9,3,7},
	{5,7,2,1,9,3,8,4,6},
	{3,0,8,6,4,0,0,0,0},
	{2,0,7,0,0,0,0,5,0},
	{0,8,6,4,7,5,2,0,3},
	{9,4,5,3,0,2,7,6,8},
	{0,6,0,0,0,0,0,7,0},
	{7,0,1,0,0,6,4,8,0},
	{0,0,0,0,8,1,6,0,9}
	};*/
	/*int sodu[10][10] = {
	{ 0, 8, 0, 0, 0, 9, 0, 7, 2 },
	{ 6, 0, 0, 0, 0, 0, 0, 0, 4 },
	{ 0, 5, 0, 0, 6, 0, 9, 0, 1 },
	{ 2, 0, 0, 0, 0, 5, 0, 0, 0 },
	{ 3, 7, 6, 1, 8, 4, 2, 9, 5 },
	{ 0, 0, 0, 3, 0, 0, 0, 0, 6 },
	{ 9, 0, 1, 0, 2, 0, 0, 4, 0 },
	{ 5, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 8, 4, 0, 9, 0, 0, 0, 2, 0 } };*/
	ifstream input;
	input.open(s);
	ofstream write;
	write.open("soduku.txt");
	while (!input.eof())
	{
		int i, j;
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				input >> sodu[i][j];
			}
		}
		int flag = 0;
		dfs(sodu, 0, flag);
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (j == 0)
					write << sodu[i][j];
				else
					write << " " << sodu[i][j];
			}
			if (i != 8)
				write << endl;
		}
		if (!input.eof())
		{
			write << endl;
			write << endl;
		}
	}
	write.close();
	input.close();
}