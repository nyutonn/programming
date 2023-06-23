import random
import time

ZERO = []
ONE = ["エボラ出血熱", "ラッサ熱", "クリミア・コンゴ出血熱", "マールブルグ病", "痘瘡（天然痘）", "南米出血熱", "ペスト"]
TWO = ["ジフテリア", "ポリオ", "結核", "鳥インフルエンザ", "SARS(重症急性呼吸器症候群)", "MERS(中東呼吸器症候群)"]
THREE = ["コレラ","腸チフス","パラチフス","赤痢", "腸管出血性大腸菌（O-157）"]
FOUR = ["ツツガムシ病", "日本脳炎","デング熱","A型肝炎","E型肝炎","マラリア","ジカ熱","炭疽","ボツリヌス症","狂犬病","鳥インフルエンザ","野兎病","黄熱","Q熱"]
FIVE = ["麻疹風疹（MR）","MRSA","インフルエンザ","VRE","クリプトスポリジウム症（クロイツフェルトヤコブ病）","B型肝炎","C型肝炎","AIDs","破傷風","梅毒"]
INFECTION = [ZERO, ONE, TWO, THREE, FOUR, FIVE]

def choose_mode():
    print("感染症対策！")
    print("モード選択してください。")
    print("モード1 一問一答")
    print("モード2 四択問題")
    mode = int(input("1 or 2を選択してください："))
    return mode

def question_mode1(n):
    try: 
        ok = 0
        ng = 0
        for i in range(n):
            print(f"第{i+1}問！")
            rui = random.randint(1, 5)
            no  = random.randint(0, len(INFECTION[rui]) - 1)
            q   = INFECTION[rui][no]
            print(f"{q}は何類感染症ですか？")
            my_ans = int(input("answer : "))
            if rui == my_ans:
                print("正解！")
                ok += 1
            else:
                print("不正解...")
                ng += 1

            print(f"{q}は{rui}類感染症です")
            time.sleep(3)
            print()
        print()

    finally:
        print(f"\n正解数：{ok}\n誤答数：{ng}")

def question_mode2(n):
    try: 
        ok = 0
        ng = 0
        for i in range(n):
            print(f"第{i+1}問！")
            ans_rui = random.randint(1, 5)
            ans_no  = random.randint(0, len(INFECTION[ans_rui]) - 1)
            ans_q   = INFECTION[ans_rui][ans_no]
            
            print(f"第{ans_rui}類感染症はどれ？")
            
            no_rui_list  = []
            no_ans_q_list = []
            while len(no_ans_q_list) != 3:
                no_ans_rui = random.randint(1, 5)
                if no_ans_rui == ans_rui:
                    continue
                no_ans_no  = random.randint(0, len(INFECTION[no_ans_rui]) - 1)
                no_ans_q = INFECTION[no_ans_rui][no_ans_no]
                if no_ans_q in no_ans_q_list:
                    continue
                no_rui_list.append(no_ans_rui)
                no_ans_q_list.append(no_ans_q)
            
            ans_index = random.randint(1, 4)
            no_ans_index = 0
            for j in range(1, 5):
                if j == ans_index:
                    print(f"{j}. {ans_q}")
                else:
                    print(f"{j}. {no_ans_q_list[no_ans_index]}")
                    no_ans_index += 1
            my_ans = int(input("answer : "))
            if my_ans == ans_index:
                print("正解！")
                ok += 1
            else:
                print("不正解...")
                ng += 1

            no_ans_index = 0
            for j in range(1, 5):
                time.sleep(2)
                if j == ans_index:
                    print(f"{ans_q} : {ans_rui}類感染症")
                else:
                    print(f"{no_ans_q_list[no_ans_index]} : {no_rui_list[no_ans_index]}類感染症")
                    no_ans_index += 1
                    
            time.sleep(3)
            print()


    finally:
        print(f"\n正解数：{ok}\n誤答数：{ng}")

def question_mode3(n):
    try: 
        ok = 0
        ng = 0
        print(f"誤っている組み合わせはどれでしょう？")
        for i in range(n):
            print(f"第{i+1}問！")

        
            
            

        time.sleep(3)
        print()

    finally:
        print(f"\n正解数：{ok}\n誤答数：{ng}")

try:
    mode = choose_mode()
    if mode == 1:
        question_mode1(5)
    elif mode == 2:
        question_mode2(5)
    elif mode == 3:
        question_mode3(5)

finally:
    print("おつかれさまでした")