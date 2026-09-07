class Solution {
	public:
	void rearrangeQueue(queue<int> &q) {
		stack<int> st;
		int n = q.size();
		for (int i = 0; i<n/2; i++) {
			st.push(q.front());
			q.pop();
		}
		while (!st.empty()) {q.push(st.top());
		st.pop(); }
		
		for(int i=0; i<n/2; i++){
		    q.push(q.front());
		    q.pop();
		}
		for (int i = 0; i<n/2; i++) {
			st.push(q.front());
			q.pop();
		}
		while(!st.empty()){
		    q.push(st.top());
		    st.pop();
		    
		    q.push(q.front());
		    q.pop();
		}
	}
};
