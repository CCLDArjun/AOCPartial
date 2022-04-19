import math

org_inp = ""
rules = dict()

def read():
    global org_inp
    fd = open("input", "r")
    lines = fd.readlines()
    org_inp = lines[0].rstrip()
    for line in lines[2:]:
        rules[line.split()[0]] = line.split()[2]

read()
curr = dict()
count = dict()

def put(curr, key, val=1):
    try:
        curr[key] += val
    except KeyError:
        curr[key] = val

def update_count(curr):
    for polymer_pair, c in curr.items():
        put(count, polymer_pair[0], c)
        put(count, polymer_pair[1], c)
    for polymer, c in count.items():
        count[polymer] = math.ceil(count[polymer] / 2)

for i in range(len(org_inp) - 1):
    put(curr, org_inp[i:i+2])

def reproduce(curr, rules):
    new_curr = dict()
    for x in curr.keys():
        new = rules[x]
        new = x[0] + new + x[1]
        print(new, end='')
        put(new_curr, new[0:2], curr[x])
        put(new_curr, new[1:3], curr[x])
    print()
    return new_curr

for x in range(40):
    curr = reproduce(curr, rules)

print(update_count(curr))
print(count)
print(max([x for y,x in count.items()]) - min([x for y,x in count.items()]))

