class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
       int n = positions.size();
    vector<tuple<int, int, char, int>> robots; // (position, health, direction, index)
    for (int i = 0; i < n; ++i) {
        robots.push_back(make_tuple(positions[i], healths[i], directions[i], i));
    }

    // Sort robots based on positions
    sort(robots.begin(), robots.end());

    stack<pair<int, int>> st; // stack to store (health, index) of 'R' robots
    vector<int> result(n, -1); // to store final healths in the order of input

    for (const auto& robot : robots) {
        int pos = get<0>(robot);
        int health = get<1>(robot);
        char direction = get<2>(robot);
        int index = get<3>(robot);

        if (direction == 'R') {
            st.push({health, index});
        }
        else {
            //for all collision of left moving robot with right moving robot
            while (!st.empty() && health > 0) {
                auto [rightHealth, rightIndex] = st.top();
                if (rightHealth > health) {
                    health = 0;
                    st.top().first--; // Decrease health of the right-moving robot
                } else if (rightHealth < health) {
                    health--;
                    st.pop();
                } else {
                    health = 0;
                    st.pop();
                }
            }
            if (health > 0) {
                result[index] = health;//putting robot's health at the same index where it was labeled
            }
        }
    }
    //putting all remaining right moving robots in result a their labeled position
    while (!st.empty()) {
        auto [rightHealth, rightIndex] = st.top();
        result[rightIndex] = rightHealth;
        st.pop();
    }

    // Remove -1 entries from result as they represent robots that didn't survive
    vector<int> survivors;
    for (int i = 0; i < n; ++i) {
        if (result[i] != -1) {
            survivors.push_back(result[i]);
        }
    }

    return survivors;
    
    }
};