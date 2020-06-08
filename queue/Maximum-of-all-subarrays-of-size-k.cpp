//using deque to pop elements from front and the back.
//T.C - o(n)

void maxOfSubArray(int a[], int n, int k){
    int i;
    deque<int>q;
    for(i=0; i<k; i++){
        while(!q.empty() && a[i]>=a[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    cout << a[q.front()] <<' ';
    for(; i<n; i++){
        
        while(!q.empty() && q.front()<= i-k)
            q.pop_front();
        while(!q.empty() && a[i]>=a[q.back()])
            q.pop_back();
        q.push_back(i);
        cout << a[q.front()] <<' ';
    }
    cout << endl;
}
