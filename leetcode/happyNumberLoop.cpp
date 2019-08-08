// 202 Happy Number
typedef long long ll;

class Solution {
    
public:
    bool isHappy(int n) {
        unordered_set<long long> s;
        int a = n;
        ll r = 0;
        while (r != 1) {
            r = 0;
            while(a > 0) {
                r += (a %10) * (a % 10);
                a = a /10;
            }
            if (s.find(r) != s.end())
                return false;
            s.insert(r);
            a = r;
        
        }
        return true;
    }
};

// 141 Linked List Cycle ( Loop )

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
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        ListNode* slow = head->next;
        if (slow == NULL) {
            return false;
        }
        ListNode *fast = slow->next;
        if (fast == NULL)
            return false;
        while ( slow->val != fast->val ) {
            slow = slow->next;
            fast = fast->next; 
            if (fast == NULL || fast->next == NULL)
                return false;
            fast = fast->next;
        }
        return true;
    }
};

