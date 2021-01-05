#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::sort;

bool isGreaterorEqual(string digit , string maxDigit)
{
  string A , B;
  A = digit.append(maxDigit);
  B = maxDigit.append(digit);
  
  if(A.compare(B) > 0)
	return true;
  return false;
}
	
	
  string largest_number(vector<string> a) {
  //write your code here
  
  std::stringstream ret;

  sort(a.begin(), a.end(), isGreaterorEqual);
  
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  

  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
