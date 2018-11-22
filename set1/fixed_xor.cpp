
#include <iostream>
#include <string>


/*
 * if numInHex has odd number of digits, last digit is ignored
 * return byte array in big endian format
 */
char *hexToBinByteArray(const std::string numInHex, int &sizeOfOutput); 
std::string byteArrayToHex(const char * const byteArray, int arrSize);

char *exor(const char * const buf1, const char * const buf2, int size); 

int main() {
 
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

char hexToNum(char hex) {
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
    output[i] = hexToNum(numInHex[2*i]) * 16 + hexToNum(numInHex[2*i + 1]);
  }
  return output;
}
