/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /**
  * 一开始打算读出所有节点的值到一个Vector<int>中，再判断是否为mirror，再想想发现这样是不对的，有可能左子树与左子树的值相等。
  * 所以只能直接根据TreeNode的节点来判断。这里很明显是要用到bp来遍历树，同时为了确定比较的是同一层次的节点，
  * 要为每个节点维护一个它的深度depth，所有构建了两个list,一个用于bp遍历树，一个用于维护深度，
  * 每遍历完一层，立刻检查此层是否满足mirror的条件，不满足输出false，否则继续，直到遍历完。
  */
  
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        bool res=true;
        list<TreeNode*> array;
        list<int> depth;
        array.push_front(root);
        depth.push_front(1);
        int lastdepth=1;
        while(array.size()!=0)
        {
            TreeNode* temp=array.back();
            int deep=depth.back();
            
            if(lastdepth!=deep)
            {
                res=checkTreeNode(array);
                if(res==false)
                    break;
                lastdepth=deep;
            }
            
            array.pop_back();
            depth.pop_back();
            if(temp!=NULL)
            {
                array.push_front(temp->left);
                array.push_front(temp->right);
                depth.push_front(deep+1);
                depth.push_front(deep+1);
            }

        }
        return res;
        
    }
    
    bool checkTreeNode(list<TreeNode*> array)
    {
        int n=array.size(),count=1;
        list<TreeNode*>::iterator i=array.begin(),j=array.end();
        j--;
        for(;count<=n/2;i++,j--,count++)
        {
            if((*i==NULL&&*j!=NULL)||(*j==NULL&&*i!=NULL))
                return false;
            if(*i==NULL&&*j==NULL)
                continue;
            if((*i)->val==(*j)->val)
                continue;
            else
                return false;
            
        }
        return true;
    }
};
