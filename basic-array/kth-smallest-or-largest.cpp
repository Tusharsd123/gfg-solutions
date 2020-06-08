//kth largest or smaller element can be calculated using heaps
//min heap - priority_queue<int,vector<int>,greater<int>> pq;
//max heap- priority_queue<int> pq;

int findKthLargest(vector<int>& nums, int k) {
         priority_queue<int> pq;
        
        // O(N) -------------------------> Time complexity to create this heap is O(N).
        for(int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
        
        // O(klog N) --------------> The time complexity to delete each maximum element is log N and here we are doing it k - 1 times so complexity is around O(klog N).
        for(int i = 0; i < k - 1; i++)
        {
            pq.pop();
        }
        
        // O(1)  -----------------------> This is a constant time operation to just get the top element in the heap.
        return pq.top();
    }
        
