class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long total = 0; // Using long to handle overflow safely

        while (i < s.size() && s[i] == ' ') i++;  // Skip leading spaces
        if (s[i] == '-' || s[i] == '+') sign = (s[i++] == '-') ? -1 : 1; // Handle sign

        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i++] - '0';
            if ((total * 10 + digit) > INT_MAX) 
                return sign == 1 ? INT_MAX : INT_MIN; // Prevent overflow
            total = total * 10 + digit;
        }

        return sign * total;
    }
};
