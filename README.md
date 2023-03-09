# Hamming Codes
This small project implements (15, 11) hammming codes in C++.

I learnt the concept of hamming codes from [this](https://youtu.be/X8jsijhllIA) YouTube video by 3Blue1Brown.

The code I've written is fairly simple and takes the 11-bit data as input from the user, which is converted to it's equivalent 16-bit hamming code.
It then takes the 16-bit message received by the receiver and run the checks on it to determine the error(s).

As you might have already seen, the code is kind of hard-coded for the (15, 11) hamming codes case. I am currently working on extending it and generalising the
program for any given number of data bits, for which I will have to study hamming codes in depth.

Please feel free to create any pull requests and drop any suggestions or feedback regarding the project.

Thanks

### hammingcodes.cpp
This is the main `.cpp` file which implements all the functions and produces the output. I could have created multiple files like header files and then do
multi-file compilation, but I did not do so for the sake of simplicity. I might implement it in a future version of the project though.
