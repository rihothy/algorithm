#include <vector>

using namespace std;

auto flood_fill = [&](const auto& graph, auto ele)
{
	auto cnt = 0;
	auto vis = vector(r, vector(c, false));
	auto r = graph.size(), c = graph[0].size();
	const auto dir = vector<vector<int>>{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	auto dfs = [&](auto&& self, auto i, auto j)->void
	{
		for (auto k = 0; k < dir.size(); ++k)
		{
			auto ti = i + dir[k][0];
			auto tj = j + dir[k][1];

			if (ti >= 0 && ti < r && tj >= 0 && tj < c && graph[ti][tj] == ele && !vis[ti][tj])
			{
				vis[ti][tj] = true;
				self(self, ti, tj);
			}
		}
	};

	for (auto i = 0; i < r; ++i)
	{
		for (auto j = 0; j < c; ++j)
		{
			if (graph[i][j] == ele && !vis[i][j])
			{
				++cnt;
				vis[i][j] = true;

				dfs(dfs, i, j);
			}
		}
	}

	return cnt;
};
