// wromng answer...
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
class Solution {
public:
    int maxi=INT_MIN;
    pair<int,int> height(TreeNode* root,int target)
    {
        bool istarget=false;

        if(root==NULL)
        {
            return {0,0};
        }

        auto leftheight= height(root->left,target);

        auto rightheight=height(root->right,target);

        int currheight=1 + max(leftheight.first,rightheight.first);
        maxi=max(maxi, leftheight.first + rightheight.first);
        if(root->val==target)
        {  //cout<<"y "<<root->val<<", "<<currheight-1;
            return {currheight,currheight-1};
        }
        else{
            return {currheight,leftheight.second?leftheight.second:rightheight.second};
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        pair<int,int> leftans=height(root->left,start);
        pair<int,int> rightans=height(root->right,start);
        if(root->val==start) return max(leftans.first,rightans.first); 
        int total_dist=max(maxi,leftans.first + rightans.first);
        int infected_height=leftans.second?leftans.second:rightans.second;
       
        return max(total_dist - infected_height, infected_height);
    }
};