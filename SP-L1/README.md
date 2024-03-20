# CS402-SP-L1
SP Lab 01 product
# Description
1.  SPLab 01 homework project. 
2.  Read employee data from the text file and read, search, and add the data to the list.
3.  The file is consisted of as in the following.
- readFile.h / readFile.c: Contains I/O related functions.
- workerlib.h / workerlib.c: Contains functions for the SP-L1 requirements.
- workerdb.c: Contains the main function and the run function named 'menu()'.
- workerdb.exe: Executable file. Needs a 'database file path' as an argument.
- All the external functions have been linked by their headers.
# How to work
- [MacOS] Enter the code below from the 'Program' directory that stores all relevant data.
```
gcc readfile.c workerlib.c workerDB.c -o workerDB
./workerDB DataBase.txt
```
# Updates (Last update: 03.20.2024)
(03.20.2024) Code updates from previous version
- Changed some signatures to correspond to the requirements.
- Removed some functions that related to the requirements.
- Simplified and cleaned up some functions.
- Added missing docstrings.