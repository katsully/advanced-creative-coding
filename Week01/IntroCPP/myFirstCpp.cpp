// HOW TO RUN THIS PROGRAM
// 1) Right click on the file name in the explorer and select 'Open in Terminal'
// 2) Compile, for Window users type cl myFirstCpp.cpp
// Mac users type g++ myFirstCpp.cpp
// 3) Run, for Window users type myFirstCpp
// Mac users type ./myFirstCpp


#include <iostream>
#include <ctime>

using namespace std;


// this function asks the user for a user, it also returns a bool representing if the user's guess was correct or incorrect
// it takes the answer as a parameter
bool makeAGuess(int answer)
{
    int userGuess;
    
    cout << "Guess a number : ";
    cin >> userGuess;
    cout << "your guess is " << userGuess << endl;

    if (userGuess < answer)
    {
        cout << "you're too low" << endl;
        return false;
    }
    else if (userGuess > answer)
    {
        cout << "you're too high!" << endl;
        return false;
    }
    // if the answer is not smaller than the answer or larger than the answer, the user guessed correctly
    else
    {
        cout << "You're doing amazing...you won my heart" << endl;
        return true;
    }

}

int main()
{
    // create new random sequence based on time of day 
    srand(time(NULL));  

    // this will generate a random number between 1 and 10
    // a different number will be generated each game
    // because it is declared outside of any function it is a global variable
    // const means the value of this variable will not be changed
    const int answer = rand() % 10 + 1;
    // cout << "answer " << answer << endl;

    // a variable letting us know if the user guessed corrected
    bool userCorrect = false;

    cout << "Let's play a game!" << endl;

    // keep guessing until user guesses correctly
    while (userCorrect == false)
    {
        userCorrect = makeAGuess(answer);
    }

    // let the user know they won the game
    cout << "You won the game!" << endl;


    return 0;
}
