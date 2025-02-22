#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class supasecret {
    public:
	supasecret(const std::string& input_file_, const std::string& output_file_, size_t user_key_ = 0): 
	 input_file_name_(input_file_), output_file_name_(output_file_), key_(user_key_) {}
	
	
    void encryptFile() {
        std::ifstream inputFile(input_file_name_);
        std::ofstream outputFile(output_file_name_);
        if (!inputFile.is_open() || !outputFile.is_open() ) {
            std::cerr << "Error: Try again, unable to open your file." << std::endl;
            return;
        }

        std::string line_;
        while (getline(inputFile, line_)) {
            outputFile << this->encryption(line_, key_) << std::endl;
        }

        inputFile.close();
        outputFile.close();
    }
	
	
    void decryptFile() {
        std::ifstream inputFile(input_file_name_);
        std::ofstream outputFile(output_file_name_);
        if (!inputFile.is_open() || !outputFile.is_open() ) {
            std::cerr << "Error: Try again, unable to open your file." << std::endl;
            return;
        }

        std::string line_;
        while (getline(inputFile, line_)) {
            outputFile << this->decryption(line_, key_) << std::endl;
        }

        inputFile.close();
        outputFile.close();
    }
	
	
    private:
    std::string input_file_name_;
    std::string output_file_name_;
    size_t key_;
    
    std::string encryption(const std::string& plaintext_, size_t key_) {
		std::string encryptedtext_ = plaintext_;
		int left = 0, right = encryptedtext_.length() - 1;
		while (left < right) {
        std::swap(encryptedtext_[left], encryptedtext_[right]);
        left++;
        right--;
		}
		for (size_t i = 0; i + (2 + key_) < encryptedtext_.length(); i += (3 + key_)) {
			if (i + 1 < encryptedtext_.length()) {
            std::swap(encryptedtext_[i], encryptedtext_[i + 1]);
			}
		}
		for (size_t i = 0; i + (4 + key_) < encryptedtext_.length(); i += (5 + key_)) {
			if (i + 1 < encryptedtext_.length()) {
            std::swap(encryptedtext_[i], encryptedtext_[i + 1]);
			}
		}
		return encryptedtext_;
    }
    
    std::string decryption(const std::string& encryptedtext_, size_t key_) {
		std::string decryptedtext_ = encryptedtext_;
		int left = 0, right = decryptedtext_.length() - 1;
		
		for (size_t i = 0; i + (4 + key_) < decryptedtext_.length(); i += (5 + key_)) {
			if (i + 1 < decryptedtext_.length()) {
            std::swap(decryptedtext_[i], decryptedtext_[i + 1]);
			}
		}
		for (size_t i = 0; i + (2 + key_) < decryptedtext_.length(); i += (3 + key_)) {
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
    
};
