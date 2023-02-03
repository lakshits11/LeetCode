class Solution:
    def longestDupSubstring(self, S: str) -> str:
        def rabin_karp(mid):
            h = 0
            for i in range(mid):
                h = (h * 26 + nums[i]) % mod
            s = {h}
            p = pow(26, mid, mod)
            for i in range(mid, len(S)):
                h = (h * 26 + nums[i] - nums[i - mid] * p) % mod
                if h in s:
                    return i - mid + 1
                s.add(h)
            return -1

        mod = 2**63 - 1
        nums = [ord(c) - ord('a') for c in S]
        left, right = 0, len(S)
        index = -1
        while left <= right:
            mid = (left + right) // 2
            pos = rabin_karp(mid)
            if pos != -1:
                left = mid + 1
                index = pos
            else:
                right = mid - 1
        return S[index:index + left - 1] if index != -1 else ""
