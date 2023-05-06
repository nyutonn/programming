import argparse
from itertools import islice
parser = argparse.ArgumentParser(
    add_help=True,
)
parser.add_argument('readfile', help='read mode file',
                    type=argparse.FileType('r') # 読み込みモード
                    )
parser.add_argument('-n', help='行数の指定',
                    type=int,
                    default=10 # 指定しなかったら10行にする
                    )
args = parser.parse_args()
for line in islice(args.readfile, args.n):
    line = line.rstrip()
    print(line)
args.readfile.close()