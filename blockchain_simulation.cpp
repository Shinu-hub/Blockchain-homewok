#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

// Very simple hash generator (not secure, just for simulation)
string simpleHash(const string& input) {
    int hash = 0;
    for (char c : input) {
        hash = (hash * 31 + c) % 100000;
    }
    return to_string(hash);
}

class Block {
public:
    int index;
    string data;
    string previousHash;
    string hash;
    time_t timestamp;

    Block(int i, string d, string prevHash) {
        index = i;
        data = d;
        previousHash = prevHash;
        timestamp = time(0);
        hash = calculateHash();
    }

    string calculateHash() {
        stringstream ss;
        ss << index << timestamp << data << previousHash;
        return simpleHash(ss.str());
    }

    void printBlock() {
        cout << "Block " << index << ":\n";
        cout << "  Data: " << data << "\n";
        cout << "  Hash: " << hash << "\n";
        cout << "  Previous Hash: " << previousHash << "\n\n";
    }
};

int main() {
    vector<Block> chain;

    // Create 3 blocks
    chain.push_back(Block(0, "Genesis Block", "0"));
    chain.push_back(Block(1, "Second Block", chain[0].hash));
    chain.push_back(Block(2, "Third Block", chain[1].hash));

    cout << "✅ Original Blockchain:\n";
    for (auto& block : chain) block.printBlock();

    // Tamper with Block 1
    cout << "⚠ Tampering with Block 1...\n";
    chain[1].data = "Hacked Data";
    chain[1].hash = chain[1].calculateHash();

    cout << "\n❌ Blockchain After Tampering:\n";
    for (auto& block : chain) block.printBlock();

    return 0;
}