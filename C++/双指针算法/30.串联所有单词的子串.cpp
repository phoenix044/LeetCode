/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode.cn/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (37.13%)
 * Likes:    667
 * Dislikes: 0
 * Total Accepted:    109.7K
 * Total Submissions: 295.1K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些 长度相同 的单词 words 。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "barfoothefoobarman", words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * 输出：[6,9,12]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由小写英文字母组成
 * 1 
 * 1 
 * words[i] 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        vector<int> res;

        int one_word = words[0].size();
        int word_num = words.size();
        int all_len = one_word * word_num;

        unordered_map<string, int> m1;
        for (const auto & w:words) m1[w] ++;

        for (int i = 0; i < one_word; i ++){
            int left = i, right = i, count = 0;
            unordered_map<string, int> m2;

            while(right + one_word <= s.size()){
                string w = s.substr(right, one_word);
                right += one_word;

                if (m1.count(w) == 0){
                    count = 0;
                    left = right;
                    m2.clear();
                } else {
                    m2[w] ++;
                    count ++;
                    while(m2.at(w) > m1.at(w)){
                        string t_w = s.substr(left, one_word);
                        count --;
                        m2[t_w] --;
                        left += one_word;
                    }
                    if (count == word_num) res.push_back(left);
                }
            }
        }
        return res;
    }
};
// @lc code=end

