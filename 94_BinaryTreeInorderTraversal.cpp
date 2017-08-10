/*
 Author:     Kun (Refer to Annie Kim)
 Date:       Apr 22, 2013
 Update:     Aug 18, 2013
 Problem:    Binary Tree Inorder Traversal
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_94
 Notes:
 Given a binary tree, return the inorder traversal of its nodes' values.
 For example:
 Given binary tree {1,#,2,3},
 1
  \
   2
  /
 3
 return [1,3,2].
 Note: Recursive solution is trivial, could you do it iteratively?
 Solution: 1. Iterative way (stack).   Time: O(n), Space: O(n).
           2. Recursive solution.      Time: O(n), Space: O(n).
           3. Threaded tree (Morris).  Time: O(n), Space: O(1).
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 class Solution
{
public:
     vector<int> inorderTraversal(TreeNode *root){
       return inorderTraversal_1(root);
     }
    //beats 11%
     vector<int> inorderTraversal_1(TreeNode *root){
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *p = root;

        while(p||!s.empty())
        {
           while(p)
           {
             s.push(p);    //先尽可能的压入左子树
             p=p->left;
           }
        p = s.top();
        s.pop();
        res.push_back(p->val);
        p = p->right;
      }
      return res;
     }
    //beats 77%
    vector<int> inorderTraversal_2(TreeNode *root){
      vector<int> res;
      inorderTraversalRe(root, res);
      return res;
    }

    void inorderTraversalRe(TreeNode *node, vector<int>& res){
      if(!node) return;
      inorderTraversalRe(node->left, res);
      res.push_back(node->val);
      inorderTraversalRe(node->right, res);
    }


    //beats 77%
    vector<int> inorderTraversal_3(TreeNode *root){
      vector<int> res;
      TreeNode *cur = root;
      while(cur)
      {
        if(cur->left)  //左子树不为空,遍历其左子树
        {
          TreeNode *prev = cur->left;
          while (prev->right&& prev->right!=cur)  //找当前节点的前驱节点(目的是为了能从其左子树返回回当前节点)
             prev = prev->right;

          if (prev->right != cur)       //前驱节点指向当前节点,这样遍历到前驱节点能直接回来.
          {
            prev->right=cur;
            cur=cur->left;
          }
          else  //回到了当前节点(遍历完成当前节点的左子树),恢复前驱节点的右指针为NULL
          {
            res.push_back(cur->val);
            cur= cur->right;
            prev->right=NULL;
          }
        }
        else         //左孩子为空,输出该节点,去找右子树.
        {
          res.push_back(cur->val);
          cur=cur->right;
        }

      }
        return res;
    }

};
