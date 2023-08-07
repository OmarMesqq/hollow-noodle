#include <cstdlib>
#include <iostream>
#include <random>

void genPassword(int length) {
    std::string characters = "abcdefghijklmnopqrstuvwxyz0123456789!\"@?$&%_#*^ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::random_device rd;	// Gets a "random" device from OS 
    std::mt19937 gen(rd());	// Uses that device as seed for the Mersenne Twister object 
    std::uniform_int_distribution<int> dis(0, characters.size() - 1); 

    std::string password;
    for (int y = 0; y < length; ++y) {
	    password += characters[dis(gen)];
    }
    std::cout << password << std::endl;
}


void interactive(int lastLength) {
	if (lastLength == 0) {

		std::cout << "\nHow long would you like your password to be?\n";
	        std::cout << "Length: ";
	        int length;
        	std::cin >> length;
	        std::cout << "\nYour password is: ";
		genPassword(length);
	
		std::cout << "\nGenerate another password?\n";
        	std::cout << "y (yes), c (change length) or any other key to exit: ";
		char x; 
		std::cin >> x;

		if (x == 'y') {
			interactive(length);
		}
		else if (x == 'c') {
			std::cout << "New length: ";
			int length;
			std::cin >> length;
			interactive(length);
		}
		else {
			return;	// 1st stop condition
		}
	}
	else {
		std::cout << "Your new password is: ";
		genPassword(lastLength);

		std::cout << "\nGenerate new password?\n";
        	std::cout << "y (yes), c (change length) or any other key to exit: ";
		char x; 
		std::cin >> x;

		if (x == 'y') {
			interactive(lastLength);
		}
		else if (x == 'c') {
			std::cout << "New length: \n";
			int length;
			std::cin >> length;
			interactive(length);
		}
		else {
			return;	// 2nd stop condition
		}
	}
}


int main() {
	interactive(0);
	return 0;
}

