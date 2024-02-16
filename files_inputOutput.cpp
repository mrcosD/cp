#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string filename = "hola.txt";

void outputFile () {
    ofstream file;

    file.open(filename, ios::app);
}

void intputFile () {
    ifstream myfile (filename);
}

int main() {
    // ofstream myfile;

    // myfile.open("hola.txt", ios::app);
    // myfile << "hola";
    // myfile.close();

    ifstream myfile ("hola.txt");
    string line;
    while (getline(myfile, line)) cout << line << '\n';
}