#include <vector>
#include <queue>

using namespace std;

auto a_star = [](const auto& graph, auto s, auto t, auto f)
{
	const auto& n = graph.size();

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
	auto vis = vector(n, false);

	que.push({ 0 + f(s), 0, s });
	vis[s] = true;

	while (!que.empty())
	{
		auto [f, steps, u] = que.top();
		que.pop();

		if (u == t)
		{
			return steps;
		}

		for (const auto& [v, len] : graph[u])
		{
			if (!vis[v])
			{
				vis[v] = true;
				que.push({ steps + len + dist[v], steps + len, v });
			}
		}
	}

	return -1;
}