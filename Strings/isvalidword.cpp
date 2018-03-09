

#include <iostream>
#include <string>
#include <algorithm>

//dummy class to validate the word
class Dictionary {
    
public:
    Dictionary() : isword(false) {}
    bool isValidWord(std::string word) {
        isword = !isword;
        return isword;
    }
private:
    bool isword;
    
};

int main(int argc, const char * argv[]) {
   
    std::string input;
    std::cin >> input;
    
    Dictionary d;
    int len = (int)input.length();
    //generate all the substrings here
    for(int i = 0; i < len; i++) {
        for(int j = i; j < len; j++) {
            std::string substring = input.substr(i,len-j);
            if(d.isValidWord(substring)) {
                std::cout << substring << std::endl;
            }
            else {
                std::cout << substring << "\n";
            }
        }
    }
    
    return 0;
}

