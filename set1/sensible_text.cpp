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
