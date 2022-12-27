#include <iostream>

//using namespace std;

#define print(x) std::cout << x << std::endl





int getChallenge(int difficulty){
    // return question + answer (right?)
    return 0;
}

class Challenge {
    public:
        Challenge(int difficulty){
            m_question = "2+2";
            m_answer = "4";

            if (difficulty==1){
                m_question = "3+3";
                m_answer = "6";
            }
        }
        Challenge(){
        }
        /*
        static Challenge getChallenge(int difficulty) {
            Challenge challenge;
            challenge.question = "2+2";
            challenge.answer = "4";
            
            return challenge;
        }
        */

        std::string getQuestion(){ return m_question;}
        bool checkAnswer(std::string answerAttempt){
            //TODO: clean up answer of whitespace / capitalization
            return answerAttempt == m_answer;

        }
    private:
        std::string m_question;
        std::string m_answer;  
};

#include <chrono>
#include <thread>
void sleep(float seconds){
    const int milliseconds = 1000*seconds;
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}


//maybe one of the challenges the answer can be a hint for being able to unlock Shop
int main()
{
    int points = 0;
    
    
    Challenge currentChallenge = Challenge(0); //same as Challenge currentChallenge(0)
    while (true){
        
        print(points << " points");
        sleep(0.1); //todo make this one function
        print( "Your next problem: " << currentChallenge.getQuestion() );
        sleep(0.1);


        std::cout << "> ";
        std::string userInput;
        std::cin >> userInput;


        if(userInput == "exit"){
            break;
        }


        else if(currentChallenge.checkAnswer(userInput)) {
            std::cout << "correct!" << std::endl;
            points++;
            currentChallenge = Challenge(1); //Q/N is this safe/correct??
        }
        else {
            std::cout << "incorrect!" << std::endl;
        }

                
        sleep(0.5);
        print("");



    }

    /*
    todo: 
        - run function to increment points every x seconds
        - overwrite display in console
    */
    
    return 0;
}
