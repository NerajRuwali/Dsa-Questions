class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map <int ,int > mpp;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < fruits.size(); right ++){

            mpp[fruits[right]]++;
        
        while(mpp.size()>2){

            mpp[fruits[left]]--;

            if(mpp[fruits[left]]== 0){
               mpp.erase(fruits[left]);
            }
            left++;
        }
        ans = max(ans , right - left +1);

       


        }
        return ans;
        
    }
};