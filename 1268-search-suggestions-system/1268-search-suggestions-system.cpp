class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>ans;
        int k = searchWord.size();
        string temp = "";
        for(int i=0;i<k;i++){
            temp += searchWord[i];
            vector<string>raj;
            string j = temp;
            for(int a=i+1;a<k;a++){
                j += 'a';
            }
            auto it = lower_bound(products.begin(),products.end(),temp);
            if(it == products.end()) ans.push_back(raj);
            else{
                int cnt = 0;
                int idx = it - products.begin();
                 int h = temp.size();
                 bool flag = false;
                while(cnt < 3 && idx < products.size()){
                    int p = 0;
                    string str = products[idx];
                    for(int l =0;l<h;l++){
                        if(str[l] != temp[l]){
                            flag = true;
                            break;
                        }
                    } 
                    if(flag) break;
                    raj.push_back(str);
                    idx++;
                    cnt++;
                }
                ans.push_back(raj);
            }
        }
        return ans;
    }
};