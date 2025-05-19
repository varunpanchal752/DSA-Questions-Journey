// Iterative
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long total = 0; // Using long to handle overflow safely

        while (i < s.size() && s[i] == ' ') i++;  // Skip leading spaces
        if (s[i] == '-' || s[i] == '+') sign = (s[i++] == '-') ? -1 : 1; // Handle sign

        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i++] - '0';
            if (total > (INT_MAX - digit) / 10) 
                return sign == 1 ? INT_MAX : INT_MIN; // Prevent overflow
            total = total * 10 + digit;
        }

        return sign * total;
    }
};


// Recursive 
class Solution {
public:
    int helper(string &s, int i, int sign, long total) {
        // Base case: end of string or non-digit
        if (i >= s.size() || !isdigit(s[i])) {
            return sign * total;
        }

        int digit = s[i] - '0';

        // Check for overflow before it happens
        if (total > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        // Accumulate digit
        total = total * 10 + digit;

        return helper(s, i + 1, sign, total);
    }
    
    int myAtoi(string s) {
        int i = 0, sign = 1;

        while (i < s.size() && s[i] == ' ') i++;  // Skip leading spaces

        if (s[i] == '-' || s[i] == '+') sign = (s[i++] == '-') ? -1 : 1; // Handle sign

        while (i < s.size() && s[i] == '0') i++;

        return helper(s, i, sign, 0);
    }
};

