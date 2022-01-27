#include <bits/stdc++.h>
using namespace std;

class TrieNode{
  public:
     char data;
     TrieNode **children;
     bool isTerminal;
     TrieNode(char data){
         this->data=data;
         children=new TrieNode*[26];  // Size according to all characters are small-case
         for(int i=0;i<26;i++){  // at 0th index we'll store a , at 1st index we'll store b and so on....
             children[i]=NULL;
         }
         isTerminal=false;
     }
};

class Trie{
    TrieNode *root;
    public:
        int count;
        Trie(){
            this->count=0;
            root=new TrieNode('\0');
        }
        
        bool insertWord(TrieNode *root,string word){
            // Base case
            if(word.size()==0){
                if(root->isTerminal==false){
                    root->isTerminal=true;
                    return true;
                }
                else{
                    return true;
                }
            }
            
            // Small calculation
            int index=word[0]-'a';
            TrieNode *child;
            
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            else{
                child=new TrieNode(word[0]);
                root->children[index]=child;
            }
            
            // Recursive Call
            return insertWord(child,word.substr(1));
            
        }
        
        void insertWord(string word){
            if(insertWord(root,word)==true){
                this->count++;
            }
            
        }
        
        bool searchWord(TrieNode *root,string word){
            if(word.size()==0){
                    return true;
            }
            
            int index=word[0]-'a';
            TrieNode *child;
            if(root->children[index]==NULL){
                return false;
            }
            else{
                child=root->children[index];
            }
            return searchWord(root->children[index],word.substr(1));
        }
        bool searchWord(string word){
            return searchWord(root,word);
        }
       
        bool patternSearch(vector<string> v,string pattern){
            for(int i=0;i<v.size();i++){
                string combo=v[i];
                for(int j=0;j<combo.length();j++){
                    insertWord(combo.substr(j));
                }
            }
            return searchWord(pattern);
        }
};
int main(){
    Trie t;
    cout<<"Enter number of total words in a vector : ";
    int n;
    cin>>n;
    
    vector<string> v;
    
    for(int i=0;i<n;i++){
        string word;
        cout<<"Enter "<<i+1<<" word "<<"of"<<" your vector."<<endl;
        cin>>word;
        v.push_back(word);
    }
    
    cout<<"Enter Pattern to check : ";
    string pattern;
    cin>>pattern;
    
    if(t.patternSearch(v,pattern)==true){
        cout<<"Yes!"<<endl;
    }
    else{
        cout<<"No!"<<endl;
    }
    

    return 0;
}


