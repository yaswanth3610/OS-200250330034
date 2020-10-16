* Program and Process
* compile and link
* build process
* Definition vs Declaration of fuctions
* make / Makefile
* git
    * git init, git status, git log, git add, git commit

* Sections 
    * .text
    * .data
    * .bss
    * stack 
    * heap

* Modular programs
    * Libraries
        * Standard libraries (linux - libc.a and libc.so)
        * User libraries/ 3rd party library
    * Two types
        * Static => *.a
        * Dynamic (Shared Objects) => *.so

* Static Library
    * ar x (extract)
    * ar crv libname.a 1.o 2.o..... n.o => (*.o)
    * lib function definitoin embedded in binary
    * multiple copies of library function loaded in the memory
    * more memory
* Dynamic Library
    * gcc -o libname.so -shared -fPIC
    * lib function deference definitoin embedded in binary
    * single copy of library function loaded in the memory
    * less memory


* PID, PPID, UID
* getpid(), getppid()
* man pages


* fork - create a new process
    * parent and child relationship

* Pseudo parallelism
* True parallelism

* ltrace
* strace
* Program using system call -> write a string inside a file.



