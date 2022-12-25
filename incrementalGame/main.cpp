#include <iostream>

using namespace std;




int getChallenge(int difficulty){
    // return question + answer (right?)
    return 0;
}

class Challenge {
    public:
        Challenge(int difficulty){
            m_question = "2+2";
            m_answer = "4";
        }
        /*
        static Challenge getChallenge(int difficulty) {
            Challenge challenge;
            challenge.question = "2+2";
            challenge.answer = "4";
            
            return challenge;
        }
        */

        string getQuestion(){ return m_question;}
        bool checkAnswer(string answerAttempt){
            //TODO: clean up answer of whitespace / capitalization
            return answerAttempt == m_answer;

        }
    private:
        string m_question;
        string m_answer;  
};



int main()
{
    int points = 0;
    
    
    
    while (true){
        
        Challenge currentChallenge(0); 
        //^I want this to be defined outside each loop, and reset only if you get the challenge right
        
        cout << endl;
        cout << points << " points" << endl;
        cout << "Your next problem: " << currentChallenge.getQuestion() << endl;
        
        cout << "> ";
        string userInput;
        cin >> userInput;

        if(currentChallenge.checkAnswer(userInput)) {
            cout << "correct!" << endl;
            points++;
            //make a new challenge
        }
        else {
            cout << "incorrect!" << endl;
        }



    }

    
    
    return 0;
}
