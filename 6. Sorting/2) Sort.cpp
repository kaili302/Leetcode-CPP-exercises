#include <ctime>
#include <algorithm>
#include <random>
class Sort {
public:
    void mergeSort (std::vector<int> &nums) {
        std::vector<int> numsHelper;
        numsHelper.assign(nums.size(), 0);
        mergeSort(nums, numsHelper, 0, nums.size()-1);
    }

    void selectSort (std::vector<int> &nums) {
        for (int i=0; i<nums.size(); i++) {
            int min = i;
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[j] < nums[min]) min = j;
            }
            std::swap(nums[i], nums[min]);
        }
    }

    void quickSort(std::vector<int> &nums){
        shuffle(nums);
        quickSort(nums, 0, nums.size()-1);
    }

    void shuffle(std::vector<int> &nums) {
        for (int i=1; i<nums.size(); i++) {
            // Seed with a real random value, if available
            std::random_device r;
            // Choose a random mean between 1 and 6
            std::default_random_engine e1(r());
            std::uniform_int_distribution<int> uniform_dist(0, i);
            int j = uniform_dist(e1);
            std::swap(nums[i], nums[j]);
        }
    }

    void initArray(std::vector<int> &nums, int n) {
        nums.reserve(n);
        for (int i=1; i<=n; i++){
            nums.push_back(i%31);
        }
    }

    bool isSorted(std::vector<int> &nums) {
        for (int i=1; i<nums.size(); i++){
            if (nums[i]<nums[i-1]) {
                std::cout << "unsorted\n";
                return false;
            }            
        }
        std::cout << "sorted\n";
        return true;
    }

    void print(std::vector<int> &nums) {
        for (int &num : nums) std::cout << num << " ";
        std::cout <<std::endl;
    }

private:
    void quickSort(std::vector<int> &nums, int lo, int hi){
        if (lo >= hi) return;
        int pivot = partition(nums, lo, hi);
        quickSort(nums, lo, pivot - 1);
        quickSort(nums, pivot+1, hi);
    }

    int partition(std::vector<int> &nums, int lo, int hi){
        int i = lo;
        int j = hi+1;
        while (true) {
            while (nums[++i] < nums[lo]) {
                if (i == hi) break;
            }
            while (nums[--j] > nums[lo]) {
                if (j == lo) break;
            }
            if (j <= i) break;
            else std::swap(nums[i], nums[j]);
        }
        std::swap(nums[lo], nums[j]);
        return j;
    }

    void mergeSort (std::vector<int> &nums, std::vector<int> &numsHelper, int lo, int hi) {
        if (lo >= hi) return;
        int mid = (lo + hi)/2;
        mergeSort(nums, numsHelper, lo, mid);
        mergeSort(nums, numsHelper, mid+1, hi);
        merge(nums, numsHelper, lo, mid, hi);
    }

    void merge (std::vector<int> &nums, std::vector<int> &numsHelper, int lo, int mid, int hi) {
        for (int k=lo; k<=hi; k++) numsHelper[k] = nums[k]; 
        int i = lo;
        int j = mid+1;
        for (int k=lo; k<=hi; k++) {
            if (i>mid) nums[k] = numsHelper[j++];
            else if (j>hi) nums[k] = numsHelper[i++];
            else if (numsHelper[i] < numsHelper[j]) nums[k] = numsHelper[i++];
            else nums[k] = numsHelper[j++];
        }
    }
};






class MinHeap{
private:
	int *m_pHeap;
	int m_end;
	int m_capacity;

	void sink(int k) {
		if (isEmpty()) return ;
		int j = k*2;
		while (j <= m_end && m_pHeap[k] > m_pHeap[j]) {
			if (j<m_end && m_pHeap[j+1] < m_pHeap[j]) j++;
			std::swap(m_pHeap[j], m_pHeap[k]);
			k = j;
			j = 2*k;
		}
	}

	void swim(int k) {
		if (isEmpty()) return ;
		int j = k/2;
		while (j>=1 && m_pHeap[j] > m_pHeap[k]) {
			std::swap(m_pHeap[j], m_pHeap[k]);
			k = j;
			j = k/2;
		}
	}

public:
	MinHeap(int capacity): m_end{0}, m_capacity{capacity}, m_pHeap{new int[capacity+1]}
	{}
	~MinHeap(){
		delete[] m_pHeap;
	}

	void push(int val) {
		if (isFull()) {
			m_pHeap[1] = val;
			sink(1);
		}else {
			m_pHeap[++m_end] = val;
			swim(m_end);
		}
	}

	int& top(){
		return m_pHeap[1];
	}

	void pop() {
		if (isEmpty()) return;
		std::swap(m_pHeap[1], m_pHeap[m_end--]);
		sink(1);
	}

	bool isEmpty() { return m_end == 0; }

	bool size() { return m_end; }

	bool isFull() { return m_end == m_capacity; }
};


























