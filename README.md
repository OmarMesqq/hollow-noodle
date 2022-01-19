# HollowNoodle
A fast and reliable password generator

# Important note on the entropy of passwords 

Since this software was written using (really!) simple C++ techniques, the "randomness" of generated password might be small. 
This creates a problem since the characters can be averagely predicted by someone with malicious goals.

Due to nature of the entropy "seed" used in this code (it uses the time the software was run on your system), in order to mitigate this issue it is recommended to wait as long as possible when generating a passphrase (3 - 5 seconds should be enough).

As for the length of the password, picking more than 8 or 9 characters should be safe. 
If you really want to keep your passphrases safe, remember to use two factor authentication (2FA) when possible! This adds a new layer someone would have to go through when attacking your credentials.


More reading on: https://en.wikipedia.org/wiki/Entropy_(information_theory) 

Thank you for using my code!
