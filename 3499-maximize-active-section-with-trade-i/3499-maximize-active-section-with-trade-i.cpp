class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s=s+ '1';
        int flag=0;
        int flag2=0;
        int flag3=0;
        int c2=0;
        int c1=0;
        int maxi=0;
        int count=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i] =='1')count++;
            if(s[i]=='0'){
                if(flag2==0){
                c1++;
                flag=1;
                }
                else{
                    c2++;
                    flag3=1;
                 }
            }
            else if(s[i]=='1' && flag==1 ){ 
                flag2=1;
                if(flag3==1){
                maxi = max(maxi,c1+c2);
                c1=c2;
                c2=0;
                flag3=0;
                }
            }

        }
        
        return count+maxi-1;
    }
};