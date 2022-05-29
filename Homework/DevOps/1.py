import sys
import getopt
import csv
import json

def GetFileName(argv):
    try:
        opts, args = getopt.getopt(argv,"p:b:",["parse=","build="])

    except getopt.GetoptError:
        print('Error: convert.py -b <filename>')
        print('   or: convert.py -p <filename>')
        sys.exit(2)

    filename = opts[0][1]
    
    if len(opts) == 0 :
        print('Error: convert.py -b <filename>')
        print('   or: convert.py -p <filename>')
        sys.exit(2)
    elif opts[0][0] in ("-b","--build"):
    #    filename = opts[0][1]+".csv"
        pass
    elif opts[0][0] in ("-p","--parse"):
    #    filename = opts[0][1]+".json"
        pass
    else :
        print('Error: convert.py -b <filename>')
        print('   or: convert.py -p <filename>')
        sys.exit(2)
        
    return (opts[0][0],filename)

def parse(file):
    print(file+'.json')
    reslist = list()
    targetf = open (file+'.csv',"w",newline='')
    firstrowstr = ""
    firstrow = list()
    flag = True
    with open(file+'.json',newline='') as jsonfile:
        cnt = 0
        srclist = json.load(jsonfile)
        for x in srclist:
            cnt = 0
            if flag == False :
                break
            for key in x:
                if isinstance(x[key],str) :
                    if (key != "id") :
                        firstrowstr += ','
                    firstrowstr += key
                    firstrow.append(key)
                elif isinstance(x[key],dict):
                    keyprename = key + '_'
                    for key2 in x[key]:
                        if (key != "id") :
                            firstrowstr += ','
                        firstrowstr += (keyprename + key2)
                        firstrow.append(keyprename + key2) 
                    print('dict\n')
                elif isinstance(x[key],list):
                    for interface in x[key]:
                        cnt = cnt + 1
                        if cnt == 1 :
                            keyprename = 'network1_'
                        elif cnt == 2 :
                            keyprename = 'network2_'
                        for key2 in interface:
                            if (key != "id") :
                                firstrowstr += ','
                            firstrow.append(keyprename + key2) 
                            firstrowstr += (keyprename + key2)
            if flag:
                flag=False 
                firstrowstr += '\n'
    targetf.write(firstrowstr)
    writer = csv.DictWriter(targetf, fieldnames = firstrow, dialect='excel')
    with open(file+'.json',newline='') as jsonfile:
        cnt = 0
        srclist = json.load(jsonfile)
        for x in srclist:
            resdict = dict()
            cnt = 0
            for key in x:
                if isinstance(x[key],str) :
                    resdict[key] = x[key]
                elif isinstance(x[key],dict):
                    keyprename = key + '_'
                    for key2 in x[key]:
                        resdict[keyprename + key2] = x[key][key2]
                    print('dict\n')
                elif isinstance(x[key],list):
                    for interface in x[key]:
                        cnt = cnt + 1
                        if cnt == 1 :
                            keyprename = 'network1_'
                        elif cnt == 2 :
                            keyprename = 'network2_'
                        for key2 in interface:
                            resdict[keyprename + key2] = interface[key2]
                    print('list\n')
            if flag:
                flag=False
            reslist.append(resdict)
            writer.writerow(resdict)
    
def build(file):
    flag = True
    print(file+'.csv')
    reslist = list()
    targetf = open (file+'.json',"w",newline='')
    with open(file+'.csv',newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            resdict = dict()
            hardware = dict()
            software = dict()
            network = list()
            interface1 = dict()
            interface2 = dict()
            networkflag = True
            for key in row:
                if len(network)>0 and networkflag:
                    resdict['network'] = network
                    netflag = False
                if key.startswith('hardware'):
                    subkey = key.strip()[9:]
                    hardware[subkey.strip()] = row[key].strip()
                    resdict['hardware'] = hardware
                elif key.startswith('software'):
                    subkey = key.strip()[9:]
                    software[subkey.strip()] = row[key].strip()
                    resdict['software']=software
                elif key.startswith('network1'):
                    subkey = key.strip()[9:]
                    if len(interface1) == 1:
                        network.append(interface1)
                    if row[key].strip() != "":
                        interface1[subkey.strip()] = row[key].strip()
                elif key.startswith('network2'):    
                    subkey = key.strip()[9:]
                    if len(interface2) == 1:
                        network.append(interface2)
                    if row[key].strip() != "":
                        interface2[subkey.strip()] = row[key].strip()
                else:
                    resdict[key.strip()]=row[key].strip()
            reslist.append(resdict)
            # print(reslist)
            
        outstr = json.dumps(reslist,ensure_ascii=False, indent=4, separators=(',', ': '))
        targetf.write (outstr)
    
    
def main(sys_argv):
    opt = GetFileName(sys_argv)
    if opt[0] in ["-p","--parse"]:
        parse(opt[1])
    else :
        build(opt[1])
    
main(sys.argv[1:])
