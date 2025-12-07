#include <iostream> //this allows for input and output within the program

double x, y, distance1, distance2; //this declares the variables x, y, distance1 and distance2 as file type double

double EuclideanDistance(double x,double y,double distance) { //this creates a function called EuclideanDistance with the data type double with the values x, y and distance being allowed to be passed in
    double x2, y2, sum; //this declares the variables x2, y2 and sum as the file type double
    x2 = x*x; //this multiplies x by itself to create x squared
    y2 = y*y; //this multiplies y by itself to create y squared
    sum = x2 + y2; //this adds x squared and y squared together and saves it into the variable sum
    distance = sqrt(sum); //this square roots sum to find the distance
    return distance; //this returns the value inside the distance variable to the main code
}

int main()
{
    //first point
    std::cout << "What is the X coordinate for the first point? "; //this makes "What is the X coordinate for the first point? " appear on the screen
    std::cin >> x; //This will take what is typed on the keyboard and save it in the variable x
    std::cout << "What is the Y coordinate for the first point? "; //this makes "What is the Y coordinate for the first point? " appear on the screen
    std::cin >> y; //This will take what is typed on the keyboard and save it in the variable x
    std::cout << std::endl; //this will end the line in the terminal

    distance1 = EuclideanDistance(x, y, distance1); //this will call the EuclideanDistance function and pass the values stored in x, y and distance1 and store the result in distance1

    std::cout << "The euclidean distance from the origin (0,0) is " << distance1 << std::endl << std::endl; //this makes "The euclidean distance from the origin (0,0) is " appear on the screen with the value stored in distance1 after

    //second point
    std::cout << "What is the X coordinate for the second point? "; //this makes "What is the X coordinate for the second point? " appear on the screen
    std::cin >> x; //This will take what is typed on the keyboard and save it in the variable x
    std::cout << "What is the Y coordinate for the second point? "; //this makes "What is the Y coordinate for the second point? " appear on the screen
    std::cin >> y; //This will take what is typed on the keyboard and save it in the variable y
    std::cout << std::endl; //this will end the line in the terminal

    distance2 = EuclideanDistance(x, y, distance2); //this will call the EuclideanDistance function and pass the values stored in x, y and distance2 and store the result in distance2

    std::cout << "The euclidean distance from the origin (0,0) is " << distance2 << std::endl; //this makes "The euclidean distance from the origin (0,0) is " appear on the screen with the value stored in distance2 after
    return 0; //this will return the value 0 to the program which lets the program know that the main function was executed
}