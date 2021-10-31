#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

int main() {
	
	char foo[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','!','"','@','?','$','&','%','_','#','*','^'}; 
		
	srand(time(NULL));

	std::cout << "Hello! How long would you like your password to be?" << std::endl;
	int x;
	std::cin >> x;


	std::cout << "How long should the program wait (in seconds) before generating a new character of your password?" << std::endl;
	int t;
	std::cin >> t;
	


	std::cout << "Your password is: " << std::endl;	

	for(int y = 0; y < x; ++y) {

	usleep(t*1000000);
	std::cout << foo[rand()%46];
	
	}	
	
	std::cout << "\n";


}
