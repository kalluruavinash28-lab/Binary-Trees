/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
          vector<int> ans;
          if(!root){
              return ans;
          }
       queue<pair<int,Node*> >q;
       map<int,int> m;
     
       q.push(make_pair(0,root));
     
       while(!q.empty()){
          pair<int,Node*> p=q.front();
           m[p.first]=p.second->data;
           q.pop();
            int hd = p.first;
           if(p.second->left!=NULL){
               q.push(make_pair(hd-1,p.second->left));
           }
           
           if(p.second->right!=NULL){
               q.push(make_pair(hd+1,p.second->right));
           }
         }
         
       for (auto &n : m) {
        ans.push_back(n.second);
}

        return ans;
    }
};
