class Solution {
private:
    vector<int> coins;
    vector<vector<int>> memoize;
    int n;
public:
    int coinChangeUtil(int idx, int currAmt){
        if(idx==n-1) return !(currAmt % coins[idx])? currAmt/coins[idx] : 1e9;
        if(memoize[idx][currAmt]!=-1) return memoize[idx][currAmt]; 

        int notTake = 0 + coinChangeUtil(idx+1, currAmt); 
        int take = INT_MAX; 
        if(coins[idx] <= currAmt) 
            take = 1 + coinChangeUtil(idx, currAmt-coins[idx]); 

        return memoize[idx][currAmt] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        n = coins.size();
        memoize = vector<vector<int>> (n+1, vector<int>(amount+1, -1));
        
        int res = coinChangeUtil(0, amount);
        return (res >= 1e9? -1 : res);
    }
};