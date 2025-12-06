#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>


int main() {

    std::string line;
    std::ifstream myfile ("aoc2.txt");
    long long total{};
    if (myfile.is_open()) {
        while (std::getline(myfile, line, ',')) {
            std::cout << line << std::endl;
            std::stringstream range(line);
            std::string num;
            std::vector<long long> vec;

            while (std::getline(range, num, '-')){
                // std::cout << std::atoll(num.c_str()) << std::endl;
                vec.push_back(std::stoll(num));
                // vec.push_back(num);
                
            }
            
            /*
            1) iterate from 0 to last index of the character of the current number, and make a substring of this, first do a check if the [total length] % []length of  this current substring] is 0. IF NOT then skip
            2) if it is valid, then do ANOTHER LOOP WITHIN, where its j = 0; j < [total length] % [length of  this current substring];  i++ 
                - checking if substr(j, i)it's equal to the original substring 
                - so like 12121212 would be looping 12 == 12, next 12 == 12, 3rd, and 4th etc
                    - at any point if false, then break out of everything and go back to 1) and do another iteration
            */
            for (long long i = vec[0]; i <= vec[1]; ++i) {
                std::string temp = std::to_string(i);
                const int n = static_cast<int>(temp.size());
                
                bool hasRepeatingPattern = false;

                // 1) iterate over possible substring lengths
                // we can stop at n/2 because repeating requires at least 2 copies
                for (int len = 1; len <= n / 2; ++len) {
                    // length must divide total length
                    if (n % len != 0) {
                        continue;
                    }

                    std::string pattern = temp.substr(0, len);

                    // 2) check all chunks of length len
                    bool ok = true;
                    for (int pos = len; pos < n; pos += len) {
                        // compare substring [pos, pos+len) to pattern
                        if (temp.compare(pos, len, pattern) != 0) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok) {
                        hasRepeatingPattern = true;
                        break;  // no need to try other lengths
                    }
                }

                if (hasRepeatingPattern) {
                    total += i;
                    std::cout << i << " (" << temp << ") is a repeated-pattern number\n";
                }
            }
        }
        myfile.close();
    }
    std::cout << total << std::endl;
    
    return 0;

}