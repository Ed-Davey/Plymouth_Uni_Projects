#include "Puzzle.h"
#include <iostream>

Puzzle::Puzzle(const std::string& question, const std::string& answer) 
    : question(question), answer(answer) {}

void Puzzle::displayQuestion() {
    std::cout << "Puzzle: " << question << std::endl;
}

bool Puzzle::checkAnswer(const std::string& userAnswer) {
    return userAnswer == answer;
}