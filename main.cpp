#include<cstdio>
#include "sodu_creat.h"
#include "resort.h"
#include<cstring>
#include<algorithm>
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int n = 0;
	char c;
	char s[1000];
	while ((c = getchar()) != '\n')
	{
		if (c == '-')
		{
			if ((c = getchar()) == 'c')
			{
				scanf_s("%d", &n);
				creat(n);
				break;
			}
			else if (c == 's')
			{
				scanf_s("%s", s, 1000);
				resort(s);
			}
		}
	}
}

