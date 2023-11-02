# CS402-SP-L1
SP Lab 01 product
# Description
1.  SPLab 01 homework project. 
2.  Read employee data from the text file and read, search, and add the data to the list.
3.  When choosing to save the modification, then it will be written to the file name "DataBase_Updated.txt".
4.  File is consisted like as below
- readFile.h / readFile.c: Contains I/O related functions.
- workerlib.h / workerlib.c: Contains requirement of the homework.
- workerdb.c: Contains main function and run function named 'menu()'.
- workerdb.exe: Executable file. Needs 'database file path' as a argument.
- All the external function have been linked by their headers.
# How to work
- Enter code below from the 'Program' directory that stores all relevant data.
```
gcc readFile.c workerlib.c workerDB.c -o workerDB
workerDB DataBase.txt
```
