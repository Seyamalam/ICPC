#include <bits/stdc++.h>

using namespace std;



// Function to calculate f(k) as defined in the problem

int64_t calculate_f(const vector<int>& seq, int k) {

    int64_t product = 1;

    int64_t sum = 0;

    

    // Calculate product and sum for first k elements

    for (int i = 0; i < k; i++) {

        product *= seq[i];

        sum += seq[i];

    }

    

    return (product & sum); // Bitwise AND of product and sum

}



// Function to check if sequence is good

bool is_good_sequence(const vector<int>& seq) {

    int n = seq.size();

    

    // Check all pairs i,j where i < j

    for (int i = 1; i <= n; i++) {

        for (int j = i + 1; j <= n; j++) {

            if (calculate_f(seq, i) == calculate_f(seq, j)) {

                return false;

            }

        }

    }

    return true;

}



// Function to generate a valid sequence

vector<int> generate_sequence(int n) {

    vector<int> seq;

    // Start with small numbers to minimize difference

    int curr = 2;

    

    // Generate sequence of length n with numbers from 2 to 3n

    while (seq.size() < n) {

        seq.push_back(curr);

        curr++;

        if (curr > 3 * n) break;

    }

    

    // Verify the sequence meets all conditions

    assert(seq.size() == n);

    assert(is_good_sequence(seq));

    

    // Verify max-min <= 10

    int max_val = *max_element(seq.begin(), seq.end());

    int min_val = *min_element(seq.begin(), seq.end());

    assert(max_val - min_val <= 10);

    

    return seq;

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    

    int t;

    cin >> t;

    

    while (t--) {

        int n;

        cin >> n;

        

        vector<int> result = generate_sequence(n);

        

        // Print the sequence

        for (int i = 0; i < n; i++) {

            cout << result[i];

            if (i < n-1) cout << " ";

        }

        cout << "\n";

    }

    

    return 0;

}


