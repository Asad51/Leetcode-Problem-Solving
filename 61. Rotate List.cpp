/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct DoublyListNode
{
    ListNode *node;
    DoublyListNode *prev, *next;
    DoublyListNode(ListNode *n) : node(n), prev(NULL), next(NULL) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;
        ListNode *tmp = head, *last;
        DoublyListNode *front = NULL, *rear = NULL;
        int j = 0;
        while (tmp)
        {
            DoublyListNode *newNode = new DoublyListNode(tmp);
            if (!front || !rear)
            {
                front = rear = newNode;
                front->next = front->prev = rear;
                rear->prev = rear->next = front;
            }
            else
            {
                rear->prev = front->next = newNode;
                newNode->next = rear;
                newNode->prev = front;
                front = newNode;
            }

            last = tmp;
            tmp = tmp->next;
            j++;
        }
        last->next = head;

        int i = 0;
        ListNode *ret;
        k = k % j;
        while (i < k)
        {
            front = front->prev;
            i++;
        }
        printf("%d\n", front->node->val);
        ListNode *retValue = front->node->next;
        front->node->next = NULL;

        return retValue;
    }
};
