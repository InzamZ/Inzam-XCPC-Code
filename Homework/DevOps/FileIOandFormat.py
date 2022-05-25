import sys

inputfile = sys.argv[1]
outputfile = sys.argv[2]

fir = False
with open(inputfile, "r") as f:
    with open(outputfile, "w") as g:
        for line in f:
            cnt = 0
            if fir :
                g.write('\n')
            fir = True
            for c in line:
                if c <= '9' and c >= '0':
                    cnt += 1
                    if cnt == 4 or cnt == 7:
                        g.write('-')
                    g.write(c)