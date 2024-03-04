//Happy Ladybugs
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'happyLadybugs' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING b as parameter.
 */

string happyLadybugs(string b) {
    string state = "YES";
        bool tmp = true;
        int tab[27] = {};
        for(int i=0,j=0 ; i<b.length() ; i++, j+=2){
            if(tmp && j<b.length()-1 && b[j]!=b[j+1] && b[j]!=b[j-1]) tmp = false;
            if(b[i]=='_') tab[26]++;
            else tab[b[i]-'A']++;
        }
        for(int i=0 ; i<26 ; i++){
            if(tab[i]==1){
                state = "NO";
                break;
            }
        }
        if(!tmp && tab[26]==0) state = "NO";
        return state;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

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
