class Solution {
public:
    // Function to count the number of set bits (1s) in a number.
    int findsetbits(int number) { return __builtin_popcount(number); }
    int minimizeXor(int num1, int num2) {
        // If num1 and num2 already have the same number of set bits, return num1.
        if (findsetbits(num1) == findsetbits(num2)) return num1;
        int ans = num1;
        int n2setbits = findsetbits(num2); // setbits in num2
        int anssetbits = findsetbits(ans); // setbits in num1
        int currbit = 0;                 // start from lsb bit;

    // If num1 has fewer set bits than num2,we need to set more bits.
        while (anssetbits < n2setbits) {
            if (!(ans & (1 << currbit))) {  // if lsb bit is not set
                ans = ans | (1 << currbit); // set the bit
                anssetbits++;               // increment setbit count
            }
            currbit++; // move to next bit
        }

    // If num1 has more set bits than num2, we need to unset some bits.
        while (anssetbits > n2setbits) {
            if ((ans & (1 << currbit))) {    // if lsb bit is set
                ans = ans & ~(1 << currbit); // unset the bit
                anssetbits--;                // decrement setbit count
            }
            currbit++; // move to next bit
        }
        return ans;
    }
};
