#define print(x) std::cout << x << "\n"

#include <iostream>
#include <chrono>


/* Chat GPT wrote this for me*/
#include <iomanip>
#include <sstream>
std::string formatNumberWithCommas0(int n) {
  std::ostringstream out;
  out << std::fixed << std::setprecision(0) << std::setw(1) << std::setfill('0') << n;
  std::string s = out.str();
  int pos = s.length() - 3;
  while (pos > 0) {
    s.insert(pos, ",");
    pos -= 3;
  }
  return s;
}

//then i asked it not to use those libraries and it gave me this:
std::string formatNumberWithCommas(int n) {
  std::string s = std::to_string(n);
  int pos = s.length() - 3;
  while (pos > 0) {
    s.insert(pos, ",");
    pos -= 3;
  }
  return s;
}
/*----------*/



//framerate test

double fpsTest(int secondsToRun, void(*doStuffFunction)(int)) //takes in a function (function pointer), chatGPT told me there is also a std::function but yeah, im very scared
{
    double fps;
    
    auto startTime = std::chrono::high_resolution_clock::now();
    unsigned long int count = 0;
    while (true)
    {
        count++;
        doStuffFunction(count);

        auto currentTime = std::chrono::high_resolution_clock::now();
        auto timeElapsed = currentTime - startTime;
        if (timeElapsed > std::chrono::seconds(secondsToRun))
        {
            break;
        }
    }
    return count/secondsToRun;
    //didnt figure out how to get true clock speed at last loop

}


int main(int argc, char const *argv[])
{
    int secondsToRun;
    std::cout << "How many seconds (int) would you like to test per function (we'll run 3 functions) : ";
    std::cin >> secondsToRun;
    std::cout <<"\n"; 


    auto printCountFunc = [](int count){
        print(count);
    };
    double printCountFPS = fpsTest(secondsToRun, printCountFunc);
    print("print count fps: " << formatNumberWithCommas(printCountFPS));

    
    auto doNothingFunc = [](int count){
    };
    double doNothingFPS = fpsTest(secondsToRun, doNothingFunc);
    print("empty function fps: " << formatNumberWithCommas(doNothingFPS));

    // Declare a 3D array with typical screen width/height and 3 depth/rgb layers, to try to simulate what the fps of a game might be
    static int canvas[1920][1080][3];  //dont fully understand 3d arrays i copied this from chatGPT actually its gonna become a crutch i need to cut it off i think idk idk idk
    auto busyFunc1 = [](int count){
        // Assign values to each of the elements in the canvas 3d array
        for (int i = 0; i < 1920; i++) {
            for (int j = 0; j < 1080; j++) {
                for (int k = 0; k < 3; k++) {
                    canvas[i][j][k] = i + j + k;
                }
            }
        }
    };
    double busyFunc1FPS = fpsTest(secondsToRun, busyFunc1);
    print("1080p array loop fps: " << formatNumberWithCommas(busyFunc1FPS));



    
    return 0;
}

