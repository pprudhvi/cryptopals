/*  take lower 4 bits of each char in the string
 *  and create a byte/bit array
 *  6 bits make up a digit in base64 
 **/


#include <iostream>
#include <string>

char base64Char(int num) {
  if(num == 62) {
    return '+';
  }
  if(num == 63) {
    return '/';
  }
  if(num <= 25) {
    return num - 0 + 'A';
  }
  if(num <= 51) {
    return num - 26 + 'a';
  }
  return num - 52 + '0';
}

std::string toBase64(char *binaryByteArray, int size) {
  std::string answer;
  int carryOver = 0;
  int bitsFromNext = 0;
  int current;
  for(int i = 0; i < size; ++i) {
    switch(bitsFromNext) {
      case 0:
        if(carryOver != 0) {
          answer += base64Char(carryOver);
        }
        current = binaryByteArray[i] / 4;
        carryOver = binaryByteArray[i] & 3;
        bitsFromNext = 4;
        break;
      case 2:
        current = carryOver * 4 + binaryByteArray[i] / 64 ;
        carryOver = binaryByteArray[i] & ((1<<6) - 1);
        bitsFromNext = 0;
        break;
      case 4:
        current = carryOver * 16 + binaryByteArray[i] / 16;
        carryOver = binaryByteArray[i] & ((1<<4) - 1);
        bitsFromNext = 2;
        break;
    }
    answer += base64Char(current);
  }

  if(size*8%6 == 2) { // equiv to case 4 above
    answer += base64Char(carryOver*16);
    answer += "==";
  } else if(size*8%6 == 4) { // equiv to case 2 above
    answer += base64Char(carryOver*4);
    answer += "=";
  } else {
    answer += base64Char(carryOver);
  }
  return answer;
}

char hexToChar(char hex) {
  if(hex >= 'a') {
    return hex - 'a' + 10;
  }
  return hex - '0';
}


// bigendian
char *hexToBinByteArray(std::string numInHex, int &sizeOfOutput) {
  int inputSize = numInHex.size();
  int numOfBits = inputSize * 4;
  int numOfBytes = numOfBits / 8;
  sizeOfOutput = numOfBytes;
  char *output = new char[numOfBytes];
  for(int i = 0; i < numOfBytes; ++i) {
    output[i] = hexToChar(numInHex[2*i])*16 + hexToChar(numInHex[2*i+1]);
  }
  return output;
}

int main() {
  std::string numInHex;
  std::cin >> numInHex;
  int binByteArraySize;
  std::string inBase64 = toBase64(hexToBinByteArray(numInHex, binByteArraySize), binByteArraySize); // memory leak
  std::cout << inBase64 << '\n';
  return 0;
}
