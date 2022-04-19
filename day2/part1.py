fd = open("input", "r")
horiz = 0
depth = 0

for line in fd.readlines():
    line = line.rstrip().split(' ')

    match line[0]:
        case "forward":
            horiz += int(line[1])
        case "up": 
            depth -= int(line[1])
        case "down":
            depth += int(line[1])

print(horiz*depth)

