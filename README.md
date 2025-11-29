FILE DESCRIPTION
----------------
The project consists of the following files
1. main.cpp
    - Entry point of program. Handles user input for the number of certificates and word length.

2. Certificate.h/.cpp
    - Defines the certificate class (types of docment)
    - handle storage of hexadecimal words
    - implement similarity logic (comparing first word digit)

3. DocumentHandler.h
    - Defines template class
    - stores collection of generic documents
    - Calculates statistics:
        a. Minimum Similarity across all document pairs.
        b. Digit Frequency (Least and Most frequent hexadecimal digits).


COMPILATION INSTRUCTIONS
------------------------
This program is written in C++ and can be compiled using the g++ compiler.
Ensure all files within the same directory before compiling

Open terminal or command prompt and run the following command:
    g++ *.cpp -o Run


EXECUTION INSTRUCTIONS
----------------------
To run the program after compilation, execute the following command:
    Run.exe


Upon Running,
the program will prompt for:
- The number of certificates to generate (Integer).
- The number of words per certificate (Integer).

