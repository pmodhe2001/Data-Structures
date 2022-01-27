/*
Normal Trie Implementation
1. Insert Word
2. Search Word
3. Remove Word
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
        Trie(){
            root=new TrieNode('\0');
        }
        
        void insertWord(TrieNode *root,string word){
            // Base case
            if(word.size()==0){
                root->isTerminal=true;
                return;
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
            insertWord(child,word.substr(1));
            
        }
        
        void insertWord(string word){
            insertWord(root,word);
        }
        
        bool searchWord(TrieNode *root,string word){
            if(word.size()==0){
                if(root->isTerminal==true){
                    return true;
                }
                else{
                    return false;
                }
            }
            
            int index=word[0]-'a';
            
            if(root->children[index]==NULL){
                return false;
            }
            else{
                return searchWord(root->children[index],word.substr(1));
            }
        }
        bool searchWord(string word){
            return searchWord(root,word);
        }
       
        void removeWord(TrieNode *root,string word){
            // Base case
            if(word.size()==0){
                root->isTerminal=false;
                return;
            }
            // Small calculation
            TrieNode *child;
            int index=word[0]-'a';
            
            if(root->children[index]==NULL){
                return;
            }
            else{
                child=root->children[index];
            }
            
            removeWord(child,word.substr(1));
            
            // Remove Useless Nodes
            
            if(child->isTerminal==false){
                for(int i=0;i<26;i++){
                    if(child->children[i]!=NULL){
                        return;
                    }
                }
                delete child;
                root->children[index]=NULL;
            }
        } 
        
        void removeWord(string word){
            removeWord(root,word);
        }
};
int main(){
    int choice;
    cin >> choice;
    Trie t;

    while (choice==1 or choice==2 or choice==3) {
            string word;
            if(choice==1){ // insert
                cin >> word;
                t.insertWord(word);
            } 
            else if(choice==2){ // search
                cin >> word;
                if(t.searchWord(word)==true){
                    cout<<"True"<<endl;
                }
                else{
                    cout<<"False"<<endl;
                }
            }
            else if(choice==3){
                cin>>word;
                t.removeWord(word);
            }
        
        cin >> choice;
    }

    return 0;
}


