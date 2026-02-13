def alphabetToNum(c):
    if c >= 'a' and c <= 'z':
        return (ord(c) - ord('a') + 1) * 100
    elif c >= 'A' and c <= 'Z':
        return (ord(c) - ord('A') + 1) * 10000
    elif c >= '0' and c <= '9':
        return int(c)
    else:
        return 10000

result = 0
for a in "111BBBccc!@#$^*":
    result += alphabetToNum(a)
print(result)
