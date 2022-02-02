class Solution {
public:
    bool winnerOfGame(string colors) {
         int a=0,b=0;
        int c=0;
        for(int i=1;i<colors.size()-1;i++){
            if(colors[i-1]==colors[i] && colors[i]==colors[i+1])c++;
            else{
                if(c==0) continue;
                if(colors[i]=='A')a+=c;
                else b+=c;
                c=0;
            }
        }
        if(c!=0){
            if(colors[colors.size()-1]=='A')a+=c;
            else b+=c;
        }
        return a>b;
        
    }
};