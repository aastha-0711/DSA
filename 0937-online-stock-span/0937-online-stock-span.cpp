class StockSpanner {
    vector<int> prices;
    stack<int> st;
public:
    StockSpanner() {}

    int next(int price) {
        int idx = prices.size();
        prices.push_back(price);

        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }

        int span = st.empty() ? idx + 1 : idx - st.top();
        st.push(idx);
        return span;
    }
};