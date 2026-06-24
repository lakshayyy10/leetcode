class Solution {
public:
/*
int t[46];
    int solve(int n){
        if(n<0) return 0;
        if(t[n]!=-1){
            return t[n];
        }
        if(n==0) return 1;
        int one  = solve(n-1);
        int two = solve(n-2);
        return t[n]=one+two;
    }
    */
    int climbStairs(int n) {
        /*
        memset(t,-1,sizeof(t));
        return solve(n);
        */
        //bottomup
        vector<int>t(n+1,0);
        if(n==1 || n==2 || n==3) return n;
        t[1]=1;
        t[2]=2;
        t[0]=0;
        for(int i=3;i<=n;i++){
            t[i]=t[i-1]+t[i-2];
        }
        return t[n];
    }
};