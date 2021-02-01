#include <algorithm>
#include <vector>

using namespace std;

auto dfs1 = [](auto& arr, auto& book, auto i, auto sum)
{
	if (sum > w)
	{
		return;
	}

	if (i == arr.size())
	{
		book.push_back(sum);
	}
	else
	{
		dfs1(arr, book, i + 1, sum + arr[i]);
		dfs1(arr, book, i + 1, sum);
	}
};

auto dfs2 = [](auto& arr, auto& book, auto& ans, auto i, auto sum)
{
	if (sum > w)
	{
		return;
	}

	if (i == arr.size())
	{
		if (auto iter = lower_bound(book.begin(), book.end(), w - sum, greater<int>()); iter != book.end())
		{
			sum += *iter;
		}

		ans = max(ans, sum);
	}
	else
	{
		dfs2(arr, book, ans, i + 1, sum + arr[i]);
		dfs2(arr, book, ans, i + 1, sum);
	}
};

auto bid_dfs = [](auto& arr)
{
	sort(arr.begin(), arr.end(), greater<int>());

	auto a = vector(arr.begin(), arr.begin() + arr.size() / 2);
	auto b = vector(arr.begin() + arr.size() / 2, arr.end());
	auto book = vector(0, 0);
	auto ans = 0ll;

	dfs1(b, book, 0, 0ll);

	book = vector(book.begin(), unique(book.begin(), book.end()));

	sort(book.begin(), book.end(), greater<int>());

	dfs2(a, book, ans, 0, 0ll);

	return ans;
};