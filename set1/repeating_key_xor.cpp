#include <string>
#include <iostream>
#include <fstream>

std::string byteArrayToHex(const char * const byteArray, int arrSize);

char *exor(const char * const buf1, const char * const buf2, int size); 

int main() {
 
  std::string textToEncrypt;
  std::string fileName;
  std::cout << "Enter file to encrypt:\n";
  std::cin >> fileName;
  std::ifstream file(fileName);
  std::string line;
  while(getline(file, line)) {
    textToEncrypt += line + '\n';
  }
  textToEncrypt.resize(textToEncrypt.size()-1); // ignore last char; why?
  int messageSize = textToEncrypt.size();
  
  std::cout << "Enter key:\n";
  std::string key;
  std::cin >> key;
  while(key.size() < messageSize) {
    key += key;
  }
  key.resize(messageSize);
  
  char *buf3 = exor(textToEncrypt.data(), key.data(), messageSize);
  std::string exorInHex = byteArrayToHex(buf3, messageSize);
  std::cout << exorInHex << '\n';

  delete [] buf3;

  return 0;
}

char *exor(const char * const buf1, const char * const buf2, int size) {
  char *exor = new char[size];
  for(int i = 0; i < size; ++i) {
    exor[i] = buf1[i] ^ buf2[i];
  }
  return exor;
}

char numToHex(int num) {
  if(num >= 10) {
    return 'a' + num - 10;
  }
  return '0' + num;
}

std::string byteArrayToHex(const char * const byteArray, int arrSize) {
  std::string output;
  for(int i = 0; i < arrSize; ++i) {
    output = output + numToHex(byteArray[i] / 16) + numToHex(byteArray[i] % 16); 
  }
  return output;
}

