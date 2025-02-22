#include <iostream>
#include <fstream>
#include <string>


int main() {
	std::cout << "Hello, would you like to encrypt or decrypt a file? e/d " << std::endl;
	std::cout << "Enter Here: ";
	std::cin >> crypt_opt_;
	std::cout << "Please enter a key (positive integer): "; << std::endl;
	std::cin >> key_;
	std::cout << "Enter the name of the file you wish to input: " << std::endl;
	std::cin >> input_file_;
	std::cout << "Enter the name of the file you wish to output: " << std::endl;
	std::cin >> output_file_;
	
	supasecret user_secret(input_file_, output_file_, key_);
	
	if (crypt_opt_ == e) {
		user_secret.encryptFile();
		
	} else if (crypt_opt_ == d) {
		user_secret.decryptFile();
		
	} else {
		cout << "Invalid input." << std::endl;
	}
	
	return 0;
}




