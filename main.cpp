#include <iostream>
#include <cctype>

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "funcs.h"

int main() {
    /*std::string text, code; 
    while(std::getline(std::cin, text)) {
        code += text + "\n";
    }
    std::cout << indent(code) << std::endl;
    */
    //std::string code = receiveInput(std::cin);
    //std::cout << code << std::endl;
    std::string name, code;
    std::cin >> name;
    code = receiveFile(name);
    std::cout << indent(code) << std::endl;
    
    return 0;
}
