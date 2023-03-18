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

vector<vector<string>> printTree(struct Node* root) {
        int k = 0 ; 
        queue<Node *> q ;
        q.push(root) ;
    // height of the tree is k 
        while(!q.empty()){
        int sz = q.size() ; 
        for(int i = 0 ;i < sz ;++i){
            struct Node *p = q.front() ; 
            q.pop() ; 
            if(p->left!=nullptr) q.push(p->left) ;
            if(p->right!=nullptr) q.push(p->right) ;
           }
          ++k ; 
        }
       k-=1;
    // inititalising the vector of string    
     vector<vector<string>> ans ;
     int width = pow(2,k+1) - 1 ;  
     for(int i = 0 ;i < k+1 ;++i){
         vector<string > v ; 
       for(int j = 0 ;j < width ; ++j )
         v.emplace_back(" ") ; 
        
        ans.emplace_back(v) ; 
     }
     queue<pair<Node* , pair<int,int> > >  qr ; 
     qr.push(make_pair(root , make_pair(0 , (width-1)/2)) ) ;
      ans[0][(width-1)/2] = to_string(root->data) ;

     while(!qr.empty()){
        int sz = qr.size() ; 
        for(int i = 0 ;i < sz ;++i){
            struct Node *p = qr.front().first ;
             int a = (qr.front().second).first ;
             int b = (qr.front().second).second ; 
             qr.pop() ; 
            if(p->left!=nullptr) {
            qr.push(make_pair(p->left , make_pair(a+1 , b-pow(2,k-a-1) )) ) ;
            ans[a+1][b-pow(2,k-a-1)]  = to_string(p->left->data); }
            if(p->right!=nullptr) {
              qr.push(make_pair(p->right , make_pair(a+1 , b+pow(2,k-a-1) )) ) ;  
               ans[a+1][b+pow(2,k-a-1)]  = to_string(p->right->data);
                }
           }
    
    }
       
     return ans ; 
}


signed
main ()
{

     struct Node *root = NULL ; 
     root = create(root) ; 
     vector<vector<string> > ans ; 
     ans = printTree(root) ; 
     // Visualizing the structure of a Tree. 
     for(int i = 0 ;i < ans.size() ; ++i){
         
        for(int j = 0 ; j < ans[i].size() ;++j) cout << ans[i][j]  ; 
        
        cout << next ; 
     }
    return 0;
}
