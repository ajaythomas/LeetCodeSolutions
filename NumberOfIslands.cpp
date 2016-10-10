class Queue
{
public:
    pair<int, int> a;
    Queue* next;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int i, j, count = 0, m, n;
        
        m = grid.size(); //no. of rows
        
        if(m == 0)
            return 0;
        
        n = grid[0].size(); //no. of columns
        
        if(n == 0)
            return 0;
        
        set<pair<int, int>> ones;
        pair<int,int> one;
        
        //add all the 1s to a set
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    one = std::make_pair(i,j);
                    ones.insert(one);
                }
                
            }
        }
        
        if(ones.size() == 0)
            return 0;
        
        Queue* head = NULL;
        Queue* node = NULL;
        Queue* curr = NULL;
        Queue* temp = NULL;
        
        int xCoord, yCoord;
        pair<int, int> adj;
        
        while(ones.size() != 0)
        {
            auto it = ones.begin();
            count++;
            
            node = new Queue();
            pair<int, int> charlie(*it);
            node->a = std::make_pair(charlie.first, charlie.second);
            node->next = NULL;
            head = node;
            curr = node;
            
            ones.erase(it);
            
            while(head != NULL)
            {
                xCoord = head->a.first - 1;
                yCoord = head->a.second;
                
                if(xCoord > -1)
                {
                    adj = std::make_pair(xCoord, yCoord);
                    auto iter = ones.find(adj);
                    if(iter != ones.end())
                    {
                        node = new Queue();
                        pair<int, int> charlie1(*iter);
                        node->a = std::make_pair(charlie1.first, charlie1.second);
                        node->next = NULL;
                        curr->next = node;
                        curr = node;
                        ones.erase(iter);
                    }
                }
                
                xCoord = head->a.first + 1;
                yCoord = head->a.second;
                
                if(xCoord < m)
                {
                    adj = std::make_pair(xCoord, yCoord);
                    auto iter = ones.find(adj);
                    if(iter != ones.end())
                    {
                        node = new Queue();
                        pair<int, int> charlie1(*iter);
                        node->a = std::make_pair(charlie1.first, charlie1.second);
                        node->next = NULL;
                        curr->next = node;
                        curr = node;
                        ones.erase(iter);
                    }
                }
                
                xCoord = head->a.first;
                yCoord = head->a.second - 1;
                
                if(yCoord > -1)
                {
                    adj = std::make_pair(xCoord, yCoord);
                    auto iter = ones.find(adj);
                    if(iter != ones.end())
                    {
                        node = new Queue();
                        pair<int, int> charlie1(*iter);
                        node->a = std::make_pair(charlie1.first, charlie1.second);
                        node->next = NULL;
                        curr->next = node;
                        curr = node;
                        ones.erase(iter);
                    }
                }
                
                xCoord = head->a.first;
                yCoord = head->a.second + 1;
                
                if(yCoord < n)
                {
                    adj = std::make_pair(xCoord, yCoord);
                    auto iter = ones.find(adj);
                    if(iter != ones.end())
                    {
                        node = new Queue();
                        pair<int, int> charlie1(*iter);
                        node->a = std::make_pair(charlie1.first, charlie1.second);
                        node->next = NULL;
                        curr->next = node;
                        curr = node;
                        ones.erase(iter);
                    }
                }
                
                temp = head;
                head = head->next;
                
                
                delete temp;
            }
            
            head = node = curr = temp = NULL;
            
        }
        
        return count;
        
    }
};
