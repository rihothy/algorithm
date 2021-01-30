#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

auto bfs = [](auto& que, auto& book1, auto& book2, auto limit, auto div)
{
	auto max_steps = book1[que.front()];

	while (!que.empty() && book1[que.front()] == max_steps)
	{
		auto temp = que.front();
		que.pop();

		if (book2.count(temp))
		{
			return to_string(book1[temp] + book2[temp]);
		}
		else if (book1[temp] > limit)
		{
			return string("NO ANSWER!");
		}

		auto arr = div(temp);

		for (auto& ele : arr)
		{
			if (!book1.count(ele))
			{
				book1[ele] = book1[temp] + 1;
				que.push(ele);
			}
		}
	}

	return string();
};

auto bid_bfs = [](auto src, auto dst, auto div_src, auto div_dst)
{
	auto que1 = queue<decltype(src)>();
	auto que2 = queue<decltype(src)>();
	auto book1 = unordered_map<decltype(src), int>();
	auto book2 = unordered_map<decltype(src), int>();

	que1.push(src);
	que2.push(dst);
	book1[src] = 0;
	book2[dst] = 0;

	while (!que1.empty() || !que2.empty())
	{
		if (auto ret = bfs(que1, book1, book2, 5, div_src); ret != "")
		{
			return ret;
		}

		if (auto ret = bfs(que2, book2, book1, 5, div_dst); ret != "")
		{
			return ret;
		}
	}

	return string("NO ANSWER!");
};