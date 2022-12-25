#include <iostream>
using namespace std;

/*
    Arrays are fixed size

    an array is really a pointer to the beginning of the array (then the elements are stored next to each other in memory)
    int example[5];
    type of 

*/

int main()
{
    int favNums[] = {0, 1, 2}; // equivilent to favNums[3] = {0,1,2} (probably better practice idk)
    int favNumsSize = sizeof(favNums) / sizeof(int); 
    /* - sizeof counts size of something in bytes
       - to find array length you need to divide sizeof */
    for (int i = 0; i < favNumsSize; i++)
    {
        cout << favNums[i] << endl;
    }

    cout << "------\n";

    favNums[0] = 69;
    for(auto var : favNums)
    {
        cout << var << endl;
    }

    cout << "----\n";

    
    /* If you go over the size you get a random thing from memory*/
    cout << favNums[99] << endl; 
    
    
    //favNums[3] = 420;  // stack smashing detected, still printed it though
    //cout << favNums[3] << endl;



//-------------------------
    printf("--------------\n");

    string favNames[10] = {"Amy", "Ryan", "blocoblabla"};
    //we allocated 10 and initialized first 3, can still allocate 7 more

    cout << sizeof(char);

    cout << endl;
    return 0;
}


/*
    For auto resize // list equivilent, you can use
    std::vector<type> name = {}
    name.push_back()
*/