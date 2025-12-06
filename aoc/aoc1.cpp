#include <iostream>
#include <fstream>
#include <string>

int realmod(int num) {
    return (num % 100  + 100) % 100;
}
int main() {
    // Given letter + a number
    // 
    // so start with 50 then you mod 100, 

    /*
    Plan: 
    1) Split the input by index 1
    2) Convert the 2nd part into an int (will it fit into int? looks like so, max 3 digits), 
    3) + or - depending on the L or R
    4) cout final result
    5) READ THE QUESTION U DUMBASS USE THE INPUT: OUTPUT METHOD
        The actual password is the number of times the dial is left pointing at 0 after any rotation in the sequence.
        6) if the operation != modded result then  
    */

    // std::cout << __cplusplus << std::endl;
    int num{50};
    int countofzeroes{0};
    std::string line;
    std::ifstream myfile ("aoc1.txt");
    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            std::cout << line << " " << num << std::endl;
            int addenum = std::stoi(line.substr(1));
            if (line.substr(0, 1) == "L") {
                if (num - addenum <= 0) {
                    if (num - addenum == 0) {
                        countofzeroes += 1;
                    }
                    else {
                        countofzeroes += std::abs(num - addenum) / 100 + (num != 0 ? 1 : 0);
                    }
                    // 60 - 70 = 1 wrap
                    // 60 - 120 = 1 wrap

                }
                num = realmod(num - addenum);
                // 0      99 
            }
            else {
                if (num + addenum > 99) {
                    countofzeroes += (num + addenum) / 100;
                }
                num = realmod(num + addenum);
                
            }
            
            
            // so 99 + 1 count
            // 99 + 2 counts
            // 1 - 1 counts
            // 1 - 2 counts 

            // 20 - 225 -> -205 would be abs(final) / 100 
            // 0 
            // -100
            // -200
        }
        myfile.close();
    }
    std::cout << num << std::endl;
    std::cout << countofzeroes << std::endl;


    return 0;

}