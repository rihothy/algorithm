#include <climits>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

auto shortest_path = [](const auto& graph, auto barrier, auto si, auto sj, auto ei, auto ej)
{
	auto r = graph.size(), c = r ? graph[0].size() : 0;

	auto vis = vector(r, vector(c, false));
	auto que = queue<tuple<int, int, int>>();
	const auto dir = vector<vector<int>>{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

	que.push({ si, sj, 0 });
	vis[si][sj] = true;

	while (!que.empty())
	{
		auto [i, j, steps] = que.front();
		que.pop();

		if (i == ei && j == ej)
		{
			return steps;
		}

		for (int k = 0; k < dir.size(); ++k)
		{
			auto ti = i + dir[k][0];
			auto tj = j + dir[k][1];

			if (ti >= 0 && ti < r && tj >= 0 && tj < c && graph[ti][tj] != barrier && !vis[ti][tj])
			{
				vis[ti][tj] = true;
				que.push({ ti, tj, steps + 1 });
			}
		}
	}

	return INT_MAX;
};