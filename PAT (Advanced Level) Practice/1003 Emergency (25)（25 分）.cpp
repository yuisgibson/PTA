1003 Emergency(25)（25 分）

As an emergency rescue team leader of a city, you are given a special map of your country.The map shows several scattered cities connected by some roads.Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map.When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case.For each test case, the first line contains 4 positive integers : N(<= 500) - the number of cities(and the cities are numbered from 0 to N - 1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively.The next line contains N integers, where the i - th integer is the number of rescue teams in the i - th city.Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively.It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers : the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.\ All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input

5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output

2 4

最短路径问题，使用Dijkstra算法。
注意最后要输出的，一个是最短路径的个数，一个是最短路径基础上可召集的最大人数。

代码 部分参考《算法笔记》

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, st, ed;
int G[510][510], weight[510];
int d[510], w[510], num[510];
int vis[510] = { 0 };

void dijkstra(int s) {
	fill(d, d + 510, 9999999);
	fill(w, w + 510, 0);
	fill(num, num + 510, 0);
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;

	for (int i = 0;i<n;++i) {
		int u = -1, min = 9999999;

		for (int j = 0;j<n;++j) {
			if (vis[j] == 0 && d[j]<min) {
				u = j;
				min = d[j];
			}
		}

		if (u == -1)return;

		vis[u] = 1;

		for (int v = 0;v<n;++v) {
			if (vis[v] == 0 && G[u][v] != 9999999) {
				if (G[u][v] + d[u]<d[v]) {
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				}
				else if (G[u][v] + d[u] == d[v]) {
					if (w[u] + weight[v]>w[v]) {
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &st, &ed);

	for (int i = 0;i<n;++i) {
		scanf("%d", &weight[i]);
	}

	for (int i = 0;i<n;++i) {
		for (int j = 0;j<m;++j) {
			G[i][j] = 9999999;
		}
	}

	for (int i = 0;i<m;++i) {
		int b, e;
		scanf("%d%d", &b, &e);
		scanf("%d", &G[b][e]);
		G[e][b] = G[b][e];
	}

	dijkstra(st);

	printf("%d %d", num[ed], w[ed]);

	return 0;
}