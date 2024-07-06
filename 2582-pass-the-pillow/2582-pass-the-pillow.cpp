class Solution {
public:
    int passThePillow(int n, int time) {
        int position = 1; // Initial position
        
        // Determine the direction and position after each second
        bool forward = true; // Indicates the direction of the pass
        
        for (int i = 0; i < time; ++i) {
            if (forward) {
                if (position < n) {
                    position++;
                } else {
                    forward = false;
                    position--;
                }
            } else {
                if (position > 1) {
                    position--;
                } else {
                    forward = true;
                    position++;
                }
            }
        }
        
        return position;
    }
};
