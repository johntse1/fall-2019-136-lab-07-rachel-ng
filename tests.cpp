#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "funcs.h"

TEST_CASE("removeLeadingSpaces"){
    CHECK(removeLeadingSpaces("                int main(){")=="int main(){");
    CHECK(removeLeadingSpaces("int x = 1; ")=="int x = 1; ");
    CHECK(removeLeadingSpaces("          cout << endl;")=="cout << endl;");
}

TEST_CASE("countChar"){
    CHECK(countChar("{{}}{{}}", '{')==4);
    CHECK(countChar("hello world", 'l')==3);
    CHECK(countChar("dogs",'g')==1);
}

TEST_CASE("tabs"){
    CHECK(tabs(1)=="\t");
    CHECK(tabs(3)=="\t\t\t");
    CHECK(tabs(9)=="\t\t\t\t\t\t\t\t\t");
}

std::istringstream iss("                int main(){ \n           // Hi, I'm a program!\nint x = 1; \n    for(int i = 0; i < 10; i++) {\ncout << i;\n          cout << endl;\n }\n    }");

TEST_CASE("indent"){
    CHECK(indent("                int main(){ \n           // Hi, I'm a program!\nint x = 1; \n    for(int i = 0; i < 10; i++) {\ncout << i;\n          cout << endl;\n }\n    }")==receiveFile("code-indented.txt"));
    CHECK(indent(receiveInput(iss))==receiveFile("code-indented.txt"));
    CHECK(indent(receiveFile("code.txt"))==receiveFile("code-indented.txt"));
}


