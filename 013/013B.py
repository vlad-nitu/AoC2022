from functools import cmp_to_key

with open("./013B.in") as fin:
    parts = fin.read().strip().replace("\n\n", "\n").split("\n")


def compare(a, b):
    if type(a) == list and type(b) == int:
        b = [b]

    if type(a) == int and type(b) == list:
        a = [a]

    if type(a) == int and type(b) == int:
        if a < b:
            return 1
        if a == b:
            return 0
        return -1

    if type(a) == list and type(b) == list:
        i = 0
        while i < len(a) and i < len(b):
            x = compare(a[i], b[i])
            if x == 1:
                return 1
            if x == -1:
                return -1

            i += 1

        if i == len(a):
            if len(a) == len(b):
                return 0
            return 1  # a ended first

        #   This means that b is shorter, which is bad
        else:
            return -1


lists = list(map(eval, parts))
lists.append([[2]])
lists.append([[6]])
# https://www.geeksforgeeks.org/how-does-the-functools-cmp_to_key-function-works-in-python/
lists = sorted(lists, key=cmp_to_key(compare), reverse=True)



for i, li in enumerate(lists): # 1-indexed in I0N0
    if li == [[2]]:
        a = i + 1
    if li == [[6]]:
        b = i + 1

print(a * b)
