#include <bits/stdc++.h>
#include "makeLL.cpp"
using namespace std;

/* Definition for singly linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/

ListNode *mergeKSortedLists(vector<ListNode *> lists)
{
    priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;

    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i])
            pq.push({lists[i]->val, lists[i]});
    }

    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;

    while (!pq.empty())
    {
        auto it = pq.top().second;
        pq.pop();
        if (it->next)
            pq.push({it->next->val, it->next});

        temp->next = it;
        temp = temp->next;
    }
    return dummy->next;
}

void print(ListNode *head)
{
    ListNode *curr = head;
    while (curr->next != NULL)
    {
        cout << curr->val << "->";
        curr = curr->next;
    }
    cout << curr->val << "->NULL" << endl;
}

int main()
{
    /* creating first linked List */
    ListNode *l1 = new ListNode(1);
    ListNode *tmp1 = l1;
    tmp1->next = new ListNode(4);
    tmp1 = tmp1->next;
    tmp1->next = new ListNode(5);
    tmp1 = tmp1->next;
    tmp1->next = NULL;

    /* creating second linked list */
    ListNode *l2 = new ListNode(1);
    ListNode *tmp2 = l2;
    tmp2->next = new ListNode(3);
    tmp2 = tmp2->next;
    tmp2->next = new ListNode(4);
    tmp2 = tmp2->next;
    tmp2->next = NULL;

    /* creating third linked list */
    ListNode *l3 = new ListNode(2);
    ListNode *tmp3 = l3;
    tmp3->next = new ListNode(6);
    tmp3 = tmp3->next;
    tmp3->next = NULL;

    ListNode *result = mergeKSortedLists({l1, l2, l3});
    print(result);
}