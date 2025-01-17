#include <vector> // Include vector header for using vectors

// The Solution class definition
class Solution {
public:
    // Function checks if there exists a valid array such that all of its elements XORed equals zero
    bool doesValidArrayExist(std::vector<int>& derivedArray) {
        int cumXor=0;

        for(int i=0; i<derivedArray.size(); i++){
            cumXor=cumXor^derivedArray[i];
        }

        return cumXor==0;
    }
};
