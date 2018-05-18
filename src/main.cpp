#include "sentenceGenerator.h"

int main(int argc, char *argv[]) {  
    string input;
    std::cout << "Enter your #: ";
    std::cin >> input;  
    SentenceGenerator sentGen(input);
    // SentenceGenerator sentGen("2063657830");
    sentGen.generate();
    sentGen.printBestSentences();
}
