#include "library.hpp"

using namespace std;

void solve(int N) {
	vector<int> v(N);

	int totalSum = 0;
	for(auto &c : v) {
		cin >> c;
		totalSum += c;
	}

	int partialSum = 0, ans = 0;

	for(int c :  v) {
		partialSum += c;
		ans++;
		if(partialSum == totalSum-partialSum-v[ans]) {
			cout << ans+1 << "\n";
			return;
		}
		if(ans == N-1) break;
	}
	cout << "A cadeira, usa a cadeira!\n";
}

int main ()
{
	int D; cin >> D;

	while(D--) {
		int N; cin >> N;
		solve(N);
	}
}
