class StockSpanner {
public:
    stack<pair<int,int>> st; // {price, span}

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;

        // sare smaller and equal price hata denge
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // current price with their span
        st.push({price, span});

        return span;
    }
};