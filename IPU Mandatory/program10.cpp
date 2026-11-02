#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    char ch;

    if (!fin) {
        cout << "Error opening input file!";
        return 1;
    }

    if (!fout) {
        cout << "Error opening output file!";
        return 1;
    }

    while (fin.get(ch)) {
        if (!isspace((unsigned char)ch)) {
            fout.put(ch);
        }
    }

    fin.close();
    fout.close();

    cout << "Whitespace characters removed successfully.";
    cout << "\nResult written to output.txt";

    return 0;
}