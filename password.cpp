#include <cstdlib>
#include <iostream>
#include <random>
std::string genPassword(int length) {

    char foo[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                  'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '"', '@', '?',
                  '$', '&', '%', '_', '#', '*', '^', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    std::random_device rd;
    srand(rd.operator()());
    for (int y = 0; y < length; ++y) {
        std::cout << foo[random() % 73];
    }


}

int main() {

    while (true) {

        std::cout << "\nHello! How long would you like your password to be?\n";
        std::cout << "Length: ";
        int length;
        std::cin >> length;
        std::cout << "\nYour password is: " << genPassword(length) << std::endl;
        std::cout << "\nGenerate another password?\n";
        std::cout << "y (yes), c (change length) or any other key to exit: ";
        char x;
        std::cin >> x;
        if (x == 'y') {
            std::cout << "\nYour new password is: " << genPassword(length) << std::endl;
            std::cout << "\nGoing back to the main menu...\n";
        }
        else if (x == 'c') {
            std::cout << "\nOk! How long would you like your new password to be?\n";
            std::cout << "Length: ";
            std::cin >> length;
            std::cout << "Your new password is: " << genPassword(length) << std::endl;
            std::cout << "\nGoing back to the main menu...\n";
        }
        else {
            std::cout << "\nNice to see you! Bye :)";
            break;
        }
    }
}
