This project has been created as part of the 42 curriculum by rarayano.

## Description
The `push_swap` project aims to sort numbers with least possible amount of commands.

This project was made by implementing **Chunk algorithm**.
this algorithm focuses on divinding numbers into specific chunks/segments, and pushing them to Stack B sequentially. This reduces the search space and makes pushing the numbers back to Stack A in descending order significantly more efficient.

This project 

### Technical Struggles
During the development of this project, my main struggles revolved around:
* **Linked Lists:** Adapting to and manipulating custom linked list structures to properly and safely represent the stacks without memory leaks or segmentation faults.
* **Chunk Algorithm Logic:** Fine-tuning the chunk sizes and boundaries to ensure the algorithm remains fully optimized within the tight operational limits set by the benchmark requirements. 

## Instructions

### Compilation
A `Makefile` is provided to compile the source code into the executable. 

To compile the mandatory part, simply run:
```bash
make
```

run the program
```bash
./push_swap {numbers}
```

run the program with tester
```bash
./push_swap {numbers} | ./checker_OS {same number}
```

### Linked Lists

* [Short introduction to linked lists in C](https://www.youtube.com/watch?v=uBZHMkpsTfg) - CodeVault
* [Understanding and implementing a Linked List in C and Java](https://www.youtube.com/watch?v=VOpjAHCee7c) - Jacob Sorber
* Extensive discussions and code reviews with peers, which helped solidify pointer concepts and catch edge cases.
