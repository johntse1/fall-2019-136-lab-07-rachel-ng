#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>

std::string removeLeadingSpaces(std::string line) {
    for (int i = 0; i < line.size(); i++) {
        if (!isspace(line[i])) {
            return line.substr(i,line.size() - i);
        }
        else {
            continue;
        }
    }
    return line;
}
int countChar(std::string line, char c) {
    int n = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == c) {
            n++;
        }
    }
    return n;
  }
std::string tabs (int n) {
    std::string t = "";
    for (int i = 0; i < n; i++) {
        t += "\t";
    }
    return t;
}

std::string receiveInput (std::istream& stream){
    std::string text, code;
    while(std::getline(stream, text)) {
        code += text + "\n";
    }
    return code;
}

std::string receiveFile (std::string file) {
    std::ifstream fin(file);
    std::string code, line;
    while (std::getline(fin, line)) {
        code += line + "\n";
    }
    return code;
}

std::string indent (std::string code) {
    std::string s, indented;
    int indent = 0;
    std::istringstream lines(code);
    while(std::getline(lines, s)) {
        std::string copy =s;
        if(copy.find("/*")!=std::string::npos){
          while(copy.find("*/")==std::string::npos){
                std::cout << copy << std::endl;
                std::getline(lines, s);
          }
        }
        else {
        std::string r = removeLeadingSpaces(s);
        int c = r[0] == '}' ? 1 : 0;
        indented += tabs(indent - c) + r + "\n";
        indent += countChar(r,'{') - countChar(r,'}');
      }
    }
    return indented;
}
