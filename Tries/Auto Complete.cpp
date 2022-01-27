/*
Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
*/

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
        
        // Finding Node
        TrieNode *SearchNode(TrieNode *root,string word){
            if(word.size()==0){
                return root;
            }
            
            int index=word[0]-'a';
            
            if(root->children[index]!=NULL){
                return SearchNode(root->children[index],word.substr(1));
            }
            return root;
        }
        
        TrieNode *SearchNode(string word){
            return SearchNode(root,word);
        }
        
        // If isTerminal is true then print the word
        void print(TrieNode *root,string word){
            if(root==NULL){
                return; 
            }
            if(root->isTerminal==true){
                cout<<word<<endl;
            }
            for(int i=0;i<26;i++){
                if(root->children[i]!=NULL){
                    print(root->children[i],word+root->children[i]->data);
                }
            }
            
        }
        
        
       
        void autoComplete(vector<string> words,string incompleteWord){
            for(int i=0;i<words.size();i++){
                insertWord(words[i]);
            }
            TrieNode *tempRoot=SearchNode(incompleteWord); // Search the nodes with incompleteWord
            print(tempRoot,incompleteWord); // Now print all the possible words with incompleteWord as prefix
            
        }
};

int main(){
    Trie t;
    int n;
    cin>>n;
    
    vector<string> v;
    
    for(int i=0;i<n;i++){
        string word;
        cin>>word;
        v.push_back(word);
    }
    
    string incompleteWord;
    cin>>incompleteWord;
    
    t.autoComplete(v,incompleteWord);
    return 0;
}

