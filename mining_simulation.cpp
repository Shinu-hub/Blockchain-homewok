#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string fakeHash(string input) {
    unsigned int hash = 0;
    for (char c : input)
        hash = (hash * 101 + c) % 10000000;  // lightweight fake hash
    string h = to_string(hash);
    while (h.length() < 7) h = "0" + h;  // pad with zeros
    return h;
}

int main() {
    int nonce = 0, difficulty = 2;  // reduce difficulty to run faster
    string prefix(difficulty, '0');
    string hash;
    time_t start = time(0);

    do {
        nonce++;
        hash = fakeHash("data" + to_string(nonce));
    } while (hash.substr(0, difficulty) != prefix);

    time_t end = time(0);
    cout << "Mined Hash: " << hash << endl;
    cout << "Nonce: " << nonce << endl;
    cout << "Time Taken: " << end - start << " seconds" << endl;

    return 0;
}