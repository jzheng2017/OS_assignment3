# Memory Report

## Operating System | Assignment 3 | 31-10-2021

| Student name | Student number |
| ------------ | -------------- | 
| Jiankai Zheng | s1080484 |
| Shenghang Wang | s1034413 |

## Summary article by Kamp
I think the issue in general that the article is trying to convey is that, we like to reason about the performance of an algorithm in very abstract terms. 

This becomes very clear in the last section of the article ‘So Why are You, and I, Still doing it Wrong?’. 
In this section it is discussed that when we for instance reason about the performance of an algorithm using mathematical notations like Big O. 
We talk about an algorithm at a very high level by abstracting the details away. 
However in practice these details do matter very much, especially in operating systems like it was mentioned in the introduction of the third assignment. 

A good example of these details is for instance the memory access delays caused by virtual memory. What if it’s not in memory? The data must then be loaded into the memory. This takes quite some time. These abstractions do not talk about this while it is very important. This leads to issues where let’s say an algorithm that is O(n^2) but has minimal page faults and an algorithm that is in O(n) but has a lot of page faults. We automatically assume that the algorithm with O(n) time complexity is faster because we focus on the big O running time, but is it really faster in practice?

The final remark is that performance analysis of algorithms would be more accurate and interesting if it was applied to real computers and real situations and not just “toys” like the authors likes to call it. 
