import sys

def output(obj):
    import json
    print(json.dumps(obj))

count = {}
inputfile = sys.argv[1]
with open(inputfile, "r") as f:
    for line in f:
        for word in line.split(sep=' '):
            word = word.strip()
            word = word.lower()
            if len(word) <= 0:
                continue
            if word[-1] == '.' or word[-1] == '?' or word[-1] == '!':
                word = word[:-1]
            if word in count:
                count[word] += 1
            else:
                count[word] = 1

output(count)