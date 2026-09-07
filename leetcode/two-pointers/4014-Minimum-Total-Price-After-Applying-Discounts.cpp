class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        int i=prices.size()-1;
        int j=discounts.size()-1;
        double res=0;
        while(i>=0 && j>=0){
            int rem=100-discounts[j];
            double cur=(prices[i]*rem)/100.00;
            res+=cur;
            i--; j--;
        }
        while(i>=0){
            res+=prices[i];
            i--;
        }
        return res;
    }
};