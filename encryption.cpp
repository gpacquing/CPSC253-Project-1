#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class encryption {
	
	public:
	
	string encryption(const string& plaintext_) {
		string encryptedtext_ = plaintext_;
		int left = 0, right = encryptedtext_.length() - 1;
		while (left < right) {
        std::swap(encryptedtext_[left], encryptedtext_[right]);
        left++;
        right--;
		}
		for (size_t i = 0; i + 2 < encryptedtext_.length(); i += 3) {
			if (i + 1 < encryptedtext_.length()) {
            std::swap(encryptedtext_[i], encryptedtext_[i + 1]);
			}
		}
		for (size_t i = 0; i + 4 < encryptedtext_.length(); i += 5) {
			if (i + 1 < encryptedtext_.length()) {
            std::swap(encryptedtext_[i], encryptedtext_[i + 1]);
			}
		}
		return encryptedtext_;
    }
		
		
		
	}
	
	
	string decryption(const string& encryptedtext_) {
		decryptedtext_ = encryptedtext_;
		int left = 0, right = decryptedtext_.length() - 1;
		
		for (size_t i = 0; i + 4 < decryptedtext_.length(); i += 5) {
			if (i + 1 < decryptedtext_.length()) {
            std::swap(decryptedtext_[i], decryptedtext_[i + 1]);
			}
		}
		for (size_t i = 0; i + 2 < decryptedtext_.length(); i += 3) {
			if (i + 1 < decryptedtext_.length()) {
            std::swap(decryptedtext_[i], decryptedtext_[i + 1]);
			}
		}
		while (left < right) {
        std::swap(decryptedtext_[left], decryptedtext_[right]);
        left++;
        right--;
		}
		return decryptedtext_;
		
		
	}
	
	void encryptfile() {
		
		
		
	}
	
	
	void decryptfile() {
		
	
	}
	
	
	
	
	private:
		
	
	
	
};
