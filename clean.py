import os
import shutil

def clean_dotout():
    for root, dirs, files in os.walk("."):
        # 排除 Luogu/**/data 文件夹
        if root.startswith("./Luogu/") and "data" in root:
            continue
        for file in files:
            if file.endswith(".out"):
                os.remove(os.path.join(root, file))

def clean_dotdSYM():
    for root, dirs, files in os.walk("."):
        for dir in dirs:
            if dir.endswith(".dSYM"):
                # 递归删除该目录
                shutil.rmtree(os.path.join(root, dir))

def main():
    clean_dotdSYM()
    clean_dotout()

if __name__ == "__main__":
    # 遍历当前目录，删除所有 .out 文件和 .dSYM 文件夹
    main()