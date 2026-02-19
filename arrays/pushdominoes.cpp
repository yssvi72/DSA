#include <ranges>
class Solution {
public:
    /****
     Four cases to handle:
     1. L...L => all dominoes fall to the left
     2. R...L => forces meet in the middle (balance)
     3. R...R => all dominoes fall to the right
     4. L...R => no dominoes fall (forces cancel out before acting)
     ****/
    string pushDominoes(string dominoes) {
        // Treat the virtual left boundary as 'L' 
        // because it has no effect on any following dominoes
        bool lastL = true; // Initially simulate a virtual left boundary
        int lstIdx = -1;

        for (auto [i, d] : views::enumerate(dominoes)) {
            switch (d) {
                case 'L':
                    if (lastL) { // Case 1: L...L
                        for (int j = lstIdx + 1; j < i; ++j) dominoes[j] = 'L';
                    } else { // Case 2: R...L
                        int lpos = lstIdx + 1, rpos = i - 1;
                        for (;lpos < rpos; ++lpos, --rpos) {
                            dominoes[lpos] = 'R';
                            dominoes[rpos] = 'L';
                        }
                        // Middle domino (lpos == rpos, if any) stays upright
                    }
                    lastL = true;
                    lstIdx = i;
                    break;

                case 'R':
                    if (!lastL) { // Case 3: R...R
                        for (int j = lstIdx + 1; j < i; ++j) dominoes[j] = 'R';
                    }
                    lastL = false;
                    lstIdx = i;
                    break;

                default: // Case '.'
                    // Do nothing for now; the state depends on surrounding forces
                    break;
            }
        }

        // Handle any remaining dominoes after the last 'R' (e.g., R... end of string)
        if (!lastL) {
            for (int i = lstIdx + 1; i < dominoes.length(); ++i) dominoes[i] = 'R';
        }

        return dominoes;
    }
};
