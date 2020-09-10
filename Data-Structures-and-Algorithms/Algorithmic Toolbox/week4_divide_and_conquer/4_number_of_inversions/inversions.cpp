#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &a, vector<int> &b, int left, int mid, int right){
	
  long long number_of_inversions = 0;
  int i = left;
  int j = mid ;
  int k = left;
  
  while(i <= mid - 1 && j <= right){
    if(a[i] <= a[j]){
	  b[k] = a[i];
	  i++;
	}
		
	else{
	  b[k] = a[j];
	  j++;
	  number_of_inversions += mid - i;
	  // https://www.geeksforgeeks.org/counting-inversions/
	}
	k++;
  }
	
  if(i > mid - 1){
    while(j <= right){
	  b[k] = a[j];
	  k++;
	  j++;
	}
  }
	
  else{
    while(i <= mid - 1){
	  b[k] = a[i];
	  k++;
	  i++;
    }
  }
  
  for(i = left; i <= right; i++)
	  a[i] = b[i];
	  
  return number_of_inversions;
 				
}

// Here number of inversions is similar to merge sort
// This function returns number of inversions instead of returning the sorted array in O(nlogn)

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left ) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave + 1 , right);
  //write your code here
  number_of_inversions += merge(a, b, left, ave + 1 , right);
  
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}
