from collections import deque
fd = open("input", "r")

window = []
cnt = 0

for line in fd.readlines():
    curr = int(line.rstrip())
    window.append(curr)
    if (len(window) == 4):
        print(window)
        if (sum(window[0:3]) < sum(window[1:4])):
            cnt += 1
        del window[0]

print(cnt)
