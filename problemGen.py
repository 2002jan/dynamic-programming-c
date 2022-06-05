import random, os

def appendweight(weights, targetLen):
    while len(weights) != targetLen:
        weights.append(random.randrange(1, 100))
    return weights

def appendvalue(values, targetLen):
    while len(values) != targetLen:
        values.append(random.randrange(1, 100))
    return values

numofitems = [x for x in range(2, 62, 2)]

if not os.path.isdir("problem_instances"):
    os.mkdir("problem_instances")

for i in numofitems:
    for x in range(10):
        capacity = random.randrange(6, i*4)

        weights = []
        appendweight(weights, i)

        while sum(weights) <= capacity:
            weights = appendweight(weights, i)

        values = []
        appendvalue(values, i)
        filename = f"problem_instances/problem_{i}_{x + 1}.txt"

        with open(filename, "w") as f:

            f.write(str(capacity))
            f.write("\n")

            for w, v in zip(weights, values):
                f.write(f"{w} {v}\n")