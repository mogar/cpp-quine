#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
std::vector<std::string> dna {
"#include <fstream>"
"#include <iostream>"
"#include <string>"
"#include <vector>"
"#include <regex>"
"std::vector<std::string> dna {"
"magic"
"};"
"int main(int argc, char ** argv)"
"{"
"    std::ofstream child;"
"    child.open(\"cpp_quine_child.cpp\");"
"    for (int i = 0; i < dna.size(); i++) {"
"	if (dna[i].compare(\"magic\") == 0) {"
"            for (int k = 0; k < dna.size(); k++) {"
"                std::string p = std::regex_replace(dna[k], std::regex(\"\\\\\\\\\"), \"\\\\\");"
"                p = std::regex_replace(p, std::regex(\"\\"\"), \"\\\\"\");"
"                child << \"\\"\" << p << \"\\"\" << std::endl;"
"            }"
"        } else {"
"            child << dna[i] << std::endl;"
"        }"
"    }"
"    child.close();"
"    std::cout << \"quines be quining\" << std::endl;"
"    return 0;"
"}"
};
int main(int argc, char ** argv)
{
    std::ofstream child;
    child.open("cpp_quine_child.cpp");
    for (int i = 0; i < dna.size(); i++) {
	if (dna[i].compare("magic") == 0) {
            for (int k = 0; k < dna.size(); k++) {
                std::string p = std::regex_replace(dna[k], std::regex("\\\\\\\\"), "\\\\");
                p = std::regex_replace(p, std::regex("\""), "\\\"");
                child << "\"" << p << "\"" << std::endl;
            }
        } else {
            child << dna[i] << std::endl;
        }
    }
    child.close();
    std::cout << "quines be quining" << std::endl;
    return 0;
}
