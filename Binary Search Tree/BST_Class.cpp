#include<iostream>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
      T data;
      BinaryTreeNode<T> *left;
      BinaryTreeNode<T> *right;
      BinaryTreeNode(T data){
          this->data=data;
          left=NULL;
          right=NULL;
      }
};

class BST{
  BinaryTreeNode<int> *root;
  public:
     BST(){
         root=NULL;
     }
     ~BST(){
         delete root;
     }
  private:
     bool search(BinaryTreeNode<int> *r,int data){
         if(r==NULL){
             return false;
         }
         if(r->data==data){
             return true;
         }
         else if(r->data<data){
             return search(r->left,data);
         }
         else if(r->data>data){
             return search(r->right,data);
         }
     }
  public:
     bool search(int data){
         return search(root,data);
     }
  private:
      BinaryTreeNode<int> *insert(BinaryTreeNode<int> *r,int data){
          if(root==NULL){
              BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
              return newNode;
          }
          if(data<=r->data){
              r->left=insert(r->left,data);
          }
          else if(data>r->data){
              r->right=insert(r->right,data);
          }
          return r;
      }
    public:
       void insert(int data){
           root=insert(r,data);
       }
    private:
    BinaryTreeNode<int> *remove(int data, BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->data > data)
        {
            node->left = remove(data, node->left);
            return node;
        }
        else if (node->data < data)
        {
            node->right = remove(data, node->right);
            return node;
        }
        else
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = nullptr;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = nullptr;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != nullptr)
                {
                    minNode = minNode->left;
                }
                int minData = minNode->data;
                node->data = minData;
                node->right = remove(minData, node->right);
                return node;
            }
        }
    }

public:
    void remove(int data)
    {
        root = remove(data, root);
    }
};

