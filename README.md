206. Reverse Linked List

有3个指针
dummy: 记录最开始的头,初始化dummy->next = head,返回头为dummy->next
head: 记录最初的头,并一步一步向后移
temp: 每次循环更新为head->next

可以缩小为2个指针

也可以用recursive解决

https://leetcode.com/problems/reverse-linked-list/discuss/