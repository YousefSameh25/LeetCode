class Solution {
public:
    int solve(int i, vector < vector < int >> &chunks, vector<int>& arr)
    {
        if (i == arr.size())
        {
            for (auto &chunk : chunks)
                sort(chunk.begin(), chunk.end());
            int idx = 0;
            bool valid = 1;
            for (auto &chunk : chunks)
            {
                for (auto &element : chunk)
                {
                    if (idx == element)
                        idx++;
                    else
                    {
                        valid = false;
                        break;
                    }
                }
            }
            return valid? chunks.size() : 1;
        }

        // Create New chunk
        chunks.push_back({arr[i]});
        int op1 = solve(i + 1, chunks, arr);

        // Revert the change
        chunks.pop_back();

        // If there is a size
        if (chunks.size())
            chunks[chunks.size() - 1].push_back(arr[i]);
        // Empty chunks
        else
            chunks.push_back({arr[i]});
            
        int op2 = solve(i + 1, chunks, arr);
        return max(op1, op2);
    }
    int maxChunksToSorted(vector<int>& arr) 
    {
        vector < vector < int >> chunks;
        return solve(0, chunks, arr);
    }
};