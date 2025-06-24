class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                // Asteroid moving left, handle collisions
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                    st.pop(); // smaller right-moving asteroid explodes
                }

                if (!st.empty() && st.top() == abs(asteroids[i])) {
                    st.pop(); // both equal, both explode
                } 
                else if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]); // left-moving survives
                }
                // else: larger right-moving survives, do nothing
            }
        }

        // Convert stack to vector (in correct order)
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
