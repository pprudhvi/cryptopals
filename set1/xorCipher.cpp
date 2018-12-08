//
//  xorCipher.cpp
//  set1
//
//  Created by prudhvi on 08/12/18.
//  Copyright © 2018 crypto. All rights reserved.
//

#include <utility>
#include <string>
#include <map>

#include "byteUtil.h"
#include "xorCipher.h"


//struct data {
  static std::map<char, int>
//freqMap;
//data() {
 freqMap = {
  {' ',130},
  {'e',120}, {'t',90},
  {'i',80}, {'a',80},
  {'n',80}, {'o',80},
  {'h',64}, {'s',80},
  {'r',62}, {'d',44},
  {'u',34}, {'l',40},
  {'c',30}, {'m',30},
  {'w',20}, {'f',25},
  {'y',20}, {'g',17},
  {'b',16}, {'p',17},
  {'v',12}, {'k',8},
  {'j',4}, {'q',5},
  {'x',4}, {'z',2}
};
//};
//};

//TODO penalise if num of diff chars is less
int scoreText(std::string in) {
  std::transform(in.begin(), in.end(), in.begin(), ::tolower);
  int score = 0;
  for(const char &c : in) {
    score += freqMap[c];
  }
  return score/in.size();
}

std::pair<char, std::string> breakSingleByteXor(std::string input) {
  int maxScore = 0;
  char key;
  std::string maxScoreMessage;
  for(char i = 0; i < (char) 126; ++i) {
    std::string s;
    for(int j = 0; j < input.size(); ++j) {
      s += input[j] ^ i;
    }
    int temp = scoreText(s);
    if(temp > maxScore) {
      maxScore = temp;
      key = i;
      maxScoreMessage =  s;
    }
  }

//  std::cout << "Key: " << key << " Message: " << maxScoreMessage << '\n';
  return std::pair<char, std::string>(key, maxScoreMessage);
}

std::string xorEncrypt(std::string message, std::string key) {
  while(key.size() < message.size()) {
    key += key;
  }
  key.resize(message.size());
  
  char *buf3 = exor(message.data(), key.data(), message.size());
  std::string secret(buf3, message.size());
  delete [] buf3;
  return secret;
}
