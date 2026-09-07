class myStack {
	queue<int> q;
	
	public:
	void push(int x) {
		q.push(x);
		
		int sz = q.size();
		
		for (int i = 0; i < sz - 1; i++) {
			q.push(q.front());
			q.pop();
		}
	}
	void pop() {
		if (!q.empty())
			q.pop();
	}
	
	int top() {
		if (q.empty()) {
			return - 1;
		}
		return q.front();
	}
	
	int size() {
		return q.size();
	}
};
