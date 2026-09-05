class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int n = tickets.size();
        int Time = 0;
        // sare logo ko queue me dal do
        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        while (tickets[k] != 0) {

            int person = q.front();
            q.pop();

            // Person buys one ticket
            tickets[person]--;
            Time++;

            // If they still need tickets, go to the back
            if (tickets[person] > 0) {
                q.push(person);
            }
        }

        return Time;
    }
};