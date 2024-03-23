# CS402-SP-L1
SP Lab 01 product
# Description
1.  SPLab 01 homework project. 
2.  Read employee data from the text file and read, search, and add the data to the list.
3.  The file is consisted of as in the following.
- readfile.h / readfile.c: Contains I/O related functions.
- workerlib.h / workerlib.c: Contains functions for the SP-L1 requirements.
- workerdb.c: Contains the main function and the run function named 'menu()'.
- workerdb.exe: Executable file. Needs a 'database file path' as an argument.
- All the external functions have been linked by their headers.
# How to work
- [MacOS, UbuntuOS] Enter the code below from the 'Program' directory that stores all relevant data.
```
gcc readfile.c workerlib.c workerDB.c -o workerDB
./workerDB DataBase.txt
```
- [Window OS] Enter the code below from the 'Program' directory that stores all relevant data.
```
gcc readfile.c workerlib.c workerDB.c -o workerDB
workerDB DataBase.txt
```
# Updates (Last update: 03.22.2024)
(03.20.2024) Code updates from previous version.
- Changed some signatures to correspond to the requirements.
- Removed some functions that related to the requirements.
- Simplified and cleaned up some functions.
- Added missing docstrings.
(03.22.2024) Corrected file reference.
- Unlike MacOS, UbuntuOS track file name as case sensitive. 
- Thus, changed file reference to correspond to real name.
- Also changed to execution command to correspond to the filename.
(03.22.2024) Fixed some error.
- load_db set incorrectly -> fixed.
(03.22.2024) Added input handling.
- 'read_int' will detect invalid input(such as float) then reject as EOF. 
(03.22.2024) Added window, UbuntuOS version execution method. 
(03.23.2024) Change some format.
- Ternary operators to standard if/else statements.
(03.23.2024) Added some error handlings.
- Error handling for maximum input string as 64 char(including '\0').
- Error handling for the function 'find_emp_by_LN()'.