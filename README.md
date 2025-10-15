
# Using GCC with MinGW 

https://code.visualstudio.com/docs/cpp/config-mingw


# Dev C++

https://www.bloodshed.net/


# Online compilers

https://www.onlinegdb.com/online_c_compiler

https://www.programiz.com/c-programming/online-compiler/

# Adding gcc to PATH in Windows

Follow instructions here:
https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/


# Checking if gcc is installed
Open Command Prompt and type:

```bash
gcc --version
```
If gcc is installed, it will display the version information. If not, you will see an error message indicating that the command is not recognized.


# How to compile and run C code

Assuming you have gcc installed,

go to the terminal, 

to navigate to the directory where your C file is located,
use the `cd` command, for example:

```bash
cd path/to/your/c/file
```

Then, to compile the C file, use the `gcc` command


and run:

```bash
gcc filename.c -o outputname
```

To run the compiled program, use:

```bash
./outputname
```
