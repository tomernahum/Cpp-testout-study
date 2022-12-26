#include <iostream>

//using namespace std;

#define LOG(x) std::cout << x << std::endl





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


//maybe one of the challenges the answer can be a hint for being able to unlock Shop
int main()
{
    int points = 0;
    
    
    Challenge currentChallenge = Challenge(0); //same as Challenge currentChallenge(0)
    while (true){
        
        std::cout << std::endl;
        std::cout << points << " points" << std::endl;
        std::cout << "Your next problem: " << currentChallenge.getQuestion() << std::endl;
        std::cout << std::endl;
        

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



    }

    
    
    return 0;
}
