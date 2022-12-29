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
int main(int argc, char const *argv[])
{
    const int SECONDS_TO_RUN = 1;

    double fps;
    
    auto startTime = std::chrono::high_resolution_clock::now();
    unsigned long int count = 0;
    while (true)
    {
        count++;
        print(count);

        auto currentTime = std::chrono::high_resolution_clock::now();
        auto timeElapsed = currentTime - startTime;
        if (timeElapsed > std::chrono::seconds(SECONDS_TO_RUN))
        {
            break;
        }
    }
    
    print("");
    //print(count/SECONDS_TO_RUN);
    print("fps: " << formatNumberWithCommas(count/SECONDS_TO_RUN));
    //didnt figure out how to get true clock speed at last loop
    
    return 0;
}

