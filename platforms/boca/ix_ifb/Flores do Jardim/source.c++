#include "library.hpp"

using namespace std;

using ii = pair<int, int>;

 void dfs(vector<vector<int>> &adj, vector<bool> &visited, int u, function<void(int)> process) {
		if(visited[u]) return; 

		visited[u] = true; 

		process(u); 

		for(auto v : adj[u]) dfs(adj, visited, v, process);
 }

bool has_cycle(vector<vector<int>> &adj, vector<bool> &visited, int N) {

	for(int u = 1; u <= N; ++u)
		if(not visited[u]) {
			vector<int> cs;
			size_t edges = 0; 

			dfs(adj, visited, u, [&](int k) {
				cs.push_back(k); 

				for(const auto& v : adj[k])
					edges += (visited[v] ? 0 : 1);
			}); 

			if (edges >= cs.size()) return true;
		}
	return false;
}


int connected_component(vector<vector<int>> &adj,vector<bool> &visited, int N) {
       int count = 0;

       for(int u = 1; u <= N; ++u) {
             if(not visited[u])
                  if (has_cycle(adj, visited, N))
				{
					debug(u);
						++count;
				}
      } 

      return count;
}

int main ()
{
	int N, M; cin >> N >> M; 

	vector<vector<int>> adj(N+1, vector<int>());

	for(int i = 0; i <  M; i++) {
		int v, w; cin >> v >> w;
		adj[v].push_back(w);
		adj[w].push_back(v);
	}


	vector<bool> visited(N+1, false);

	print << connected_component(adj, visited, N) << endl;
	
}
