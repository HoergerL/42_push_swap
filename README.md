# 42_push_swap

Push_swap is about programming a <b>sorting algorithm</b>, with 2 stacks, stack a and stack b. At the beginning of your sorting algorithm all of the elements are  placed on stack a.
You can only use the following operations;
1. sa - swap a: swap the first 2 elements of stack a
2. sb - swap b: swap the first 2 elements of stack b
3. ss - swap a and swap b at the same time
4. ra - rotate a: rotate stack a so that first element becomes the last one
5. rb - rotate b: rotate stack b so that first element becomes the last one
6. rr - rotate a and rotate b at the same time
7. rra - reverse rotate a: rotate stack a so that the last element becomes the first one
8. rrb - reverse rotate b: rotate stack a so that the last element becomes the first one
9. rrr - reverse roate a and reverse rotate b at the same time
10. pb - push element from a to the top of stack b
11. pa - push element from b to the top of stack a

### approach:
1. Find the longest increasing subsequence in stack a and push all the elements, which aren't part of that to stack b.
2. calculate for every element on stack b the number of needed operations to push it on the right place at stack a.
3. push the element with the lowest number of operation back and repeat until all elements are back on stack a.
4. rotate the stack until the lowest element is on top of stack a.

### goal: 
For 100 points the algorithm needs to take:
1. less than 5500 for 500 numbers
2. less than 700 for 100 numbers

The mean of the algorithm takes
1. 5024 operations for a stack of size 500
2. 535 operations for a stack of size 100

