# GFG Notes

# Q - Longest Prefix Suffix<br/>
https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1<br/>
Ref: https://www.youtube.com/watch?v=lhhqbGH7Pao<br/>

Algo - KMP

Prefix Function<br/> 
prefix[i] is the length of the longest proper prefix of the substring s[0...i] which is also a suffix of this subtring.
By definition, prefix[0] = 0.

prefix[i] = maximum k such that 
s[0...k-1] = s[i-(k-1)...i]

# Q - Smallest window in a string containing all the characters of another string<br/>
https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1#<br/>

Algo - Sliding Window

Instead of using unordered_map we can use array if the range of key is finite like in this case range of key is [0,255]

# Q - Count Customers Who Did Not Get A Computer<br/>
https://www.codingninjas.com/codestudio/problems/count-customers-who-did-not-get-a-computer_1115775?leftPanelTab=0<br/>

Instead of using unordered_map we can use array if the range of key is finite like in this case range of key is [1,n]

# Q - Reverse a linked list using Recursion<br/>
https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1#<br/>
Ref: https://www.youtube.com/watch?v=KYH83T4q6Vs

# Quick Sort
![alt text](https://github.com/anirudhkgupta222/GFG/blob/main/Screenshot%202021-09-27%20202523.jpg?raw=true)
