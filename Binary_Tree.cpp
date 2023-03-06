/* ZULEEN KHAN 
codeforces template */
#include<bits/stdc++.h>
 
#define ll long long int
#define next '\n'
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pp push
#define vc vector<ll>
 
 
using namespace std;

struct Node {
  
  int data ; 
  struct Node *left ;
  struct Node *right ; 
  
};
struct Node * create(struct Node *root){
    
    struct Node *p; 
    queue<Node*> q ; 
    int x ; 
    cout << "Enter root" << next ;
    cin >> x ; 
    root = (struct Node *)malloc(sizeof(struct Node)) ; 
    root->data = x ; 
    root->left = nullptr ; 
    root->right = nullptr ;
    q.push(root) ; 
    while(!q.empty()){
        
        p = q.front() ; 
        q.pop() ; 
        
        cout << "Enter the left child" << next ; 
        cin >> x ; 
        if(x!=-1){
            struct Node *t = (struct Node *)malloc(sizeof(struct Node )) ; 
            t->data = x ; 
            t->left = nullptr ; 
            t->right = nullptr ; 
            p->left = t ; 
            q.push(t) ; 
        }
        cout << "Enter the right child" << next ; 
        cin >> x ; 
        if(x!=-1){
            struct Node *t = (struct Node *)malloc(sizeof(struct Node )) ; 
            t->data = x ; 
            t->left = nullptr ; 
            t->right = nullptr ; 
            p->right = t ;
            q.push(t) ; 
        }
    }
    return root ; 
    
} 
void
input (vector < ll > &v, int n)
{
  int i;
 
  for (i = 0; i < n; ++i)
    cin >> v[i];
 
}
 
bool
ispalin (string z)
{
  int i, j;
  string temp = z;
 
  for (i = 0, j = z.size () - 1; i < j; ++i, --j)
    swap (z[i], z[j]);
 
  return (temp == z ? 1 : 0);
}
void level_order(struct Node *root){
    queue<Node *> q ; 
    q.push(root) ; 
    while(!q.empty()){
        int sz = q.size() ; 
        for(int i = 0 ;i < sz ;++i){
             struct Node *p = q.front() ; 
             q.pop() ; 
             cout << p->data <<" " ; 
             if(p->left!=nullptr){
                 q.push(p->left) ; 
                  
             }
             if(p->right!=nullptr){
                 q.push(p->right) ; 
                  
             }
            
        }
        
        
    }
    
}
signed
main ()
{

     struct Node *root = NULL ; 
     root = create(root) ; 
     level_order(root) ; 
    
    return 0;
}
