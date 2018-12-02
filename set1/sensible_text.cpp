#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <algorithm>
#include <numeric>


std::string frequencyOrderString(std::string text) {
  std::map<char, int> charFrequency;
  std::transform(text.begin(), text.end(), text.begin(), ::tolower);
  for(const char &c : text) {
      ++charFrequency[c];
  }

  auto appendKeyChar = [] (std::string acc, std::pair<char, int> key) -> std::string {
    return std::move(acc) + key.first;
  };

  std::string uniqueChars = std::accumulate(std::next(charFrequency.begin()), charFrequency.end(), std::string(1, charFrequency.begin()->first), appendKeyChar);

  auto highFrequencyFirst = 
    [&charFrequency] (const char& c1, const char& c2) -> bool {
      return charFrequency.at(c1) > charFrequency.at(c2);
    };
  std::sort(uniqueChars.begin(), uniqueChars.end(), highFrequencyFirst);
//  std::cout << uniqueChars << '\n';
  return uniqueChars;
}

//TODO penalise if num of diff chars is less
int scoreText(std::string in, std::map<char, int> &naturalFrequency) {
  std::transform(in.begin(), in.end(), in.begin(), ::tolower);
  int score = 0;
  for(const char &c : in) {
    score += naturalFrequency[c]; 
  }
  return score/in.size();
}

std::map<char, int> getMorseLetterFreqMap();

int main() {
  std::string input;
  std::getline(std::cin, input);
  auto naturalFreq = getMorseLetterFreqMap();
  std::cout << scoreText(input, naturalFreq) << '\n';
  return 0;
}


std::map<char, int> getMorseLetterFreqMap() {
  std::map<char, int> freqMap;
  freqMap[' '] = 130;
  freqMap['e'] = 120; freqMap['t'] = 90;
  freqMap['i'] = 80; freqMap['a'] = 80;
  freqMap['n'] = 80; freqMap['o'] = 80;
  freqMap['h'] = 64; freqMap['s'] = 80;
  freqMap['r'] = 62; freqMap['d'] = 44;
  freqMap['u'] = 34; freqMap['l'] = 40;
  freqMap['c'] = 30; freqMap['m'] = 30;
  freqMap['w'] = 20; freqMap['f'] = 25;
  freqMap['y'] = 20; freqMap['g'] = 17;
  freqMap['b'] = 16; freqMap['p'] = 17;
  freqMap['v'] = 12; freqMap['k'] = 8;
  freqMap['j'] = 4; freqMap['q'] = 5;
  freqMap['x'] = 4; freqMap['z'] = 2;
  return freqMap;

}
