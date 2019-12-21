//
//  main.cpp
//  CodingChallengeTest
//
//  Created by adeeb mohammed on 21/12/19.
//  Copyright © 2019 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <vector>

/*
    this is the problem for finding out the state of each cell
 after a given number of days.
 the number of the cell is 8
 condition 1: 1 represent active cell , 0 inactive
 condition 2: adjacent cells can be either asctive or inactive
 condition 3: if adjacent cells are same the cell become
            inactive on the next day
 condition 4: the adjacent cells are different the cell
            become active on the next day
 
 */

std::vector<int> cellCompete(int* states, int days){
    // total number of cells
    const int totalCells = 8;
    // temporary array to store the updated state
    int tempStates[totalCells];
    // vector for storing the result array
    std::vector<int> resultVector;
    
    // storing the actual state of the array initially
    for(int i = 0;i < totalCells; i++){
        tempStates[i] = states[i];
    }
    
    // processing the cell states each day
    while(days--){
        // processing the edge case
        // assigning corner states to zero
        //(avoiding an else condition)
        tempStates[0] = 0;
        tempStates[totalCells-1] = 0;
        // check whether the right side of left
        // cornered cell is 1 then the cell state is 1
        if(states[1] == 1){
            tempStates[0] = 1;
        }
        // check the above condition for right side cell
        if(states[totalCells - 2] == 1){
            tempStates[totalCells - 1] = 1;
        }
        // check the condition for the other cells
        // except the corner cells
        for(int i =  1; i <= (totalCells - 2); i++) {
            // make the states active for avoding the else check
            tempStates[i] = 1;
            if(states[i-1] == states[i+1]){
                tempStates[i] = 0;
            }
        }
        // storing the current state for next iteration
        for(int i = 0; i < totalCells; i++){
            states[i] = tempStates[i];
        }
    }
    // storing the final state after the specified days
    for(int i = 0; i < totalCells; i++){
        resultVector.push_back(states[i]);
    }
    
    return resultVector;
}
int main(int argc, const char * argv[]) {
    std::cout << "compute the state of the cells"<<std::endl;
    return 0;
}
