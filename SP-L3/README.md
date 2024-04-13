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
- [MacOS, UbuntuOS] Enter the code below from the 'Program' directory that stores all relevant data.
```
gcc *.c -o basicstats -lm
./basicstats small.txt
./basicstats large.txt
```
- [Window OS] Enter the code below from the 'Program' directory that stores all relevant data.
```
gcc *.c -o basicstats -lm
basicstats small.txt
basicstats large.txt
```
# Updates (Last update: 04.12.2024)
(04.12.2024) Code updates from previous version.
- Update readme and dates.
- Modify some function to work better.