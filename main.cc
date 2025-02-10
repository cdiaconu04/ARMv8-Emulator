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
    int PC = 0; // Program counter
    vector<int> registers(32, 0);
    vector<int> memory(4096, 0);
    vector<string> instructions;

    string line = "";
    while (getline(cin, line)) {
        instructions.emplace_back(line);
    }

    for (auto& instr : instructions) {
        istringstream iss {instr};
        string instrName;
        iss >> instrName;

        int reg1;
        int reg2;
        int reg3;
        int opcode;

        if (instrName == "ADD") {
            iss >> reg1 >> reg2 >> reg3;
            registers[reg1] = registers[reg2] + registers[reg3];
            PC += 4;
        } else if (instrName == "ADDI") {

        } else if (instrName == "SUB") {

        } else if (instrName == "SUBI") {

        } else if (instrName == "LDUR") {

        } else if (instrName == "STUR") {

        } else if (instrName == "CBZ") {

        } else if (instrName == "CBNZ") {

        } else if (instrName == "B") {

        } else {
            cerr << "ERROR: Invalid instruction" << endl;
            return 0;
        }
    }

    print(registers, PC);
}

