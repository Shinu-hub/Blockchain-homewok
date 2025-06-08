#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Structs for validators
struct Validator {
    string name;
    int power; // for PoW
    int stake; // for PoS
};

int main() {
    srand(time(0));

    // Create validators
    Validator miner1 = {"Miner1", rand() % 100};
    Validator miner2 = {"Miner2", rand() % 100};
    Validator miner3 = {"Miner3", rand() % 100};

    Validator staker1 = {"Staker1", 0, rand() % 100};
    Validator staker2 = {"Staker2", 0, rand() % 100};
    Validator staker3 = {"Staker3", 0, rand() % 100};

    vector<string> delegates = {"Alice", "Bob", "Charlie"};
    vector<int> votes = {rand() % 100, rand() % 100, rand() % 100};

    // PoW: highest power wins
    Validator powWinner = miner1;
    if (miner2.power > powWinner.power) powWinner = miner2;
    if (miner3.power > powWinner.power) powWinner = miner3;
    cout << "PoW Selected: " << powWinner.name << " with power " << powWinner.power << endl;
    cout << "Logic: Selected validator with highest computational power.\n\n";

    // PoS: highest stake wins
    Validator posWinner = staker1;
    if (staker2.stake > posWinner.stake) posWinner = staker2;
    if (staker3.stake > posWinner.stake) posWinner = staker3;
    cout << "PoS Selected: " << posWinner.name << " with stake " << posWinner.stake << endl;
    cout << "Logic: Selected validator with highest token stake.\n\n";

    // DPoS: most votes
    int maxVotes = votes[0], index = 0;
    for (int i = 1; i < 3; i++) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            index = i;
        }
    }
    cout << "DPoS Selected: " << delegates[index] << " with votes " << votes[index] << endl;
    cout << "Logic: Selected delegate based on most votes by token holders.\n";

    return 0;
}