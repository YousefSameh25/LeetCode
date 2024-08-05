class Solution {
public:
    map < int , string > mp1;
    map < string, int > mp2;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {

        int hash = rand();
        while(mp1.count(hash))
            hash = rand();
        
        mp1[hash] = longUrl;
        mp2[longUrl] = hash;
        return to_string(hash);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp1[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));