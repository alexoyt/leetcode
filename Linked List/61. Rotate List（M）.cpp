/**
 * 遍历一次找出该线性链表的长度n，从右数起第k个数即从左到右第n-k个数，在链表中找出这个节点的位置，之后
 * 1、记录下此时头部的节点q
 * 2、令它的下一个节点为头部head
 * 3、同时此节点指向null
 * 接着向右移动，当找到本来的结尾节点时，令此节点指向原来的头部节点q即可。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        if(head==NULL||k==0)
            return head;
        ListNode* p=head;
        ListNode* q=NULL;
        while(p!=NULL)
        {
            p=p->next;
            n++;
        }
        if(n==1)
            return head;
        p=head;
        k=k%n;
        for(int i=1;i<n;i++)
        {
            
            if(i==n-k)
            {
                ListNode* temp=p->next;
                p->next=NULL;
                q=head;
                head=p=temp;
            }
            else
                p=p->next;
        }
        p->next=q;
        return head;
    }
};
