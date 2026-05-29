#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)4e18;

struct Edge {
    int to;
    int w;
};

static vector<Edge> g[100001];
static ll dista[100001];
static int indeg[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, C;
    ll K;

    cin >> N >> M >> C >> K;

    vector<int> people(C);

    for (int i = 0; i < C; i++)
        cin >> people[i];

    for (int i = 1; i <= N; i++) {
        g[i].clear();
        indeg[i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int A, B, D;
        cin >> A >> B >> D;

        g[A].push_back({B, D});
        indeg[B]++;
    }

    // Topological order (necessária!)
    vector<int> topo;
    topo.reserve(N);

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (indeg[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        topo.push_back(v);

        for (auto &e : g[v]) {
            if (--indeg[e.to] == 0)
                q.push(e.to);
        }
    }

    vector<vector<ll>> Dpp(C, vector<ll>(C, INF));
    vector<ll> DtoN(C, INF);

    unordered_map<int,int> idx;
    idx.reserve(C * 2);

    for (int i = 0; i < C; i++)
        idx[people[i]] = i;

    for (int s = 0; s < C; s++) {

        fill(dista + 1, dista + N + 1, INF);

        int src = people[s];
        dista[src] = 0;

        for (int v : topo) {

            ll dv = dista[v];
            if (dv == INF)
                continue;

            for (const auto &e : g[v]) {

                ll nd = dv + e.w;

                if (nd < dista[e.to])
                    dista[e.to] = nd;
            }
        }

        for (int j = 0; j < C; j++)
            Dpp[s][j] = dista[people[j]];

        DtoN[s] = dista[N];
    }

    int start = idx[1];

    vector<ll> best(C, INF);

    priority_queue<
        pair<ll,int>,
        vector<pair<ll,int>>,
        greater<pair<ll,int>>
    > pq;

    best[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {

        auto [cur, u] = pq.top();
        pq.pop();

        if (cur != best[u])
            continue;

        for (int v = 0; v < C; v++) {

            ll d = Dpp[u][v];

            if (d == INF)
                continue;

            ll cost = max(0LL, d - K);

            if (best[v] > cur + cost) {

                best[v] = cur + cost;
                pq.push({best[v], v});
            }
        }
    }

    ll ans = INF;

    for (int i = 0; i < C; i++) {

        if (best[i] == INF)
            continue;

        if (DtoN[i] == INF)
            continue;

        ans = min(
            ans,
            best[i] + max(0LL, DtoN[i] - K)
        );
    }

    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}

