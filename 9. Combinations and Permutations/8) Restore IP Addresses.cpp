/* Given a string containing only digits, restore it by returning all possible valid IP address combinations.
For example: Given "25525511135",
return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)*/

class Solution{
private:
    void restoreIP(string& digits, int segment, int idx, string ip, vector<string>& result){
        if (segment * 3 < digits.size() - idx) return;
        if (!segment){
            if (idx == digits.size()){
                ip.pop_back();
                result.push_back(ip);
            }   
            return;
        }
        
        if (digits[idx] == '0'){
            restoreIP(digits, segment - 1, idx + 1, ip + "0.", result);
        }else{
            for (int end = idx; end < digits.size() && end - idx + 1 <= 3; end++){
                string num = digits.substr(idx, end - idx + 1);
                if (stoi(num) <= 255){
                    restoreIP(digits, segment - 1, end + 1, ip + num + ".", result);
                }
            }    
        }        
    }
public:
    vector<string> restoreIpAddresses(string digits) {
        if (digits.empty()) return {};
        vector<string> result;
        string ip;
        restoreIP(digits, 4, 0, ip, result);
        return result;
    }
};

