# sha256_bruteforce.py
# 逆向工程 SHA256 爆破通用模板
# 直接改 target_hash、charset、min_len、max_len 即可

import hashlib
import itertools
import string


# =========================
# 这里改参数
# =========================

# 程序里提取到的 SHA256 目标值
target_hash = "10e8c22df32a570db8fab6efbb0b7432f8f807df96cc4b3cc661f95811457fa1"

# 爆破长度范围
min_len = 4
max_len = 4

# 字符集：根据题目情况修改
#charset = string.ascii_lowercase
# charset = string.ascii_letters + string.digits
charset = string.ascii_letters + string.digits + "_{}-@!"
# charset = "0123456789abcdef"
# charset = "abcdefghijklmnopqrstuvwxyz0123456789_{}"


# 如果已知前缀或后缀，可以写这里
known_prefix = ""
known_suffix = ""


# =========================
# SHA256 计算函数
# =========================

def sha256_hex(s: str) -> str:
    return hashlib.sha256(s.encode()).hexdigest()


# =========================
# 爆破部分
# =========================

def brute_force():
    for length in range(min_len, max_len + 1):
        print(f"[*] 正在爆破长度: {length}")

        for chars in itertools.product(charset, repeat=length):
            mid = "".join(chars)
            candidate = known_prefix + mid + known_suffix

            h = sha256_hex(candidate)

            if h.lower() == target_hash.lower():
                print("[+] 找到结果!")
                print("[+] plaintext:", candidate)
                print("[+] sha256:", h)
                return candidate

    print("[-] 没找到，尝试扩大长度或字符集")
    return None


if __name__ == "__main__":
    brute_force()