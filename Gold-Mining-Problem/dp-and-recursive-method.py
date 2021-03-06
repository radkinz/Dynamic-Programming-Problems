goldmine = [[1, 3, 6, 7, 5], [8, 7, 2, 3, 4], [2, 4, 5, 8, 7], [6, 3, 7, 9, 1]]

#recursion
def goldMine(mine, startingpos):
  #base case
  if len(mine) == 1:
    return mine[0][startingpos]
 
  if startingpos == 0:
    return  mine[0][startingpos] + max(goldMine(mine[1:],startingpos), goldMine(mine[1:],startingpos+1))
  if startingpos == len(mine[0])-1:
    return  mine[0][startingpos] + max(goldMine(mine[1:],startingpos), goldMine(mine[1:],startingpos-1))

  return  mine[0][startingpos] + max(goldMine(mine[1:], startingpos), goldMine(mine[1:],startingpos+1), goldMine(mine[1:],startingpos-1))

#DP
def goldmineDP(mine):
  table = [] 
  for i in range(len(mine)):
    table.append([]);
    for j in range(len(mine[0])):
      table[i].append(0)

  #base case
  for i in range(len(mine[0])):
    table[0][i] = mine[0][i]

  for i in range(1, len(mine)):
    for j in range(len(mine[0])):
      if j == 0:
        table[i][j] = max(mine[i][j] + table[i-1][j],mine[i][j] + table[i-1][j+1])
      elif j == len(mine[0])-1:
        table[i][j] = max(mine[i][j] + table[i-1][j],mine[i][j] + table[i-1][j-1])
      else:
        table[i][j] = max(mine[i][j] + table[i-1][j],mine[i][j] + table[i-1][j-1],mine[i][j] + table[i-1][j+1])
  
  return max(table[len(mine)-1])

print(goldmineDP(goldmine), goldMine(goldmine, len(goldmine)-1))
