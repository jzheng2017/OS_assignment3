# Memory Report

## Operating System | Assignment 3 | 31-10-2021

| Student name | Student number |
| ------------ | -------------- | 
| Jiankai Zheng | s1080484 |
| Shenghang Wang | s1034413 |

## Article by Kamp
### Summary
I think the issue in general that the article is trying to convey is that we like to reason about the performance of an algorithm in very abstract terms. 

This becomes very clear in the last section of the article ‘So Why are You, and I, Still doing it Wrong?’. 
In this section it is discussed that when we for instance reason about the performance of an algorithm using mathematical notations like Big O. 
We talk about an algorithm at a very high level by abstracting the details away. 
However in practice these details do matter very much, especially in operating systems like it was mentioned in the introduction of the third assignment. 

A good example of these details is for instance the memory access delays caused by virtual memory. What if it’s not in memory? The data must then be loaded into the memory. This takes quite some time. These abstractions do not talk about this while it is very important. This leads to issues where let’s say an algorithm that is O(n^2) but has minimal page faults and an algorithm that is in O(n) but has a lot of page faults. We automatically assume that the algorithm with O(n) time complexity is faster because we focus on the big O running time, but is it really faster in practice?

The final remark is that performance analysis of algorithms would be more accurate and interesting if it was applied to real computers and real situations and not just “toys” like the authors likes to call it. 

### Reasoning design choice B-Heap
TODO

## OS Configurations
### Host
| Type | Specification |
| ---- | ------------- |
| OS | Windows 10 Education 20H2 19042.1288 |
| System type | 64-bit operating system, x64-based processor |
| Processor | AMD Ryzen 5 1600 Six-Core Processor, 3200 Mhz, 6 Core(s), 12 Logical Processor(s) |
| Cache | L1 128KB, L2 512KB, L3 3MB
| RAM | 16GB |
| GPU | NVIDIA GeForce GTX 1060 6GB |
| HDD | Seagate Barracude 2TB ST2000DM006-2DM164 |
| SSD | Samsung SSD 850 EVO 250GB |

### Guest
| Type | Specification |
| ---- | ------------- |
| OS | Linux Ubuntu 21.04|
| Kernel | Linux 5.11.0-34-generic|
| Architecture | x86-64 |
| Processor | AMD Ryzen 5 1600 Six-Core Processor, 3200 Mhz, 6 Core |
| Memory | 4096 MB |
| HDD | 49.66 GB|
| Cache | L1d cache: 192 KiB, L1i cache: 384 KiB, L2 cache: 3 MiB, L3 cache: 16 MiB |

