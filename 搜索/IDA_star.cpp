#include <unordered_map>

using namespace std;

auto dfs = [](auto src, auto div, auto f, auto& book, auto max_depth, auto depth)
{
	if (f(src) == 0)
	{
		return true;
	}
	else if (f(src) + depth <= max_depth)
	{
		auto arr = div(src);

		for (auto& ele : arr)
		{
			if (!book[ele])
			{
				book[ele] = true;

				if (dfs(ele, div, f, book, max_depth, depth + 1))
				{
					return true;
				}

				book[ele] = false;
			}
		}
	}

	return false;
};

auto IDA_star = [](auto src, auto div, auto f)
{
	auto depth = 0;
	auto book = unordered_map<decltype(src), bool>();

	while (!dfs(src, div, f, book, depth, 0))
	{
		++depth;
	}

	return depth;
};