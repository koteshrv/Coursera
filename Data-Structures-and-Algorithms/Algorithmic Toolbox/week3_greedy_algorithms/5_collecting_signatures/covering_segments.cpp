#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using std::sort;

struct Segment {
  int start, end;
};

bool comparator(Segment a, Segment b){
	return (a.end < b.end);
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  
  sort(segments.begin(), segments.end(), comparator);
  
  int a = segments[0].end;
  points.push_back(a);
  
  for (size_t i = 1; i < segments.size(); ++i) {
	  if(a < segments[i].start || a > segments[i].end){
		a = segments[i].end;
		points.push_back(a);
	}
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
