//NEEDS FIXING!!!!!


class MedianFinder {
public:

    //keep 2 heaps that differ in size by at most 1

    vector<int> maxHeap;
    vector<int> minHeap;
    
    int minSize = 0, maxSize = 0;
    
    //greater is +1 if maxHeap is bigger in size else if they ar equal, it will be 0 else -1
    int greater = 0;
    
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void maxHeapify(vector<int> maxHeap)
    {
        int len = maxHeap.size();
        
        int i = len - 1;
        int parent;
        
        //cout<<"maxHeapify"<<endl;
        
        while(i > 0)
        {
            parent = (i + 1)/2 - 1;
            //cout<<maxHeap[parent]<<" "<<maxHeap[i]<<endl;
            if(maxHeap[parent] < maxHeap[i])
            {
                cout<<"swapped"<<endl;
                swap(&maxHeap[parent], &maxHeap[i]);
                i = parent;
            }
            else
                break;
        }
    }
    
    void maxHeapifyFromTop(vector<int> maxHeap)
    {
        int len = maxHeap.size();
        
        int i = 0;
        int lchild, rchild, great;
        
        while(((i + 1)*2 - 1) < len)
        {
            lchild = (i + 1)*2 - 1;
            rchild = lchild + 1; //check it has not reached the end of the vector
            
            if(rchild < len)
            {
                if(maxHeap[lchild] > maxHeap[rchild])
                {
                    great = lchild;
                }
                else
                    great = rchild;
            }
            else
                great = lchild;
            
            if(maxHeap[great] > maxHeap[i])
            {
                swap(&maxHeap[great], &maxHeap[i]);
                i = great;
            }
            else
                break;
        }
    }
    
    
    void minHeapify(vector<int> minHeap)
    {
        int len = minHeap.size();
        
        int i = len - 1;
        int parent;
        
        while(i > 0)
        {
            parent = (i + 1)/2 - 1;
            if(minHeap[parent] > minHeap[i])
            {
                swap(&minHeap[parent], &minHeap[i]);
                i = parent;
            }
            else
                break;
        }
    }
    
    void minHeapifyFromTop(vector<int> minHeap)
    {
        int len = minHeap.size();
        
        int i = 0;
        int lchild, rchild, smaller;
        
        while(((i + 1)*2 - 1) < len)
        {
            lchild = (i + 1)*2 - 1;
            rchild = lchild + 1; //check it has not reached the end of the vector
            
            if(rchild < len)
            {
                if(minHeap[lchild] > minHeap[rchild])
                {
                    smaller = rchild;
                }
                else
                    smaller = lchild;
            }
            else
                smaller = lchild;
            
            if(minHeap[smaller] < minHeap[i])
            {
                swap(&minHeap[smaller], &minHeap[i]);
                i = smaller;
            }
            else
                break;
        }
        
    }

    // Adds a number into the data structure.
    void addNum(int num) {
        if(maxSize == 0 && minSize == 0)
        {
            //very first element
            maxHeap.push_back(num);
            greater = 1;
            maxSize++;
        }
        else if(maxSize == 0)
        {
            //this can never happen since the very first element is always inserted in maxHeap
            cout<<"WTF!!"<<endl;
            //throw an error
        }
        else if(minSize == 0)
        {
            //called when the second element is being inserted
            //maxHeap already has one element
            if(maxHeap[0] > num)
            {
                int temp;
                temp = maxHeap[0];
                maxHeap[0] = num;
                minHeap.push_back(temp);
            }
            else
            {
                minHeap.push_back(num);
            }

            greater = 0;
            minSize++;
        }
        else
        {
            if(maxHeap[0] == num && greater != 0)
            {
                //put in the heap which has a smaller size
                if(greater > 0)
                {
                    //put in minHeap
                    minHeap.push_back(num);
                    minHeapify(minHeap);
                    minSize++;
                }
                else
                {
                    //put in maxHeap
                    maxHeap.push_back(num);
                    maxHeapify(maxHeap);
                    maxSize++;
                }
                
                greater = 0;
            }
            else if(maxHeap[0] == num) //&& greater == 0
            {
                //num belongs in maxHeap
                maxHeap.push_back(num);
                maxHeapify(maxHeap);
                maxSize++;
                greater = 1;
            }
            else if(maxHeap[0] > num)
            {
                if(greater > 0)
                {
                    //maxHeap already has one element more than minHeap
                    //remove maxHeap[0] and put in minHeap
                    //add num to maxHeap
                    minHeap.push_back(maxHeap[0]);
                    minHeapify(minHeap);
                    minSize++;
                    maxHeap[0] = num;
                    maxHeapifyFromTop(maxHeap);
                    greater = 0;
                }
                else
                {
                    //add number to maxHeap;
                    maxHeap.push_back(num);
                    maxHeapify(maxHeap);
                    maxSize++;
                    if(maxSize > minSize)
                        greater = 1;
                    else
                        greater = 0;
                }
            }
            else
            {
                //num belongs in minHeap
                if(greater < 0)
                {
                    //minHeap already has one element more than maxHeap
                    //remove minHeap[0] and put in maxHeap
                    //add num to minHeap
                    maxHeap.push_back(minHeap[0]);
                    maxHeapify(maxHeap);
                    maxSize++;
                    minHeap[0] = num;
                    minHeapifyFromTop(minHeap);
                    greater = 0;
                }
                else
                {
                    //add number to minHeap;
                    minHeap.push_back(num);
                    minHeapify(minHeap);
                    minSize++;
                    if(maxSize < minSize)
                        greater = -1;
                    else
                        greater = 0;
                }
                
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        
        if(minSize == 0 && maxSize == 0)
            return 0;
            
        if(minSize == 0)
            return maxHeap[0];
        else if (maxSize == 0)
        {
            return minHeap[0];
        }
        else
        {
            
            cout<<minSize<<" "<<maxSize<<" "<<greater<<endl;
            
            if(greater == 0)
            {
                cout<<minHeap[0]<<" "<<maxHeap[0]<<endl;
                return (minHeap[0] + maxHeap[0])/2.0;
            }
            else if(greater == 1)
            {
                return maxHeap[0];
            }
            else if(greater == -1)
            {
                return minHeap[0];
            }
            else
            {
                cout<<"Something went wrong"<<endl;
                return -1;
            }
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
