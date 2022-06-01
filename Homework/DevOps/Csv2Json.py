import json
import csv,sys
from tkinter.ttk import Separator

def parse(file):
    # id、name、type、hardware_model、hardware_sn、software_version、software_last_update、nic1_type、nic1_mac、nic1_ipv4、nic2_type、nic2_mac、nic2_ipv4、state
    FirstRow = ["id","name","type","hardware_model","hardware_sn","software_version","software_last_update","nic1_type","nic1_mac","nic1_ipv4","nic2_type","nic2_mac","nic2_ipv4","state"]
    with open(file, 'r') as f:
        reader = csv.DictReader(f,fieldnames=FirstRow,Separator=',')
        for row in reader:
            print(row)

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