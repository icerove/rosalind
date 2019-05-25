#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>

void ComplementingStrandOfDNA(std::ifstream &input, std::ofstream &output) {
//    std::string str((std::istreambuf_iterator<char>(input)),
//                    std::istreambuf_iterator<char>());
    int result[20] = {0};
    char c;
    while (input.good()) {
        input.get(c);
        if (input.fail())
            break;
        result[c-'A']++;
    }
    output << result['A'-'A'] << ' ' << result['C'-'A'] << ' ' << result['G' - 'A'] <<' ' << result['T' - 'A'];
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    ComplementingStrandOfDNA(input, output);

    input.close();
    output.close();
    return 0;
}