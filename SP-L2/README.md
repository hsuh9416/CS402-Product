# CS402-SP-L2
SP Lab 02 product
# Description
1.  SP Lab 02 homework project.
2.  Read employee data from the text file and read, search, and add the data to the list.
3.  [Optional] When choosing to save the modification, then it will be written to the file name "DataBase_Updated.txt".
4.  File is consisted like as below
5.  This project is modification of SP Lab 01. So it shares the same properties as the previous SP Lab 01 matarials.
- readFile.h / readFile.c: Contains I/O related functions.
- workerlib.h / workerlib.c: Contains requirement of the homework.
- workerdb.c: Contains main function and run function named 'menu()'.
- workerdb.exe: Executable file. Needs 'database file path' as a argument.
- All the external function have been linked by their headers.
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
# Updates (Last update: 04.05.2024)
(04.05.2024) Code updates from previous version.
- Changed some signatures to correspond to the requirements.
- Removed some functions that related to the requirements.
- Simplified and cleaned up some functions.
- Added missing docstrings.
(04.05.2024) Fix error from SP-L01
- Value error after testing: 64 -> 10 -> 64
- Coditional statement. No need to add 2 index!
- Will also reflect to the SP-L01