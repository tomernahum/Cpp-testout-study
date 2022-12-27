#!/bin/bash
g++ "$@" -pthread && ./a.out


#"$@" is supposed to get all arguments and put them in there but im not an expert
# -pthread makes threading work on my system

# g++ is what was reccomended originally by a class I took, 
# I think it does compiling and linking (and anything else?)
# if you put in multiple files it seems to compile and link them and put in a.out

# && runs the second command only if the first was successfull. you probably knew that.