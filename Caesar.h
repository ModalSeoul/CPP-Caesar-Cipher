#include <iostream>
#include <vector>

#ifndef CAESAR_H
#define CAESAR_H

//////////////////////////////////////////////////////
// Initial Caesar Cipher construction
// Purpose:
//		Prevent string searching of familiar strings
//		when reversing the Gunz executable.
//////////////////////////////////////////////////////
class Caesar {
public:
	Caesar::Caesar();
	char text[100] = { '\0' };
	char cipher[100] = { '\0' };

	// The amount you'd like to shift in the cipher
	int shift_count = 4;
	int get_shift_count() { return shift_count; }
	void set_shift_count(int count) {
		shift_count = count;
	}

	char* encrypt(char* to_encrypt) {
		strcpy_s(text, to_encrypt);
		for (int i = 0; i < strlen(text); i++) {
			text[i] = tolower(text[i]);
			if (text[i] + shift_count > 122)
				cipher[i] = (text[i] + shift_count) - 26;
			else if (text[i] == 32)
				cipher[i] = text[i];
			else if (text[i] == '\0')
				break;
			else
				cipher[i] = text[i] + shift_count;
		}
		return cipher;
	}
	char* decrypt(char* to_decrypt) {
		strcpy_s(text, to_decrypt);
		for (int i = 0; i < strlen(text); i++) {
			text[i] = tolower(text[i]);
			if (text[i] - shift_count < 97)
				cipher[i] = (text[i] - shift_count) + 26;
			else if (text[i] == 32)
				cipher[i] = text[i];
			else if (text[i] == '\0')
				break;
			else
				cipher[i] = text[i] - shift_count;
		}
		return cipher;
	}

};

#endif