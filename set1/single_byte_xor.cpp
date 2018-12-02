#include <iostream>
#include <string>
#include <map>

char hexToChar(char hex) {
  if(hex >= 'a') {
    return hex - 'a' + 10;
  }
  return hex - '0';
}

char *hexToBinByteArray(const std::string numInHex, int &sizeOfOutput) {
  int inputSize = numInHex.size();
  int numOfBits = inputSize * 4;
  int numOfBytes = numOfBits / 8;
  sizeOfOutput = numOfBytes;
  char *output = new char[numOfBytes];
  for(int i = 0; i < numOfBytes; ++i) {
    output[i] = hexToChar(numInHex[2*i]) * 16 + hexToChar(numInHex[2*i + 1]);
  }
  return output;
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
  std::cin >> input;
  int byteArraySize;
  char * byteArray = hexToBinByteArray(input, byteArraySize);
  std::cout << "input string:" << std::string(byteArray, byteArraySize) << '\n';
  
  int maxScore = 0;
  char key;
  std::string maxScoreMessage;
  auto naturalFreq = getMorseLetterFreqMap();
  for(char i = 0; i < (char) 126; ++i) {
    std::string s;
    for(int j = 0; j < byteArraySize; ++j) {
      s += byteArray[j] ^ i; 
    }
    int temp = scoreText(s, naturalFreq);
    if(temp > maxScore) {
      maxScore = temp;
      key = i;
      maxScoreMessage =  s;
    }
  }
  std::cout << "Key: " << key << " Message: " << maxScoreMessage << '\n';
  delete [] byteArray;
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
