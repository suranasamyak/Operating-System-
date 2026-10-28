#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int movement(vector<int> a, int head) {
    int total = 0;
    for (int x : a) {
        total += abs(head - x);
        head = x;
    }
    return total;
}

int main() {
    vector<int> r = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53, n = r.size();

    // FCFS
    int fcfs = movement(r, head);

    // SSTF
    vector<int> s = r;
    int cur = head, sstf = 0;
    while (!s.empty()) {
        int k = 0;
        for (int i = 1; i < s.size(); i++)
            if (abs(s[i] - cur) < abs(s[k] - cur))
                k = i;

        sstf += abs(s[k] - cur);
        cur = s[k];
        s.erase(s.begin() + k);
    }

    // Divide requests for SCAN and C-SCAN
    vector<int> left, right;
    for (int x : r) {
        if (x < head) left.push_back(x);
        else right.push_back(x);
    }
    sort(left.rbegin(), left.rend());
    sort(right.begin(), right.end());

    // SCAN: move towards 0 first
    vector<int> scan = left;
    scan.push_back(0);
    for (int x : right) scan.push_back(x);
    int scanTotal = movement(scan, head);

    // C-SCAN: move towards 199 first
    vector<int> cscan = right;
    cscan.push_back(199);
    cscan.push_back(0);
    for (int x : left) cscan.push_back(x);
    int cscanTotal = movement(cscan, head);

    cout << "FCFS Total Movement: " << fcfs << endl;
    cout << "SSTF Total Movement: " << sstf << endl;
    cout << "SCAN Total Movement: " << scanTotal << endl;
    cout << "C-SCAN Total Movement: " << cscanTotal << endl;

    cout << "\nMost Efficient: ";
    if (fcfs <= sstf && fcfs <= scanTotal && fcfs <= cscanTotal)
        cout << "FCFS";
    else if (sstf <= scanTotal && sstf <= cscanTotal)
        cout << "SSTF";
    else if (scanTotal <= cscanTotal)
        cout << "SCAN";
    else
        cout << "C-SCAN";

    cout << endl;
    return 0;
}
