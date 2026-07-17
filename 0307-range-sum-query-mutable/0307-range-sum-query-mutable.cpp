class NumArray {
public:
    vector<int> nums;
    int n;
    vector<int>tree;


    void build(int node,int left,int right){
        if(left == right){
            tree[node] = nums[left];
            return;
        }
        int mid = (left + right)/2;
        build(2*node,left,mid);
        build(2*node + 1,mid + 1,right);
        tree[node] = tree[2*node] + tree[2*node + 1];
    }

   void up(int index , int val,int node,int left,int right){

    if(left == right){
        nums[index] = val;
        tree[node] = val;
        return;
    }

    int mid = (left + right)/2;

    if(index <= mid)
    {
        up(index,val,2*node,left,mid);
    }
    else
    {
        up(index,val,2*node+1,mid+1,right);
    }

    tree[node] = tree[2*node] + tree[2*node+1];
}

   int query(int node, int start, int end, int l, int r) {

    if (r < start || end < l)
        return 0;

    if (l <= start && end <= r)
        return tree[node];

    int mid = (start + end) / 2;

    int left = query(2 * node, start, mid, l, r);
    int right = query(2 * node + 1, mid + 1, end, l, r);

    return left + right;
   }


    NumArray(vector<int>& nums) {
      this->nums = nums;
      n = nums.size();
      tree.resize(4*n);
      build(1,0,n-1);
    }

    

    void update(int index, int val) {
        up(index,val,1,0,n-1);
    }
    
    int sumRange(int left, int right) {
         return query(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */