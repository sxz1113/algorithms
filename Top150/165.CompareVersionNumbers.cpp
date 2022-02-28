#include "../Common.h"


class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size(), n = version2.size();
        int i = 0, j = 0;
        int revision1, revision2;
        while (i < m || j < n) {
            revision1 = getRevision(version1, i);
            revision2 = getRevision(version2, j);

            printf("revision1 %d -- revision2 %d\n", revision1, revision2);

            if (revision1 < revision2) {
                return -1;
            } else if (revision1 > revision2) {
                return 1;
            } else {
                
            }
        }

        return 0;
    }

private:
    int getRevision(const string& version, int& ptr) {
        int revision = 0;
        while (ptr < version.size() && version[ptr] != '.') {
            revision = revision * 10 + version[ptr++] - '0';
        }
        ++ptr;
        return revision;
    }
};