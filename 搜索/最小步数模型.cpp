#include <unordered_map>
#include <climits>
#include <queue>

using namespace std;

auto shortest_path = [](auto src, auto dst, auto div)
{
	auto que = queue<decltype(src)>();
	auto book = unordered_map<decltype(src), int>();

	que.push(src);
	book[src] = 0;

	while (!que.empty())
	{
		auto src = que.front();
		que.pop();

		if (src == dst)
		{
			return book[dst];
		}

		auto arr = div(src);

		for (const auto& ele : arr)
		{
			if (!book.count(ele))
			{
				book[ele] = book[src] + 1;
				que.push(ele);
			}
		}
	}

	return INT_MAX;
};