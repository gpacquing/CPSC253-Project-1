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
    
	int main() {
		std::string crypt_opt_;
		size_t key_;
		int temp_key_;
		std::string input_file_;
		std::string output_file_;
	
		std::cout << "Hello, would you like to encrypt or decrypt a file? e/d " << std::endl;
		std::cout << "Enter Here: ";
		std::cin >> crypt_opt_;
		if (crypt_opt_ != "e" && crypt_opt_ != "d") {
			std::cout << "Invalid input. Options are e to encrypt or d to decrypt a file.";
			return 1;
		}
		std::cout << "Please enter a key (positive integer): " << std::endl;
		std::cin >> temp_key_;
		if (temp_key_ <= 0) {
			std::cout << "Invalid key. Key must be a positive integer." << std::endl;
			return 1;
		}
		key_ = static_cast<size_t>(temp_key_);
		std::cout << "Enter the name of the file you wish to input: " << std::endl;
		std::cin >> input_file_;
		std::cout << "Enter the name of the file you wish to output: " << std::endl;
		std::cin >> output_file_;
		
		supasecret user_secret(input_file_, output_file_, key_);
		
		if (crypt_opt_ == "e") {
			user_secret.encryptFile();
			
		} else if (crypt_opt_ == "d") {
			user_secret.decryptFile();
			
		} else {
			std::cout << "Invalid input." << std::endl;
			return 1;
		}
		
		return 0;
	}





