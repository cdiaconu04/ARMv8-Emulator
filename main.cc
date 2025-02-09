#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void print(vector<int>& registers, int PC) {
    int len = registers.size();
    for (int i = 0; i < len; i++) {
        cout << "X" << i << ": " << registers[i];
        if (i + 1 % 5 == 0) {
            cout << endl;
        }
    }
    cout << endl;
    cout << "PC: " << PC << endl;
}

int main() {
    int PC = 0;
    vector<int> registers(32, 0);
    vector<int> memory(4096, 0);
    vector<string> instructions;

    string line = "";
    while (getline(cin, line)) {
        instructions.emplace_back(line);
    }

    


}

