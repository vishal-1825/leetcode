class NumberContainers {
public:
    unordered_map<int, int> container;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> indices;
    NumberContainers()
    {
    }
    
    void change(int index, int number) {
        container[index]=number;
        indices[number].push(index);
    }
    
    int find(int number) {
        while (!indices[number].empty())
        {
            int index=indices[number].top();
            if (container.find(index)!=container.end() && container[index]==number) return index;
            indices[number].pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */