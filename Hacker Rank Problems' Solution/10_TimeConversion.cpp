//Time Conversion
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    if(s.at(8)=='P')
    {
        string ss = s.substr(0,2);
        
        if(!ss.compare("12"));
        else 
       { 
            int n = stoi(ss);
            n+=12;
            ss = to_string(n);
            s.replace(0,2,ss);
        }            
        s.erase(8,2);

    }
    else
    {   string ss = s.substr(0,2);
        if(!ss.compare("12"))
        {   s.replace(0,2,"00");
        }
        s.erase(8,2);
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
