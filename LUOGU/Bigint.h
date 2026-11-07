#ifndef BIGINT
#define BIGINT

#include <string>
#include <vector>
#include <algorithm>

inline std::string big_add(std::string a, std::string b) {
    std::string res;
    int i = a.size() - 1, j = b.size() - 1, c = 0;
    while (i >= 0 || j >= 0 || c) {
        int sum = (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0) + c;
        res.push_back(sum % 10 + '0');
        c = sum / 10;
    }
    std::reverse(res.begin(), res.end());
    return res.empty() ? "0" : res;
}

inline std::string big_max(const std::string &a, const std::string &b) {
    if (a.length() != b.length()) return a.length() > b.length() ? a : b;
    return a > b ? a : b; // String comparison works if lengths are equal
}

// 大数乘法：处理两个非负整数字符串的乘法
inline std::string big_mult(const std::string &a, const std::string &b) {
    if (a == "0" || b == "0")
        return "0";
    
    std::vector<int> temp(a.size() + b.size(), 0);
    
    // 直接从低位开始计算，避免反转字符串
    for (int i = a.size() - 1; i >= 0; --i) {
        int digit_a = a[i] - '0';
        for (int j = b.size() - 1; j >= 0; --j) {
            int digit_b = b[j] - '0';
            int product = digit_a * digit_b;
            int pos = i + j + 1; // 结果的低位位置
            
            temp[pos] += product;
            temp[pos - 1] += temp[pos] / 10; // 进位到高位
            temp[pos] %= 10;
        }
    }
    
    // 转换为字符串，跳过前导零
    std::string res;
    size_t start = 0;
    while (start < temp.size() && temp[start] == 0)
        start++;
    
    for (size_t k = start; k < temp.size(); ++k)
        res.push_back(temp[k] + '0');
    
    return res.empty() ? "0" : res;
}
#endif
