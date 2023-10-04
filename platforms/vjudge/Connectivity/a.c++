#include <bits/stdc++.h>

using namespace std;

struct UnionFind
{
	vector<int> data;

	UnionFind(int sz)
	{
		data.assign(sz, -1);
	}

	bool unite(int x, int y)
	{
		x = find(x), y = find(y);
		if(x == y) return(false);
		if(data[x] > data[y]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return(true);
	}

	int find(int k)
	{
		if(data[k] < 0) return(k);
		return(data[k] = find(data[k]));
	}

	int size(int k)
	{
		return(-data[find(k)]);
	}
};

int main(){
	int n,k,l;
	cin >> n >> k >> l;
	UnionFind uf1(n);
	UnionFind uf2(n);
	for (int _ = 0; _ < k; _++){
		int p,q;
		cin >> p >> q;
		p--;
		q--;
		uf1.unite(p,q);
	}
	for (int _ = 0; _ < l; _++){
		int r,s;
		cin >> r >> s;
		r--;
		s--;
		uf2.unite(r,s);
	}
	vector<int> root1(n);
	vector<int> root2(n);
	for (int i = 0; i < n; i++){
		root1[i] = uf1.find(i);
		root2[i] = uf2.find(i);
	}
	map<pair<int,int>, int> group;
	for (int i = 0; i < n; i++){
		group[make_pair(root1[i], root2[i])]++;
	}
	for (int i = 0; i < n; i++){
		cout << group[make_pair(root1[i], root2[i])] << (i == n - 1 ? "\n" : " ");
	}

}
