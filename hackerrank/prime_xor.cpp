#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> getPrimes()
{
    int a[10000] = {0}
    for(int i=2;i<8192;i++){
        for(int j=2; i*j <= 8192; j++){
            a[i*j] = 1;
        }
    }
    vector<int> primes;
    for(int i=2;i<8192;i++)
        if(a[i] == 0)
            primes.push_back(i);
    return primes;
}

// Complete the primeXor function below.
int primeXor(vector<int> a) {
    vector<int> primes = getPrimes();
    int freq[1001] = {0};
    int n = a.size();
    for(int i=0;i<n;i++)
        freq[a[i]-3500]++;
    
    int dp[a.size()][8192];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = dp[i-1][j]+ (dp[i-1][j^a[i-1]])
        }
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        int result = primeXor(a);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
