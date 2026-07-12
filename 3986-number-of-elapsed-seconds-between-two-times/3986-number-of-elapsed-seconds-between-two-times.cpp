class Solution {
public:
    int secondsBetweenTimes(string s, string e) {
        int a = stoi(s.substr(0,2));
        int b = stoi(s.substr(3,2));
        int c = stoi(s.substr(6,2));
        int num1 = a*3600 + b*60 + c;
        int x = stoi(e.substr(0,2));
        int y = stoi(e.substr(3,2));
        int z = stoi(e.substr(6,2));
        int num2 = x*3600 + y*60 + z;
        return (num2 - num1);
    }
};