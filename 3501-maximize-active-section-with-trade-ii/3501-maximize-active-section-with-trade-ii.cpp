
class Solution {
public:
    vector<int>tree;
    void build(int node,int l,int r,vector<int>&gap){
        if(l==r){
            tree[node]=gap[l];
            return;
        }
        int m=(l+r)/2;
        build(2*node,l,m,gap);
        build(2*node+1,m+1,r,gap);
        tree[node]=max(tree[2*node],tree[2*node+1]);
    }

    int query(int node,int l,int r,int ql,int qr){
        if(l>qr || r<ql) return 0;
        if(ql<=l && r<=qr) return tree[node];
        int m=(l+r)/2;
        return max(query(2*node,l,m,ql,qr),
                   query(2*node+1,m+1,r,ql,qr));
    }

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n=s.size();
        int cnt=count(s.begin(),s.end(),'1');
        vector<int>gap,start0,end0;
        for(int i=0;i<n;){
            int j=i;
            while(j<n && s[j]==s[i]) j++;
            if(s[i]=='0'){
                gap.push_back(j-i);
                start0.push_back(i);
                end0.push_back(j-1);
            }
            i=j;
        }

        int o=gap.size();

        vector<int>v;

        for(int i=0;i+1<o;i++){
            v.push_back(gap[i]+gap[i+1]);
        }

        tree.assign(4*max(1,(int)v.size()),0);

        if(v.size()) build(1,0,v.size()-1,v);

        vector<int>ans;
        for(auto q:queries){
            int l=q[0],r=q[1];
            int idx1=lower_bound(end0.begin(),end0.end(),l)-end0.begin();
            int idx2=upper_bound(start0.begin(),start0.end(),r)-start0.begin()-1;
            if(idx1>=o || idx2<0 || idx1>=idx2){
                ans.push_back(cnt);
                continue;
            }
            int a=end0[idx1]-max(l,start0[idx1])+1;
            int b=min(r,end0[idx2])-start0[idx2]+1;
            int best=0;
            if(idx1+1==idx2)
                best=a+b;
            else{
                best=max(a+gap[idx1+1],gap[idx2-1]+b);
                best=max(best,query(1,0,v.size()-1,idx1+1,idx2-2));
            }
            ans.push_back(cnt+best);
        }
        return ans;
    }
};