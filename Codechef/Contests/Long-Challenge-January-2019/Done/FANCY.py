t = int(input())

for i in range(t):
    s = input()
    l = s.split()
    if 'not' in l:
        print('Real Fancy')
    else:
        print('regularly fancy')
