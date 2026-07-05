import hashlib

target = "eb62f6b9306db575c2d596b1279627a4"

print("开始暴力枚举 0000-9999...")
for num in range(10000):
    plain = f"{num:04d}"  # 格式化为 4 位数字
    md5_val = hashlib.md5(plain.encode()).hexdigest()
    
    if md5_val == target:
        print(f"\n✅ 找到匹配！")
        print(f"前4位数字: {plain}")
        print(f"MD5: {md5_val}")
        break
else:
    print("❌ 未找到匹配 (0000-9999 都不等于目标 MD5)")