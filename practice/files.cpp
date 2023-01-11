#define print(x) std::cout << x << "\n"

#include <iostream>
#include <fstream>


//word by word
void one()
{
    std::ifstream filestream;
    filestream.open("file.txt");

    std::string stringVar;
    while (filestream >> stringVar)
    {
        print(stringVar);
    }
    filestream.close();
}

//line by line
void two()
{
    std::ifstream filestream;
    filestream.open("file.txt");

    std::string stringVar;
    while (std::getline(filestream, stringVar))
    {
        print(stringVar);
    }
    filestream.close();
}

//char by char
void three()
{
    std::ifstream filestream;
    filestream.open("file.txt");

    char charVar;
    while (filestream.get(charVar))
    {
        print(charVar);
    }
    filestream.close();
}

//multiple chars by chars is filestream.get(charArrayVar, <NumChars>)

void splitString()
{
    
}


void readData(std::string line)
{
    //get substrings
    int splitPoint = line.find(": ");
    print(splitPoint);
    
    std::string category = line.substr(0, splitPoint);
    std::string value = line.substr(splitPoint+2);

    print(category);
    print(value);
    print("");
    //should return it maybe
}

void readSaveFile()
{
    std::ifstream filestream;
    filestream.open("file.txt");



    std::string line;
    while (std::getline(filestream, line))
    {
        if (line == "")
        {
            continue;
        }
        if (line == "Inventory: ")
        {
            print("OMG");
            break;
        }

        readData(line);
    }

    while (std::getline(filestream, line))
    {
        //read other format. could just have same format haha
    }



    filestream.close();
}






int main(int argc, char const *argv[])
{
    readSaveFile();
    
    return 0;
}

/*
MISSING KNOWLEDGE: 
fstream usage (not ifstream or ofstream)
incl binary file manipulation
*/