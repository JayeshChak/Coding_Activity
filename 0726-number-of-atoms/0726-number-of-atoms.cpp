class Solution {
public:
    string countOfAtoms(string fr) {
        stack<string>st;
        for(int i = 0 ; i < fr.size() ;){
             if(fr[i]>64 && fr[i]<91){
                int j = i+1;
                while(j<fr.size() && fr[j]>96 && fr[j]<123) j++;
                st.push(fr.substr(i,j-i));
                i=j;
                if(j<fr.size() && fr[j]>47 && fr[j]<58) continue;
                else st.push("1");
             }
             else if(fr[i]>47 && fr[i]<58){
                int j = i+1;
                while(j<fr.size() && fr[j]>47 && fr[j]<58) j++;
                st.push(fr.substr(i,j-i));  
                i=j;              
             }
             else{
                string t = "";
                t += fr[i];
                st.push(t);
                i++;
                if(t ==")" && (i>=fr.size() || fr[i]<48 || fr[i]>57)) st.push("1"); 
             }
        }
        map<string,int> mp;
        vector<int>mult;
        mult.push_back(1);
        while(!st.empty()){
            string s = st.top();
            st.pop();
            // cout<<s<<"  ";
            // continue;
            if(s[0]>47 && s[0]<58){
               mult.push_back((stoi(s))*(mult[mult.size()-1]));
            }
            else if(s[0]>64 && s[0]<91){
                mp[s] += mult[mult.size()-1];
                mult.pop_back();
            }
            else if(s == "("){
                mult.pop_back();
            }

        }
        string ans = "";
        for(auto x : mp ){
            ans += (x.first);
            if(x.second != 1){
                ans+= to_string(x.second);
            }
        }
        return ans;
    }
};