class Solution {
public:
    int strStr(string haystack, string needle) {
       int s1 = haystack.length();
       int s2 = needle.length();
       for (int i = 0; i <= s1 - s2; i++) {
           if (haystack[i] == needle[0]) {
               int j;
               for (j = 0; j < s2; j++) {
                   if (haystack[i + j] != needle[j])
                       break;
               }
               if (j == s2)
                   return i;
           }
       }
       return -1;
    }
};