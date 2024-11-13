#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <stdexcept>

std::string generatePassword(int length) {
    if (length < 8) {
        throw std::invalid_argument("Password length must be at least 8 characters.");
    }

    const std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string lower = "abcdefghijklmnopqrstuvwxyz";
    const std::string digits = "0123456789";
    const std::string special = "!@#$%^&*()-_=+[]{};:,.<>?";
    const std::string all_chars = upper + lower + digits + special;

    // Costly, platform dependent RNG 
    std::random_device rd;

    // Stable and fast PRNG
    std::mt19937 generator(rd());
    
    // Generates random values over a closed interval
    std::uniform_int_distribution<int> upper_dist(0, upper.size() - 1);
    std::uniform_int_distribution<int> lower_dist(0, lower.size() - 1);
    std::uniform_int_distribution<int> digit_dist(0, digits.size() - 1);
    std::uniform_int_distribution<int> special_dist(0, special.size() - 1);
    std::uniform_int_distribution<int> all_dist(0, all_chars.size() - 1);

    std::string password;

    // Ensures password contains at least one character from each category
    password += upper[upper_dist(generator)];
    password += lower[lower_dist(generator)];
    password += digits[digit_dist(generator)];
    password += special[special_dist(generator)];

    // Fills the rest of the password length with random characters from all categories
    for (int i = 4; i < length; ++i) {
        password += all_chars[all_dist(generator)];
    }

    // Uses shuffling algorithm to avoid predictable pattern of characters in the generated password
    std::shuffle(password.begin(), password.end(), generator);

    return password;
}

int main() {
    int length;
    std::cout << "Desired password length (minimum 8): ";
    std::cin >> length;

    try {
        std::string password = generatePassword(length);
        std::cout << "Generated password: " << password << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

