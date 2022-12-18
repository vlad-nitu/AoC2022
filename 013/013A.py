with open("013A.in") as fin:
    parts = fin.read().strip().split("\n\n")


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

        # If i didn't hit the end of a, it hit the end of b first
        #   This means that b is shorter, which is bad
        return -1


ans = 0
for i, block in enumerate(parts):
    a, b = map(eval, block.split("\n"))
    if compare(a, b) == 1:
        ans += i + 1

print(ans)
