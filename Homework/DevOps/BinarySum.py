from ast import arg
import sys

ans = 0
for i in range(1, len(sys.argv)):
    ans += int(sys.argv[i], 2)
    
print(bin(ans).replace("0b", ""))