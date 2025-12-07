#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>

class Puzzle {
public:
    Puzzle(const std::string& question, const std::string& answer);
    bool checkAnswer(const std::string& userAnswer);
    void displayQuestion();

private:
    std::string question;
    std::string answer;
};

#endif // PUZZLE_H