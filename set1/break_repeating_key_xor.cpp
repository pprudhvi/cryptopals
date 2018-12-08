#include <string>
#include <iostream>

int numOfOnes(int num) {
  int ones = 0;
  while(num > 0) {
    ones += num%2;
    num = num / 2;
  }
  return ones;
}

int differentBits(char c1, char c2) {
  char c = c1 ^ c2;
  return numOfOnes(c);
}

int hammingdistance(std::string str1, std::string str2) {
  if(str1.size() > str2.size()) {
    return hammingdistance(str2, str1);
  }
  int distance = 0;
  for(int i = 0; i < str1.size(); ++i) {
    distance += differentBits(str1[i], str2[i]);
  }
  distance += (str2.size() - str1.size()) * 8;
  return distance;
}

int main() {
  std::cout << hammingdistance("this is a test", "wokka wokka!!!") << '\n';
  return 0;
}
