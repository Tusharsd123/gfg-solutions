o(n) - Hashmap

void findMajority(int arr[], int size) 
{ 
    unordered_map<int, int> m; 
    for(int i = 0; i < size; i++) 
        m[arr[i]]++; 
    int count = 0; 
    for(auto i : m) 
    { 
        if(i.second > size / 2) 
        { 
            count =1; 
            cout << "Majority found :- " << i.first<<endl; 
            break; 
        } 
    } 
    if(count == 0) 
        cout << "No Majority element" << endl; 
} 
