#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
struct trie {
    char data;
    bool isend;
    unordered_map<char, trie*> children;
    trie(char data){
        this->data=data;
    }
};
int main(){
    trie* t=new trie(' ');
    string s;
    cin>>s;
    trie* temp=t;
    for(int i=0;i<s.size();i++){
       if(temp->children.find(s[i])==temp->children.end()){
            trie* n=new trie(s[i]);
            temp->children[n->data]=n;
            temp=n;
       }else{
        temp=temp->children[s[i]];
       }
    }
    temp->isend=true;
    cout<<"Enter the string to search"<<endl;
    cin>>s;
    temp=t;
    for(int i=0;i<s.size();i++){
        if(temp->children.find(s[i])==temp->children.end()){
            cout<<"Not found"<<endl;
            return 0;
        }else{
            temp=temp->children[s[i]];
        }
    }
}
