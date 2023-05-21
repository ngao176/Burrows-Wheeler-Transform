#include <string>
#include <algorithm> 
#include "BWT.h"
using namespace std;

/**
 * Implement bwt() correctly
 */
string bwt(const string & s) {
    /* YOUR CODE HERE */
    const int n = s.size();
    const int MaxRot = n;
    string rot[MaxRot];
    string x;

    for (int i = 0; i < n; i++) {
        rot[i] = s.substr(i, n-i) + s.substr(0, i);
    }

    for (int i = 1; i < n; i++) {
        string tmp = rot[i];
        int j = i - 1;
        while (j >= 0 && rot[j] > tmp) {
            rot[j+1] = rot[j];
            j--;
        }
        rot[j+1] = tmp;
    }

    for (int i = 0; i < n; i++) {
        x += rot[i][n-1];
    }

    return x;
}
