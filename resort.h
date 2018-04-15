#pragma once
class resort
{
public:
	resort();
	~resort();
};
bool check(int sodu[10][10], int n, int m);
void dfs(int sodu[10][10], int n, int &flag);
void resort(char *s);

