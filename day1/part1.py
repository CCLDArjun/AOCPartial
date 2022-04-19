fd = open("input", "r")

prev = None
cnt = 0
for line in fd.readlines():
    curr = int(line.rstrip())
    if (prev and curr > prev):
        cnt += 1
    prev = curr

print(cnt)
