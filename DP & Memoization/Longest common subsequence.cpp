/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string.h>
using namespace std;
 
  // LCS RECURSION
int lcsRec(char *s1,char *s2){
    if(s1[0]=='\0' or s2[0]=='\0'){
        return 0;
    }
    
    if(s1[0]==s2[0]){
        return 1+lcsRec(s1+1,s2+1);
    }
    else{
        int opt1=lcsRec(s1,s2+1);
        int opt2=lcsRec(s1+1,s2);
        return max(opt1,opt2);
    }
}
  // LCS MEMOIZATION
int lcsMemoHelper(char *s1,char *s2,int m,int n,char **dp){
     if(m==0 or n==0){
         return 0;
     }
     
     if(dp[m][n]>-1){
         return dp[m][n];
     }
     int ans;
     if(s1[0]==s2[0]){
         ans = 1+lcsMemoHelper(s1+1,s2+1,m-1,n-1,dp);
     }
     else{
         int opt1 = lcsMemoHelper(s1,s2+1,m-1,n-1,dp);
         int opt2 = lcsMemoHelper(s1+1,s2,m-1,n-1,dp);
         int ans=max(opt1,opt2);
     }
     
     dp[m][n] = ans;
     return ans;
}
int lcsMemo(char *s1,char *s2){
    int m=strlen(s1);
    int n=strlen(s2);
    
    char **dp=new char *[m+1];
    for(int i=0;i<=m;i++){
        dp[i]=new char[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    
    int ans = lcsMemoHelper(s1,s2,m,n,dp);
    
    for(int i=0;i<n;i++){
        delete[] dp[i];
    }
    delete [] dp;
    return ans;
}

int main()
{
     char a[100];
     char b[100];
     cin>>a;
     cin>>b;
     
     cout<<lcsRec(a,b)<<endl;
     cout<<lcsMemo(a,b)<<endl;
}
