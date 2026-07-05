target = "ippio"
Str1 = []

for i in range(len(target)):
    x = (7 * (ord(target[i]) - 112)) % 10
    Str1.append(chr(x + 48))

print(''.join(Str1))