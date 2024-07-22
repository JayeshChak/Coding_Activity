class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> people;
        for (int i = 0; i < names.size(); ++i) {
            people.push_back({heights[i], names[i]});
        }
        // Sort by height in descending order
        sort(people.begin(), people.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first;
        });

        vector<string> ans;
        for (const auto& person : people) {
            ans.push_back(person.second);
        }

        return ans;
    }
};
