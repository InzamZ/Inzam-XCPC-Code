import datetime

dict = {}
def get_pi_day():
    with open("pi", "r") as f:
        pi = f.read()
        for i in range(len(pi)):
            if (int(pi[i:i+3]) in range(0,1232)) and dict.get(int(pi[i:i+3])) == None:
                dict[int(pi[i:i+3])] = i
            if (i != len(pi)-4) and (int(pi[i:i+4]) in range(0,1232)) and dict.get(int(pi[i:i+4])) == None:
                dict[int(pi[i:i+4])] = i
                
if __name__ == "__main__":
    get_pi_day()
    today = datetime.date.today()
    mmdd = int(today.strftime("%m%d"))
    for mm in range(1,13):
        for dd in range(1,32):
            print(f'{mm}月{dd}日是 π 节：出现在 π 的第 {dict[mm*100+dd]} 位')
    print(f'今天是 π 节：出现在 π 的第 {dict[mmdd]} 位')