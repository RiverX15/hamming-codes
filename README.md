# Hamming Codes
This small project implements (15, 11) hammming codes in C++.

I learnt the concept of hamming codes from [this](https://youtu.be/X8jsijhllIA) YouTube video by 3Blue1Brown.

The code I've written is fairly simple and takes the 11-bit data as input from the user, which is converted to it's equivalent 16-bit hamming code.
It then takes the 16-bit message received by the receiver and run the checks on it to determine the error(s).

As you might have already see, the code is kind of hard-coded for the (15, 11) hamming codes case. I am currently working on extending it and generalising the
program for any given number of data bits, for which I will have to study hamming codes in depth.

Please feel free to create any pull requests and drop any suggestions or feedback regarding the project.

Thanks

### hammingcodes.cpp
This is the main `.cpp` file which implements all the functions and produces the output. I could have created multiple files like header files and then do
multi-file compilation, but I did not do so for the sake of simplicity. I might implement it in a future version of the project though.

### data.csv
This is a `.csv` file which contains the 11-bit data inputs, the 16-bit received data inputs and the correct 16-bit messages after processing. The file `data.xlsx` is
the Excel version of the same. With this file, I wish to store all the ~2<sup>27</sup> possible combinations of the inputs and outputs. This would require a hell lot
of processing and optimisations on the current code, and I think I will have to rely a high performance machine for this purpose.

### hammingcodes_script.sh
This is a `.sh` file which I wrote to execute the `hammingcodes.cpp` function on my local machine. `hammingcodes.exe` is the executable created as a result 
of the `g++` commands.
