#include <cstdlib>
#include <iostream>
#include <random>


int main() {

    char foo[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','!','"','@','?','$','&','%','_','#','*','^','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    std::random_device rd;
    srand(rd.operator()());
    
    std::cout << "Hello! How long would you like your password to be?\n";
    std::cout << "Length: ";
    int x;
    std::cin >> x;
    std::cout << "Your password is: \n\n";
    
    for(int y = 0; y < x; ++y) {

        std::cout << foo[random()%73];
    }

}
