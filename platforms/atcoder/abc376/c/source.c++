#include "library.hpp"

using namespace std;

const int oo = 1e9;

using ll = long long;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;
typedef vector<int> vi;
#define pb push_back
#define ln "\n"

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N; cin >> N;
  vi toys(N, 0), boxes(N-1, 0);

  for(auto &x : toys) cin >> x;
  for(auto &x : boxes) cin >> x;

  stack<int> ans;

  sort(toys.rbegin(), toys.rend());
  sort(boxes.rbegin(), boxes.rend());

  int i = 0, j = 0;
  while(1) {
    if(i == N) break;
    if (toys[i] <= boxes[j])
	{
		i++, j++;
		continue;
	}
    ans.push(toys[i]);
    i++;
  }

  if(ans.size() > 1) cout << "-1" << ln;
  else cout << ans.top() << ln;

  return 0;
}
