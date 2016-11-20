template<class T, class smaller=less<T>>
class MinHeap{
private:
    vector<T> nums;
    int size = 0;

    void sink(int k){
        int j = k * 2; // idx starts from 1
        while (j <= size && smaller()(nums[j], nums[k])){
            if (j < size && smaller()(nums[j+1], nums[j])) j++;
            swap(nums[k], nums[j]);
            k = j; j = k * 2;
        }
    }

    void promot(int k){
        int j = k / 2;
        while (j >= 1 && smaller()(nums[k], nums[j])){
            swap(nums[j], nums[k]);
            k = j; j = k / 2;
        }
    }
public:
    MinHeap(){ }
    void push(const T& t){
        if (empty()) nums.push_back(t);
        nums.push_back(t);
        size++;
        promot(size);
    }

    void pop(){
        if (!size) return;
        swap(nums[1], nums[size--]);
        sink(1);
    }

    int empty(){ return size == 0; }
    
    T& top(){ return nums[1]; }
};

struct cmp
{
    bool operator()(const int& n1, const int& n2) const{
        return n1 < n2;
    }
};

int main(){
    MinHeap<int> minHeap;
    minHeap.push(23);
    minHeap.push(2);
    minHeap.push(33);
    minHeap.push(3);
    minHeap.push(13);
    while (!minHeap.empty()){
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}