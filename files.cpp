#define print(x) std::cout << x << std::endl

#include <iostream>
#include <fstream>    //remember this line!


int main(int argc, char const *argv[])
{
    //need to open file to read/write to it (using streams)

    std::string infile_name = "file.txt";

    std::ifstream myFile; 
    myFile.open(infile_name);   //looks in current directory (can use full file path)../  if using windows file address remeber to escape \
    //std::ifstream test("file.txt");  //works too 

    if (myFile.fail() || !myFile.is_open())
    //slides said to check myFile.fail() every time you read from it
    {
        print("Error opening file");
        return -1;
    }
    
    std::string stringVar;
    double doubleVar;
    
    while(myFile >> stringVar) // >> moves 1 word at a time and returns true or false when file is done being read (returns myFile)
    {
        print(stringVar);
    }
    
    myFile.close(); // closes automatically at end of program if you dont do .close()

    print("-----\n");
    
    
    //testing numbers
    std::ifstream myFile1; 
    myFile1.open("file2.txt");

    while (myFile1 >> doubleVar){
        print(doubleVar);
    }
    
   
    /*
        myFile >> varA >> varB;
        seems to be equivilent to:
        myFile >> varA;
        myFile >> varB;
    */

    //Ways to read from file::
    
    std::ifstream myFilee("file.txt");
    std::string myVar;
    
    //reads 1 word at a time, discards whitespace (if myVar is string)
    myFilee >> myVar;

    //reads 1 line at a time
    std::getline(myFilee, myVar);

    //???  reads 1 char at a time
    //myFilee.get(charVar); 
    myFilee.unget();  //goes back in stream

    //read X chars at a time, getline gets rid of the \n
    char cstringVar[100];
    myFilee.getline(cstringVar, 99);
    myFile.get(cstringVar, 50);

    
    
    /*
    Yet unknown but in course slides/textbook

    1. iomanip formatting
    2. reading binary files ios::binary
        - seekg[et](position) seekp[put](position)
    
    */




    //see test_files.cpp






    print("\n\n-----\n");

    

    //Video not presentation notes
    std::fstream myFile2;
    myFile2.open("file.txt", std::ios::in); //or: std::ios::out

    myFile2 >> stringVar; //gets a word at a time (terminated by space etc)
    print(stringVar);

    for (int i = 0; i < 4; i++)
    {
        std::getline(myFile2, stringVar); //gets a line
        print(stringVar);

        //getline returns False when its done with the file, so you can do
        //while (getline())  // also file.eof() (end of file)
        // >> also does
    }
    


    

    print("-----\n");
    myFile2.open("file.txt", std::ios::out);


    /*
    ios::in     reads 1 word at a time (aparently)
    ios::out    writes 1 string at a time   (resets file)
    ios::app    writes to file in append mode (doesnt reset previous contents)
    */


    return 0;
}


