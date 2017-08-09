class Solution {
public:
vector<vector<int> > levelOrder(TreeNode *root){
        vector<vector<int> > res;
        if(root == NULL) return res;

        queue<TreeNode*> q; //queue use pointer
        q.push(root);
        while (!q.empty())
        {
                vector<int> oneLevel;
                //@param: size for maker this level size
                int size = q.size();
                for(int i = 0; i<size; ++i) {
                        TreeNode *node = q.front();
                        //pop this level node
                        q.pop();
                        //push node val into this level
                        oneLevel.push_back(node->val);
                        //search next level nodes and push into queue
                        if(node->left) q.push(node->left);
                        if(node->right) q.push(node->right);
                }
                res.push_back(oneLevel);
        }
        return res;
}

};
