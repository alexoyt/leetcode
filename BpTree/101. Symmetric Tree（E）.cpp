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
  * һ��ʼ����������нڵ��ֵ��һ��Vector<int>�У����ж��Ƿ�Ϊmirror�������뷢�������ǲ��Եģ��п�������������������ֵ��ȡ�
  * ����ֻ��ֱ�Ӹ���TreeNode�Ľڵ����жϡ������������Ҫ�õ�bp����������ͬʱΪ��ȷ���Ƚϵ���ͬһ��εĽڵ㣬
  * ҪΪÿ���ڵ�ά��һ���������depth�����й���������list,һ������bp��������һ������ά����ȣ�
  * ÿ������һ�㣬���̼��˲��Ƿ�����mirror�����������������false�����������ֱ�������ꡣ
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
