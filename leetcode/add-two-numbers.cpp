#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *ans = new ListNode();
  int carry = 0;
  while (l1 != nullptr && l2 != nullptr) {
    int a = l1 == nullptr ? 0 : l1->val;
    int b = l2 == nullptr ? 0 : l2->val;
    int sum = a + b;
    carry = sum > 10 ? 1 : 0;
    l1 = l1->next;
    l2 = l2->next;
  }

  cout << ans->val << "\n";
  return nullptr;
}