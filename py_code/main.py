with open('text.txt','r',encoding='utf-8') as f:
    text = f.readlines()

res = []
for i in text:
    # 去掉单独的换行符
    if i != '\n':
        # 去掉行内的空格
        res.append(i.replace(' ',''))

print(''.join(res))