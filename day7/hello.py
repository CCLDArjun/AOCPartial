with open('input-3.txt', 'r') as f:
    list_x_pos = [int(line) for line in f.read().split(',')]

x_dic = {}
for x_pos in list_x_pos :
  x_dic[x_pos] = list_x_pos.count(x_pos)

def fuel_cost(x_pos):
  cost = 0
  for k,v in x_dic.items():
    # cost += abs(k-x_pos) * v
    cost += sum(range(abs(k-x_pos)+1)) * v
  return(cost)

dic_costs = {}
for i in range(max(list_x_pos)):
  dic_costs[i] = fuel_cost(i)

print(min(dic_costs.values()))
