def rc4(ciphertext, key):
    """RC4 加解密（对称）"""
    # 初始化 S 盒
    sbox = list(range(256))
    j = 0
    key = [ord(c) if isinstance(c, str) else c for c in key]
    
    for i in range(256):
        j = (j + sbox[i] + key[i % len(key)]) % 256
        sbox[i], sbox[j] = sbox[j], sbox[i]
    
    # 生成密钥流并异或
    result = []
    i = j = 0
    for byte in ciphertext:
        i = (i + 1) % 256
        j = (j + sbox[i]) % 256
        sbox[i], sbox[j] = sbox[j], sbox[i]
        k = sbox[(sbox[i] + sbox[j]) % 256]
        result.append(byte ^ k)
    
    return bytes(result)

# 使用示例
ciphertext = bytes([0x3D, 0x93, 0x66, 0x29, 0xE7, 0x31, 0x0E, 0xB2,0x06,0x71,0x91,0x89,0x93])
key = "{This_is_a_key_!}"

plaintext = rc4(ciphertext, key)
print("Hex:", plaintext.hex().upper())
print("Bytes:", plaintext)

# 尝试解码为文本
try:
    print("Text:", plaintext.decode('utf-8'))
except:
    print("Text: (非 UTF-8 文本)")