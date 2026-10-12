class BusBooking {
public:

    int cnt = 0;
    vector<vector<int>>bus;
    vector<vector<int>>cost;
    vector<vector<int>>temp;
    int ans = 0;
    BusBooking(int n) {
        bus.resize(n+1,vector<int>(4,0));
        cost.resize(n+1,vector<int>(4,0));
        temp.resize(n+1,vector<int>(4,0));
        cnt = 0;
        ans = 0;
    }
    
    void toggle(string seat) {
        int col = seat[0] - 'A';
        string tep = seat.substr(1);
        int row = stoi(tep);
        
             if(!cost[row][col]){
                 ans++;
                 cost[row][col] = 1;
             }
            else{
                ans--;
                cost[row][col] = 0;
            }
        
        if(!bus[row][col]){
        if(col == 1 || col == 2){
             temp[row][col] = 1;
            cnt++;
        }
        else{
            if((col == 0 && bus[row][1] == 1) || (col == 3 && bus[row][2] == 1)){
                cnt += 3;
                temp[row][col] = 3;
            }
            else{
                cnt++;
                temp[row][col] = 1;
            }
        }
        }
        else{
            cnt -= temp[row][col];
        }
        bus[row][col] = !bus[row][col];
       
    }
    
    int getTotalTime() {
        return cnt;
    }
    
    int getMinTime() {
        return ans;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */