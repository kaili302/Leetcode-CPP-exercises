/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
    	assert(matrix.size());
    	int HE = matrix.size();
    	int WI = matrix[0].size();

    	bool isFirstRowZero = false;
    	for (int i=0; i<WI; i++) {
    		if (!matrix[0][i]) {
    		    isFirstRowZero = true;
    		    break;
    		}
    	}
    	
    	bool isFirstColZero = false;
        for (int i=0; i<HE; i++) {
            if (!matrix[i][0]) {
                isFirstColZero = true;
                break;
            }
        }

    	for (int i=0; i<HE; i++) {
    		for (int j=0; j<WI; j++) {
				if (!matrix[i][j]) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
    		}
    	}
        
        // set column zeros
    	for (int j=1; j<WI; j++) {
    		if (!matrix[0][j]) {
    			for (int i=1; i<HE; i++) matrix[i][j] = 0;
    		}
    	}

    	// set row zeros
    	for (int i=1; i<HE; i++) {
    		if (!matrix[i][0]) {
    			for (int j=1; j<WI; j++) matrix[i][j] = 0;
    		}
    	}

    	if (isFirstRowZero) matrix[0].assign(WI, 0);
    	if (isFirstColZero) {
    		for (int i=1; i<HE; i++) matrix[i][0] = 0;
    	}
    }
};