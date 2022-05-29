import json
import csv,sys

def parse(file):
    pass

def build(file):
    pass

if len(sys.argv) != 3:
    print('Error: convert.py -b <filename>')
    print('   or: convert.py -p <filename>')
    sys.exit(2)

if sys.argv[1] in ("-b","--build"):
    filename = sys.argv[2][:-4]
    build(filename+'.json')
    
elif sys.argv[1] in ("-p","--parse"):
    filename = sys.argv[2][:-5]
    parse(filename + '.csv')