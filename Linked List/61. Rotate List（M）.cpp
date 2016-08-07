/**
 * ����һ���ҳ�����������ĳ���n�����������k�����������ҵ�n-k���������������ҳ�����ڵ��λ�ã�֮��
 * 1����¼�´�ʱͷ���Ľڵ�q
 * 2����������һ���ڵ�Ϊͷ��head
 * 3��ͬʱ�˽ڵ�ָ��null
 * ���������ƶ������ҵ������Ľ�β�ڵ�ʱ����˽ڵ�ָ��ԭ����ͷ���ڵ�q���ɡ�
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
