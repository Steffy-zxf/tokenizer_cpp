#include <iostream>
#include <string>
#include "tokenizer.h"

int main() {
    FullTokenizer* pTokenizer = nullptr;

    try {
        pTokenizer = new FullTokenizer("bert-base-chinese-vocab.txt.txt");
    }
    catch (std::exception& e) {
        std::cerr << "construct FullTokenizer failed" << std::endl;
        return -1;
    }

    std::string line;
    while (std::getline(std::cin, line)) {
        auto tokens = pTokenizer->tokenize(line);
        auto ids = pTokenizer->convertTokensToIds(tokens);
        std::cout << "#" << convertFromUnicode(boost::join(tokens, L" ")) << "#" << "\t";
        for (size_t i = 0; i < ids.size(); i++) {
            if (i!=0) std::cout << " ";
            std::cout << ids[i];
        }
        std::cout << std::endl;
    }
    
    return 0;
}

