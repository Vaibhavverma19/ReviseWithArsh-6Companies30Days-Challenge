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
    int count=0;
    vector<int> solve(TreeNode* node,int distance)
    {
        if(node->left== NULL && node->right==NULL)
        {
            return {1}; //means 1 leafnode found. at distance 1 from parent node
        }
         vector<int> left_leaf_nodes,right_leaf_nodes; // to track the leafnodes along with their distance
        //go to left and find all the leaf nodes in that part along with their distances
        if(node->left)
        {
           left_leaf_nodes=solve(node->left,distance);
        }
        if(node->right)
        {
            right_leaf_nodes=solve(node->right,distance);
        }

        //now we have all the leaf nodes of both left subparts and right subparts 
        //and their distances too
        //so we will check each leaf node of left part with each leaf node of right part
        for(int i=0;i<left_leaf_nodes.size();++i)
        {
            for(int j=0;j<right_leaf_nodes.size();++j)
            {
                if(left_leaf_nodes[i] + right_leaf_nodes[j] <= distance)
                {
                    count++;
                }
            }
        }

        //now we have to pass the distance values to the higher parent along with increase in distance by 1.
        //and check if it is less than distance or not because otherwise it will be a waste node for us
        vector<int> all;
        for(int i=0;i<left_leaf_nodes.size();++i)
        {
            if(left_leaf_nodes[i] + 1< distance) all.push_back(left_leaf_nodes[i]+1);
        }
        for(int i=0;i<right_leaf_nodes.size();++i)
        {
            if(right_leaf_nodes[i] + 1< distance) all.push_back(right_leaf_nodes[i]+1);
        }

        return all;

    }
    int countPairs(TreeNode* root, int distance) {
        solve(root,distance);
        return count;
    }
};