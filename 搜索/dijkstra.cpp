#include <climits>
#include <vector>

using namespace std;

auto dijkstra = [](const auto& graph, auto u, int inf = INT_MAX)
{
	auto n = graph.size();
	auto vis = vector(n, false);
	auto dist = vector(n, inf);

	for (const auto& [v, l] : graph[u])
	{
		dist[v] = min(dist[v], l);
	}

	for (int i = 0; i < n; ++i)
	{
		int idx = -1;

		for (int j = 0; j < n; ++j)
		{
			if (!vis[j] && (idx == -1 || dist[j] < dist[idx]))
			{
				idx = j;
			}
		}

		for (const auto& [v, l] : graph[idx])
		{
			dist[v] = min(dist[idx] + l, dist[v]);
		}

		vis[idx] = true;
	}

	return dist;
};