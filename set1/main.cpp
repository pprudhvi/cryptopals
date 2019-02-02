#include <iostream>
#include <string>
#include <fstream>

#include "byteUtil.h"
#include "xorCipher.h"

int main() {
  
  // challenge 6 : Break repeating-key XOR
  std::cout << hammingdistance("this is a test", "wokka wokka!!!") << '\n';
//  std::
  
  /*
  // challenge 5: Implement repeating-key XOR
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
  
  std::cout << "Enter key:\n";
  std::string key;
  std::cin >> key;
  
  std::string secret = xorEncrypt(textToEncrypt, key);
  std::cout << byteArrayToHex(secret.data(), secret.size()) << '\n';
  */
  
  /*
  // challenge 4: Single-byte XOR cipher
  int maxScore = 0;
  char key = '\0';
  std::string maxScoreMessage;
  std::string input;
  std::ifstream file("/Users/prudhvi/dev/crypto/cryptopals/set1/4.txt");
  int byteArraySize;
  char * byteArray;
  while(getline(file, input)) {
    byteArray = hexToBinByteArray(input, byteArraySize);
    auto keyMessagePair = breakSingleByteXor(std::string(byteArray, byteArraySize));
    char i = keyMessagePair.first;
    std::string s = keyMessagePair.second;
    int temp = scoreText(s);
    if(temp > maxScore) {
      maxScore = temp;
      key = i;
      maxScoreMessage =  s;
    }
    delete [] byteArray;
  }
  
  std::cout << "Key: " << key << "\nMessage: " << maxScoreMessage << '\n';
   */
/*
 // challenge 3: Single-byte XOR cipher
 std::string hexInput;
 std::cin >> hexInput;
 
 int byteArraySize;
 char * byteArray = hexToBinByteArray(hexInput, byteArraySize);
 std::string cipher(byteArray, byteArraySize);
 delete [] byteArray;
 auto keyAndText = breakSingleByteXor(cipher);
 std::cout << "key: " << keyAndText.first << "\nmessage: " << keyAndText.second << '\n';
 */

/*
 // challenge 2: Fixed XOR
 std::string hexNum1;
 std::cin >> hexNum1;
 
 std::string hexNum2;
 std::cin >> hexNum2;
 
 int binByteArraySize1;
 char *buf1 = hexToBinByteArray(hexNum1, binByteArraySize1);
 int binByteArraySize2;
 char *buf2 = hexToBinByteArray(hexNum2, binByteArraySize2);
 
 if(binByteArraySize1 != binByteArraySize2) {
 std::cout << "buffers are of different sizes\n";
 return -1;
 }
 
 char *buf3 = exor(buf1, buf2, binByteArraySize1);
 std::string exorInHex = byteArrayToHex(buf3, binByteArraySize1);
 std::cout << exorInHex << '\n';
 
 delete [] buf1;
 delete [] buf2;
 delete [] buf3;
 */

/*
 // challenge 1: convert hex to base64
 std::string numInHex;
 std::cin >> numInHex;
 int binByteArraySize;
 char *byteArray = hexToBinByteArray(numInHex, binByteArraySize);
 std::string inBase64 = toBase64(byteArray, binByteArraySize);
 std::cout << inBase64 << '\n';
 delete [] byteArray;
 */

return 0;
}
