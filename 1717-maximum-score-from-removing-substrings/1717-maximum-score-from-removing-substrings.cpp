class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int a =0;
        int b = 0;
        int ans = 0;
        for(char ch : s)
        {
          if(ch == 'a')
          {
            if(y>x)
            {
                if(b>0){
                    ans+=y;
                    b--;
                }
                else a++;
            }
            else
            a++;
          }
          else if(ch == 'b'){
           if(x>y)
            {
                if(a>0){
                    ans+=x;
                    a--;
                }
                else b++;
            }
            else
            b++;
          }
          else{
            if(x>y)
            {
               while(a>0 && b>0){ans+=y;a--;b--;}
               a = 0;
               b = 0;
            }
            else{
               while(a>0 && b>0){ans+=x;a--;b--;}
               a = 0;
               b = 0;
            }
          }
        }
        if(x>y)
            {
               while(a>0 && b>0){ans+=y;a--;b--;}
               a = 0;
               b = 0;
            }
            else{
               while(a>0 && b>0){ans+=x;a--;b--;}
               a = 0;
               b = 0;
            }

        return ans;

    }
};