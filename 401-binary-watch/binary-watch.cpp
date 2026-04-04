class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        if(turnedOn > 8) return {};
        if(turnedOn == 0) return {"0:00"};
        unordered_map<int, vector<int>> hours_bits;
        unordered_map<int, vector<int>> minutes_bits;
        for(int i = 0; i < 60; i++) {
            int count = 0;
            int n = i;
            while (n > 0) {
                n &= (n - 1); 
                count++;
            }
            if(i < 12) {
                hours_bits[count].push_back(i);
            }
            minutes_bits[count].push_back(i);
        }

        vector<string> times;
        for(int i = 0; i <= turnedOn && i <= 3; i++) {
            for(int j: hours_bits[i]){
                string hour = to_string(j) + ":";
                for(int k: minutes_bits[turnedOn - i]) {
                    if(k < 10) times.push_back(hour + "0" + to_string(k));
                    else times.push_back(hour + to_string(k));;
                }
            }
        }

        return times;
    }
};