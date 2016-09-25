num = int(input())
i = 0
while i<num:
    ans = ""
    temp = 0
    arr = {0:0, 1:1, 2:2, 3:5, 4:9, 5:8, 6:6}
    x = int(input())
    if x < 7:
        ans = ans + str(arr[x])
    else:
        while x >= 7:
            temp = int(x%7)
            ans = ans + str(arr[temp])
            x = x//7
        ans = ans + str(arr[x])
    print(ans)
    i = i+1;
