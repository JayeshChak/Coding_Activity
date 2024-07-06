class Solution {
public:
    int passThePillow(int n, int time) {
        int position = 1; 
        bool forward = true; 
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
