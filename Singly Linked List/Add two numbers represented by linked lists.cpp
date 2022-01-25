#https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#
vector<int> Sum(vector<int> &a,vector<int> &b){
        vector<int> add;
        int carry=0,i=a.size()-1,j=b.size()-1;
        
        while(i>=0 || j>=0){
           int sum=carry;
            if(i>=0){
                sum=sum+a[i];
                i--;
            }
            if(j>=0){
                sum=sum+b[j];
                j--;
            }
            add.push_back(sum%10);
            carry=sum/10;
        }
        
        if(carry)add.push_back(carry);
        
        reverse(add.begin(),add.end());
        return add;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        vector<int> a,b;
        while(first!=NULL){
            a.push_back(first->data);
            first=first->next;
        }
        while(second!=NULL){
            b.push_back(second->data);
            second=second->next;
        }
        
        vector<int> res=Sum(a,b);
        Node *newNode=new Node(res[0]);
        Node *ans=newNode;
        
        for(int i=1;i<res.size();i++){
            
            newNode->next=new Node(res[i]);
            newNode=newNode->next;
        }
        return ans;
    }
