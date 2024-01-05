/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class temp
    {
        public:
        int mini;
        int maxi;
        int sum;
        bool isBST;
        temp()
        {}
        temp(int a,int b,int c,bool d)
        {
            mini=a;
            maxi=b;
            sum=c;
            isBST=d;
        }
    };
class Solution {
public:
    
    temp solve(TreeNode* &root,int &ans)
    {
        if(root==NULL)
        {temp t1(INT_MAX,INT_MIN,0,true);
          return t1;}
        
        temp leftans=solve(root->left,ans);
        temp rightans=solve(root->right,ans);
        
        temp curr;
        curr.mini=min(root->val,leftans.mini); 
        curr.maxi=max(root->val,rightans.maxi);
        
        if(leftans.isBST && rightans.isBST && (root->val>leftans.maxi && root->val<rightans.mini))
        {
            curr.isBST=true;
        }
        else{
            curr.isBST=false;
        }
        if(curr.isBST==true)
        {
            curr.sum=leftans.sum+rightans.sum+root->val;
        }else{
            curr.sum=max(leftans.sum,rightans.sum);
        }
        ans=max(ans,curr.sum);
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        temp t;
        int ans=0;
        t=solve(root,ans);
        return ans;
    }
};