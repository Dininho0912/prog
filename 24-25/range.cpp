#include <iostream>
int main() {
  int a, b; 
  std::cin >> a >> b; 
  // TODO: change initial value of i and fix test condition
  for (int i = a; i <= b; i++) {
    std::cout << i << ' ';
  } 
  return 0;
}