# GFG Notes

Q - Longest Prefix Suffix<br/>
https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1<br/>

Algo - KMP

Prefix Function<br/> 
prefix[i] is the length of the longest proper prefix of the substring s[0...i] which is also a suffix of this subtring.
By definition, prefix[0] = 0.

prefix[i] = maximum k such that 
s[0...k-1] = s[i-(k-1)...i]
