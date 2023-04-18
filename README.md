# stroustrup-exercises
Completed exercises and drills from the book "Principles and Practice Using C++ Second Edition".

Compiled using g++ and C++14.  
Run the following command inside the terminal to check the value of the *__cplusplus* macro:  
`g++ -dM -E -x c++ /dev/null | grep -F __cplusplus`  
should return  
`#define __cplusplus 201402L`    

Compile (and run) files while inside the correct directory using:  
`g++ code.cpp -o code.o && ./code.o`  
FLTK (Chapters 12, 13, 14, 15, 16) uses special g++ flags to compile and the correct command is given inside *sources.h* or *fltkhelp.txt*.  

All exercises were completed using the techniques and facilities I was familiar with at the time.

![Programming Principles and Practice Using C++](https://www.stroustrup.com/PPP2frontNback.jpg)
