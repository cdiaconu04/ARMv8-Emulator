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

    int len = instructions.size();

    for (int i = 0; i <= len; ++i) {
        istringstream iss {instructions[i]};
        string instrName;
        iss >> instrName;

        string reg1, reg2, reg3, opcode;

        int reg1num, reg2num, reg3num, opcodenum;

        if (instrName == "ADD") {
            iss >> reg1 >> reg2 >> reg3;

            reg1num = stoi(reg1.substr(1));
            reg2num = stoi(reg2.substr(1)); 
            reg3num = stoi(reg3.substr(1));

            registers[reg1num] = registers[reg2num] + registers[reg3num];
            PC += 4;
        } else if (instrName == "ADDI") {
            iss >> reg1 >> reg2 >> opcode;

            reg1num = stoi(reg1.substr(1));
            reg2num = stoi(reg2.substr(1));
            opcodenum = stoi(opcode);

            registers[reg1num] = registers[reg2num] + opcodenum;
            PC += 4;
        } else if (instrName == "SUB") {
            iss >> reg1 >> reg2 >> reg3;

            reg1num = stoi(reg1.substr(1));
            reg2num = stoi(reg2.substr(1)); 
            reg3num = stoi(reg3.substr(1));

            registers[reg1num] = registers[reg2num] - registers[reg3num];
            PC += 4;
        } else if (instrName == "SUBI") {
            iss >> reg1 >> reg2 >> opcode;

            reg1num = stoi(reg1.substr(1));
            reg2num = stoi(reg2.substr(1));
            opcodenum = stoi(opcode);

            registers[reg1num] = registers[reg2num] - opcodenum;
            PC += 4;
        } else if (instrName == "LDUR") {
            iss >> reg1 >> reg2 >> opcode;

            reg1num = stoi(reg1.substr(1));
            reg2num = stoi(reg2.substr(1));
            opcodenum = stoi(opcode);

            memory[registers[reg2num] + opcodenum] = registers[reg1num];
            PC += 4;
        } else if (instrName == "STUR") {
            iss >> reg1 >> reg2 >> opcode;

            reg1num = stoi(reg1.substr(1));
            reg2num = stoi(reg2.substr(1));
            opcodenum = stoi(opcode);

            registers[reg1num] = memory[registers[reg2num] + opcodenum];
            PC += 4;
        } else if (instrName == "CBZ") {
            iss >> reg1 >> opcode;

            reg1num = stoi(reg1.substr(1));
            opcodenum = stoi(opcode);

            if (registers[reg1num] == 0) {
                PC = opcodenum;
                i = opcodenum / 4;
            } else {
                PC += 4;
            }
        } else if (instrName == "CBNZ") {
            iss >> reg1 >> opcode;

            reg1num = stoi(reg1.substr(1));
            opcodenum = stoi(opcode);

            if (registers[reg1num] != 0) {
                PC = opcodenum;
                i = opcodenum / 4;
            } else {
                PC += 4;
            }
        } else if (instrName == "B") {
            iss >> opcode;

            opcodenum = stoi(opcode);
            
            i = opcodenum / 4;
            PC = opcodenum;
        } else {
            cerr << "ERROR: Invalid instruction" << endl;
            return 0;
        }
    }

    print(registers, PC);
}

