class Solution {
public:
    // static bool cmp(char a,char b){
    //     return mp[a]<mp[b];
    // }
    unordered_map<char,int>mp;
    string customSortString(string o, string s) {
        int i=0;
        for(char x:o){
            mp[x]=i;
            i++;
        }
        sort(s.begin(),s.end(),[this](char a,char b){
            return mp[a]<mp[b];
        });
        return s;
    }
};
