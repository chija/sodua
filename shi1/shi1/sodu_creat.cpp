#include "sodu_creat.h"
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;


sodu_creat::sodu_creat()
{

}


sodu_creat::~sodu_creat()
{

}
void found(char factorial[][10], int &loc1, int &loc2, bool *vis, char*t)//ÕÒµ½½×³ËÊý
{
	int i;
	if (loc2 == 9)
	{
		for (i = 0; i < 9; i++)
			factorial[loc1][i] = t[i];
		loc1++;
	}
	for (i = 1; i <= 9; i++)
	{
		if (loc2 == 5 && i == 6)
		{
			t[loc2++] = 6, vis[6] = 1;
			found(factorial, loc1, loc2, vis, t);
			loc2--;
		}
		if (!vis[i])
		{
			t[loc2++] = i, vis[i] = 1;
			found(factorial, loc1, loc2, vis, t);
			loc2--, vis[i] = 0;
		}
	}
}
void cpy(int *a, int *b)
{
	for (int i = 0; i < 3; i++)
		a[i] = b[i];

}
void creat(int n)
{
	int count = 0, flag = 1;
	int i, j, k;
	char factorial[40321][10], t[10];
	int loc1 = 0, loc2 = 0;
	bool vis[10];
	memset(vis, 0, sizeof(vis));
	vis[6] = 1;
	memset(factorial, 0, sizeof(factorial));
	found(factorial, loc1, loc2, vis, t);//Ñ°ÕÒ½×³ËÊý
	char sodu[10][10] = {
		{ 6, 7, 9, 1, 8, 2, 4, 3, 5 },
	{ 2, 5, 8, 4, 9, 3, 6, 7, 1 },
	{ 4, 1, 3, 6, 5, 7, 9, 8, 2 },
	{ 9, 6, 1, 2, 7, 5, 8, 4, 3 },
	{ 3, 4, 5, 8, 6, 1, 7, 2, 9 },
	{ 8, 2, 7, 9, 3, 4, 1, 5, 6 },
	{ 7, 9, 2, 3, 4, 6, 5, 1, 8 },
	{ 5, 3, 6, 7, 1, 8, 2, 9, 4 },
	{ 1, 8, 4, 5, 2, 9, 3, 6, 7 }
	};
	int sodu_t[10];
	char change[73][10];
	memset(change, 0, sizeof(change));
	int t1[2][3] = { { 1,2,3 },{ 1,3,2 } };
	int t2[6][3] = { { 4,5,6 },{ 4,6,5 },{ 5,4,6 },{ 5,6,4 },{ 6,4,5 },{ 6,5,4 } };
	int t3[6][3] = { { 7,8,9 },{ 7,9,8 },{ 8,7,9 },{ 8,9,7 },{ 9,7,8 },{ 9,8,7 } };
	int loc_cg = 0;
	for (i = 0; i < 2; i++)
	{
		cpy(sodu_t, t1[i]);
		for (j = 0; j < 6; j++)
		{
			cpy(sodu_t + 3, t2[j]);
			for (k = 0; k < 6; k++)
			{
				cpy(sodu_t + 6, t3[k]);
				for (int ii = 0; ii < 9; ii++)
					change[loc_cg][ii] = sodu_t[ii];
				loc_cg++;
			}
		}
	}
	ofstream write;
	write.open("soduku.txt");
	for (k = 0; k < loc_cg && flag; k++)//ÁÐÌæ»»
	{
		for (j = 0; j < loc_cg && flag; j++)//ÐÐÌæ»»
		{
			for (i = 0; i < loc1 && flag; i++)//Ìæ»»µÄÊý×Ö
			{
				for (int ii = 0; ii < 9; ii++)
				{
					for (int jj = 0; jj < 9; jj++)
					{

						if (jj == 0)
							write << (int)factorial[i][sodu[change[j][ii] - 1][change[k][jj] - 1] - 1];
						else
							write << " " << (int)factorial[i][sodu[change[j][ii] - 1][change[k][jj] - 1] - 1];
					}
					if (count != n - 1 || ii != 8)
						write << endl;
				}
				count++;
				if (count == n)
				{
					flag = 0;
					break;
				}
				write << endl;
			}
		}
	}
}
