#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;

vector<ll> fast_count_segments(vector<ll> starts, vector<ll> ends, vector<ll> points) {
  vector<ll> cnt(points.size());
  //write your code here
  vector <pair<ll,ll>> pts,segments;

  for(ll i = 0; i < points.size(); i++){
    pts.push_back({points[i],i});
  }

  for(ll i = 0; i < starts.size(); i++){
    segments.push_back({starts[i], 1});
    segments.push_back({ends[i]+1, -1});
  }

  sort(segments.begin(),segments.end(),greater<pair<int,int>>());
  sort(pts.begin(),pts.end());

  ll count = 0;

  for (ll i = 0; i < points.size(); i++){
    ll x = pts[i].first;
    while(!segments.empty() && segments.back().first <= x){
      count += segments.back().second;
      segments.pop_back();
    }
    
    cnt[pts[i].second] = count;
  } 
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  ll n, m;
  std::cin >> n >> m;
  vector<ll> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<ll> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<ll> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
  return 0;
}
