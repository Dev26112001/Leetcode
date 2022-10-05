class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* value = new TreeNode(val);
            value->left = root;
            return value;
            
        } else{
        return traverse(root,val,depth);
        }
    }
    TreeNode* traverse(TreeNode* root,int val, int depth){
        if(depth-1==1){
            TreeNode* value1 = new TreeNode(val);
            TreeNode* value2 = new TreeNode(val);
            
            TreeNode* left_t = root->left;
            TreeNode* right_t = root->right;
            
            value1->left = left_t;
            value2->right = right_t;
            
            root->left  = value1;
            root->right = value2;
            
            return root;
        }else{
            if(root!=NULL){
            if(root->left!=NULL)
            traverse(root->left,val,depth-1);
            if(root->right!=NULL)
            traverse(root->right,val,depth-1);
            }
            return root;
        }
    }
};