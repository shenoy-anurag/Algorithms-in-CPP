//
// Union Find in C++ (Connected and disconnected sets)
// 
// Simplest implementation with a quick find but slow connect.
//
// Author : Anurag Shenoy
//

#include <iostream>
using namespace std;

class UF
{
public:
	int n;
	int *arr{ new int[n]{} };

	// my first time learning about dynamic arrays in c++
	void init_arr()
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = i;
		}
	}

	bool unite (int p, int q)
	{
		int x = arr[p];
		int y = arr[q];
		
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == y)
			{
				arr[i] = x;
			}
		}
		return true;
	}

	bool connected(int p, int q)
	{
		if (arr[p] == arr[q])
			return true;
		else
			return false;
	}
};

int main() {
	int n;
	cout << "Enter the number of elements for Union Find: " << flush;
	cin >> n;
	UF uf {n};
	uf.init_arr();
	while(true)
	{
		int x;
		int y;
		cin >> x;
		cin >> y;
		if (!uf.connected(x, y))
		{
			uf.unite(x, y);
			cout << x << " " << y << endl;
		}
		else
			cout << "Connected" << endl;
	}
	return 0;
}







