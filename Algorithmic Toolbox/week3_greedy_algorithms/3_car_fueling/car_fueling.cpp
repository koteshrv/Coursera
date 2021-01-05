#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int n = stops.size();		

    int numRefills = 0, currentRefill = 0;
    while(currentRefill <= n){
		int lastRefill = currentRefill;
		while(currentRefill <= n && (stops[currentRefill + 1] - stops[lastRefill] <= tank)){
			currentRefill++;
		}
		if(currentRefill == lastRefill)
			return -1;
		
		if(currentRefill <= n)
			numRefills++;
	}
	
	return numRefills;	
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (int i = 0; i < n; ++i){
        cin >> stops.at(i);
	}

	stops.insert(stops.begin(), 0);
	stops.insert(stops.end(), d);
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
