//
//  byteUtil.h
//  set1
//
//  Created by prudhvi on 08/12/18.
//  Copyright © 2018 crypto. All rights reserved.
//

#ifndef byteUtil_h
#define byteUtil_h


std::string toBase64(const char * const binaryByteArray, int size);

/*
 * if numInHex has odd number of digits, last digit is ignored
 * return byte array in big endian format
 */
char *hexToBinByteArray(const std::string numInHex, int &sizeOfOutput);

// 
char *exor(const char * const buf1, const char * const buf2, int size);

std::string byteArrayToHex(const char * const byteArray, int arrSize);



#endif /* byteUtil_h */
