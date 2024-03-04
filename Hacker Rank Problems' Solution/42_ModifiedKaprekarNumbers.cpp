//Modified Kaprekar Numbers
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

void kaprekarNumbers(int p, int q) {
    int x, x1, x2;
    string s, s1, s2;
    int count=0;
    for(int i = p; i <= q; i++) {
        long long square = static_cast<long long>(i) * i; 
        s = to_string(square);
        s1 = s.substr(0, s.size() / 2);
        s2 = s.substr(s.size() / 2);
        x1 = (s1.empty()) ? 0 : stoi(s1); 
        x2 = stoi(s2);
        if (x1 + x2 == i ) 
        {
            cout << i << " ";
            count++;
        }
    }
    if(count==0)
        cout<<"INVALID RANGE";
}



int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
