#include <iostream>
#include <vector>
using namespace std;

vector<int> reconstructPermutation(string s) {
    int n = s.length();
    vector<int> perm(n + 1);
    int low = 0, high = n;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I')
            perm[i] = low++;
        else
            perm[i] = high--;
    }
    
    perm[n] = low;
    return perm;
}

int main() {
    string s;
    cout << "Enter the string s: ";
    cin >> s;
    
    vector<int> permutation = reconstructPermutation(s);
    
    cout << "Reconstructed permutation: ";
    for (int i = 0; i < permutation.size(); i++) {
        cout << permutation[i] << " ";
    }
    
    return 0;
}
