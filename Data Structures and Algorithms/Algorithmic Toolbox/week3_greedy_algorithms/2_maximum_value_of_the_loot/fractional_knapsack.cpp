#include <iostream>
#include <bits/stdc++.h> 
#include <vector>

using namespace std;

int max_index(vector<int>& weights, vector<int>& values) {
    int max_i = 0;
    double max = 0;
    int n = weights.size();

    for (int i = 0; i < n; i++) {
        if (weights[i] != 0 && (double) values[i] / weights[i] > max) {
            max = (double) values[i] / weights[i];
            max_i = i;
        }
    }
    return max_i;
}

double get_optimal_value(int capacity, vector<int>& weights, vector<int>& values) {
  double value = 0.0;

  // write your code here
  
  int n = weights.size();

  for (int i = 0; i < n; i++) {
    if (capacity == 0) 
      return value;
    int index = max_index(weights, values);
    int a = std::min(capacity, weights[index]);
    value += a * (double) values[index] / weights[index];
    weights[index] -= a;
    capacity -= a;
    
   }
  
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
	
  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
