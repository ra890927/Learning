#include <bits/stdc++.h>
using namespace std;

int main(){
    bool check = false;
    string s, res;
    vector<string> vec;
    getline(cin, s);
    stringstream ss;
    ss << s;
    while(ss >> res){
        if(res == "bubble")
            continue;
        else if(res == "tapioka")
            continue;
        else
            vec.push_back(res);
    }

    if(!vec.size())
        cout << "nothing" << endl;
    else{
        for(int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
    }
    return 0;

}
