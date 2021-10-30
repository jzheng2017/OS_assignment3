# Memory Report

## Operating System | Assignment 3 | 31-10-2021

| Student name   | Student number |
| -------------- | -------------- |
| Jiankai Zheng  | s1080484       |
| Shenghang Wang | s1034413       |

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
| Type        | Specification                                                                     |
| ----------- | --------------------------------------------------------------------------------- |
| OS          | Windows 10 Education 20H2 19042.1288                                              |
| System type | 64-bit operating system, x64-based processor                                      |
| Processor   | AMD Ryzen 5 1600 Six-Core Processor, 3200 Mhz, 6 Core(s), 12 Logical Processor(s) |
| Cache       | L1 128KB, L2 512KB, L3 3MB                                                        |
| RAM         | DDR4 16 GB: 2 x 8 GB DIMM 288-PIN - 3000 MHz                                      |
| GPU         | NVIDIA GeForce GTX 1060 6GB                                                       |
| HDD         | Seagate Barracude 2TB ST2000DM006-2DM164                                          |
| SSD         | Samsung SSD 850 EVO 250GB                                                         |

### Guest
| Type         | Specification                                                             |
| ------------ | ------------------------------------------------------------------------- |
| OS           | Linux Ubuntu 21.04                                                        |
| Kernel       | Linux 5.11.0-34-generic                                                   |
| Architecture | x86-64                                                                    |
| Processor    | AMD Ryzen 5 1600 Six-Core Processor, 3200 Mhz, 6 Core                     |
| Memory       | 4096 MB                                                                   |
| HDD          | 49.66 GB                                                                  |
| Cache        | L1d cache: 192 KiB, L1i cache: 384 KiB, L2 cache: 3 MiB, L3 cache: 16 MiB |

## Baseline configuration
### Input parameters
We have not changed the default value of these variable because using these configurations the algorithm already runs beyond 20 seconds.
| Variable | Value    |
| -------- | -------- |
| SIZE     | 16384ULL |
| REPEAT   | 1ULL     |

### Baseline statistics
| Type                          | Value             |
| ----------------------------- | ----------------- |
| user time:                    | 33.500803 seconds |
| soft page faults:             | 524398            |
| hard page faults:             | 0                 |
| max memory:                   | 2099880 KiB       |
| voluntary context switches:   | 0                 |
| involuntary context switches: | 206               |
| dummy value (ignore):         | 549755813888      |

## Optimization
### Changes to code
| Optimization                         | Rationale |
| ------------------------------------ | --------- |
| Remove nested for loop (line: 54-58) that sums up the values of the `res` array to the `dummy` variable. This has been moved to the main nested for loop. | We did this because it is logical to add the new pixel at the place of calculation. This removes the need for looping through the whole `res` array again which dramatically reduces the running time of the algorithm. |
| Remove/Expand the `k` and `j` for loop. | We have expanded these two for loops because the number of iterations is constant, namely `3` times. Since it is a nested for loop which both loop `3` times, the number of iterations in total is `9` times. We have duplicated the executed statement `9` times with each a small difference, namely the `k` and `j` variable has been replaced by their respective constant, which ranges from [-1, 1]. This decreases the running time as there is no need to allocate memory for the two for loops anymore. |
| Introduce new `res` datastructure. Using a multi-dimensional (2D) array instead of a single dimensional array. | The problem with using a single dimensional array for this algorithm is that it tries to simulate a 2D array using a 1D array. By doing that it will each time access the array at an index that is 'far away' from eachother (and potentially not continuous in memory). This increases the chance for a page fault because it might not be in memory. We solved this by using a 2D array that solves the need for constantly accessing values in the array that are far away from eachother. Using the 2D array we can just 'sequentially' go through the array and add values instead of 'jumping' through the array. |
| Introduced a `tmp` variable that acts as a temporary storage for calculation. | We decided to use a new variable to act as a temporary storage for the calculation. This is because then we don't need to keep calculating the index which saves some instructions on a single iteration but saves a lot when you keep in mind how many times these instructions will be executed in this loop. Besides that, we don't have to access that value in the array anymore which might prevent a page fault as that specific value in the array might not be in memory at that time. |

### Statistics after optimization
| Type                          | Value                          |
| ----------------------------- | ------------------------------ |
| user time:                    | 13.353798 s (~60.29% decrease) |
| soft page faults:             | 262285 (~49.98% decrease)      |
| hard page faults:             | 0                              |
| max memory:                   | 1051560 KiB (~49.9% decrease)  |
| voluntary context switches:   | 0                              |
| involuntary context switches: | 53 (~74.3% decrease)           |
| dummy value (ignore):         | 549755813888                   |