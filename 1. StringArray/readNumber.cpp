class Solution{
private:
    unordered_map<int, string> wordMap{
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"}
    };

    string num2word(int num){
        return wordMap[num];
    }
        


public:
    string readNumber(int number){
        if (number == 0)
            return num2word(0);
        
        ostringstream oss;
        if (number < 0) {
            oss << "minus ";
            number = - number;
        }

        int segment = 0;
        for (int num = number; num > 0; num /= 1000)
            segment++;

        vector<string> units {"", "Thousand", "Million", "Billion"};

        for (int seg = segment - 1; seg >= 0; seg--){
            int num = number % static_cast<int>(pow(1000, seg + 1)) / static_cast<int>(pow(1000, seg));
            
            if (num == 0) continue;

            // get hundred 
            int hund = num / 100;
            if (hund != 0)
                oss << num2word(hund) + " Hundred ";

            if (num % 100 != 0){
                if (seg != segment - 1)
                    oss << "and ";

                // get ten
                int ten = num % 100 / 10;
                if (ten == 1){
                    oss << num2word(num % 100) << " ";
                }else{
                    if (ten != 0 )
                        oss << num2word(ten * 10) << "-";
                    
                    // get one
                    int one = num % 10;
                    if (one != 0){
                        
                        oss << num2word(one) << " ";
                    }
                }
            } 
            oss << units[seg] << " ";
        }
        return oss.str();
    }
};


// without and , -

class Solution{
private:
    unordered_map<int, string> wordMap{
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"}
    };

    string num2word(int num){
        return wordMap[num];
    }
        


public:
    string numberToWords(int number){
        if (number == 0)
            return num2word(0);
        
        ostringstream oss;
        if (number < 0) {
            oss << "minus ";
            number = - number;
        }

        int segment = 0;
        for (int num = number; num > 0; num /= 1000)
            segment++;

        vector<string> units {"", "Thousand", "Million", "Billion"};

        for (int seg = segment - 1; seg >= 0; seg--){
            int num = number % static_cast<int>(pow(1000, seg + 1)) / static_cast<int>(pow(1000, seg));
            
            if (num == 0) continue;

            // get hundred 
            int hund = num / 100;
            if (hund != 0)
                oss << num2word(hund) + " Hundred ";

            if (num % 100 != 0){
                // get ten
                int ten = num % 100 / 10;
                if (ten == 1){
                    oss << num2word(num % 100) << " ";
                }else{
                    if (ten != 0 )
                        oss << num2word(ten * 10) << " ";
                    
                    // get one
                    int one = num % 10;
                    if (one != 0)
                        oss << num2word(one) << " ";
                }
            } 
            oss << units[seg];
            if (seg != 0) oss << " ";
        }
        string ret = oss.str();
        ret.pop_back();
        return ret;
    }
};


