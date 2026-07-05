import hashlib
import itertools  # 用这个库暴力循环更快更干净

# 密码字典：大写 + 小写
dic = "QWERTYUIOPASDFGHJKLZXCVBNM"
dic += "qwertyuiopasdfghjklzxcvbnm"

# 目标MD5
target = "a35406b8720479039b686e4fa344875a"

# 暴力枚举 4 位组合
for chars in itertools.product(dic, repeat=4):
    plain = ''.join(chars)
    
    # 计算MD5
    md5 = hashlib.md5(plain.encode('utf-8')).hexdigest()
    
    # 比对
    if md5 == target:
        print("找到密码：", plain)
        print("MD5:", md5)
        break