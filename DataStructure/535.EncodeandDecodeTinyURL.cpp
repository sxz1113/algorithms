#include "../Common.h"


class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl;
        // 现有字典里没有这个long url，去生成
        if (long2short.find(longUrl) == long2short.end()) {
            for (int i = 0; i < 6; ++i)
                shortUrl += dict[rand() % dict.size()];
            long2short[longUrl] = shortUrl;
            short2long[shortUrl] = longUrl;
        } else {
            shortUrl = long2short[longUrl];
        }

        // cout << shortUrl << endl;
        return host + shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string longUrl {};
        // cout << shortUrl.substr(host.size(), 6) << endl;
        if (shortUrl.size() != host.size() + 6 || 
            short2long.find(shortUrl.substr(host.size(), 6)) == short2long.end())
                return longUrl;
        return short2long[shortUrl.substr(host.size(), 6)];
    }

private:
    const string dict="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    const string host="http://tinyurl.com/";
    unordered_map<string, string> long2short, short2long;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));