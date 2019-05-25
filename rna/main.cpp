#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>

void TranscribingDNAintoRNA(std::ifstream &input, std::ofstream &output) {
//    std::string str((std::istreambuf_iterator<char>(input)),
//                    std::istreambuf_iterator<char>());
    char c;
    while (input.good()) {
        input.get(c);
        if (input.fail())
            break;
        output << (c == 'T' ? 'U' : c);
    }
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    TranscribingDNAintoRNA(input, output);

    input.close();
    output.close();
    return 0;
}