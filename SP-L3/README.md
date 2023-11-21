# CS402-SP-L3
SP Lab 03 product
# Description
1.  SP Lab 03 homework project.
2.  Implement some statistic functions utilizing a pointer property.
3.  Restriction has applied as below:
    * Make full use of pointer properties without using global variables.
    * Implement a dynamic array using malloc.
    * Except sqrt in the math library, all statistical functions are implemented directly.
4. The main library is included in header 'statslib.h' and is referenced only once throughout the program.
5. The header 'statslib.h' serves to link functions referenced by the main file 'statslib.c' along with the library. 
6. On the other hand, 'statslib.c' consists of main functions that contain the actual requirements of the program and auxiliary functions that assist in the execution of those functions.
# How to work
- Enter code below from the 'SP-L3/Program' directory that stores all relevant data.
```
gcc *.c -o basicstats -lm
basicstats small.txt
basicstats large.txt
```
# Update for Linux execution(11.20.2023)
- Execution has been valid in Window environment, but not work as the same in Linux. So some modifictaion added like as follow:
```
gcc *.c -o basicstats -lm
basicstats small.txt
basicstats large.txt
```