#include "library.hpp"

using namespace std;
int G;

bool compare(int r, int s) {
	int dist_r = abs(r - G);
	int dist_s = abs(s - G);

	if(dist_r == dist_s) return r < s;

	return dist_r < dist_s;
}

int main ()
{
	int R, S; cin >> R >> S;

	vector<int> r(R), s(S);

	for (auto &c : r) cin >> c;
	for (auto &c : s) cin >> c;
	
	int B; cin >> B >> G;
	
	sort(r.begin(), r.end(), compare);
	sort(s.begin(), s.end(), compare);

	for(int i = 0; i < B; i++) 
		if(i == B-1) cout << r[i] << "\n";
		else  cout << r[i] << " ";
	
	for(int i = 0; i < B; i++) 
		if(i == B-1) cout << s[i] << "\n";
		else  cout << s[i] << " ";

	return 0;
}
