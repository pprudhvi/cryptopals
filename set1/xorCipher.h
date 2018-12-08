//
//  xorCipher.h
//  cryptopals
//
//  Created by prudhvi on 08/12/18.
//  Copyright © 2018 crypto. All rights reserved.
//

#ifndef xorCipher_h
#define xorCipher_h

std::pair<char, std::string> breakSingleByteXor(std::string input);
int scoreText(std::string in);
std::string xorEncrypt(std::string message, std::string key);


#endif /* xorCipher_h */
