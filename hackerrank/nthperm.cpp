/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int> factorid(unsigned long long n, int len,unsigned long long factorials[], int padding){
    
    //long long factroid = 0;
    vector<int> out;
    for(int i=1;i<=padding;i++)
        out.push_back(0);
    for(int i=len-1;i>0;i--){
           unsigned long long q = n/factorials[i];
           //cout<<q<<endl;
           n = n%factorials[i];
           //out.push_back('0'+ q);
           out.push_back(q);
    }
    out.push_back(0);
    return out;
}

char getCh(string s, vector<int>& visited, int id){
        for(int i=0,j=0;i<visited.size();i++){
            if (!visited[i]){
                if(j==id){
                    visited[i] = true;
                    return s[i];
                }
                j++;
            }
        }
}

string Nperm(string s, long long n,unsigned long long factorials[]){
            
    int len = (s.length()<=20)?s.length(): 20;
    //len -= 1;
    int padding = s.length() - len;
    vector<int> factroidIds = factorid(n ,len, factorials, padding);
    
    vector<int> visited(s.length(), 0);
    string outStr = "";
    for(int i=0;i<s.length();i++)
        outStr.push_back(getCh(s,visited, factroidIds[i]));
    return outStr;
        
        
}
 

string findEncryptedString(string s1,string s2, unsigned long long n)
{
    string permString = "";
    size_t id;
    
    unsigned long long factorials[21];
    factorials[0] = factorials[1] = 1;
    for(int i=2;i<21;i++){
        factorials[i] = i*factorials[i-1];
    //cout<<factorials[i]<<" "<<i<<endl;
    }
    
    for(int i=0;i<26;i++){
        if(s2.find('a'+i) == std::string::npos)
            permString.push_back('a'+i);
    }
    permString = Nperm(permString,n,factorials);
    cout<<permString<<endl<<s1<<endl<<s2<<endl;
    string retStr = "";
    int j=0;
    for(int i=0;i<26;i++){
        id = s1.find('a'+i);
        if (id != std::string::npos)
            retStr.push_back(s2[id]);
        else
            retStr.push_back(permString[j++]);
    }
    return retStr;
}


int main()
{
    
    cout<<findEncryptedString("bcd", "xyz", 3)<<endl;
    return 0;
}
