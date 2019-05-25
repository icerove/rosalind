#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>
#include <algorithm>

void TranscribingDNAintoRNA(std::ifstream &input, std::ofstream &output) {
    std::string str((std::istreambuf_iterator<char>(input)),
                    std::istreambuf_iterator<char>());
    reverse(str.begin(), str.end());

    for (auto c: str) {
        switch (c) {
            case 'A':
                output << 'T';
                break;
            case 'T':
                output << 'A';
                break;
            case 'C':
                output << 'G';
                break;
            case 'G':
                output << 'C';
                break;
        }
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