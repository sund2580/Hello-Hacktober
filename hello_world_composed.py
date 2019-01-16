alphabets = "abcdefghijklmnopqrstuvwxyz "

position = [7, 4, 11, 11, 14, 26, 22, 14, 17, 11, 3]
res = ""
for i in position:
    res = res + alphabets[i]

print(res)
