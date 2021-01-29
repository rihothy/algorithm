#include <vector>
#include <queue>
#include <tuple>

using namespace std;

auto multi_bfs = [](const auto& graph, auto ele)
{
	auto r = graph.size(), c = r ? graph[0].size() : 0;

	auto que = queue<tuple<int, int>>();
	auto dises = vector(r, vector(c, 0));
	auto vis = vector(r, vector(c, false));
	const auto dir = vector<vector<int>>{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (graph[i][j] == ele)
			{
				que.push({ i, j });
				vis[i][j] = true;
			}
		}
	}

	while (!que.empty())
	{
		auto [i, j] = que.front();
		que.pop();

		for (int k = 0; k < dir.size(); ++k)
		{
			int ti = i + dir[k][0];
			int tj = j + dir[k][1];

			if (ti >= 0 && ti < r && tj >= 0 && tj < c && !vis[ti][tj])
			{
				vis[ti][tj] = true;
				que.push({ ti, tj });
				dises[ti][tj] = dises[i][j] + 1;
			}
		}
	}

	return dises;
};