import argparse

# パーサーを作る
parser = argparse.ArgumentParser(
    prog='argparse_test.py', # プログラム名
    usage='argparseのテスト', # 利用方法を記述
    description='ヘルプ前に表示するところ', # 引数のヘルプの前に表示
    epilog='ヘルプ後に表示するところ', # 引数のヘルプの後に表示
    add_help=True # -h/--helpオプションの追加
)

# 引数の追加
parser.add_argument('-v', '--verbose', # オプション名
                    help='select mode', # helpの表示
                    action='store_true', # オプションの処理内容を決める
                    required=True, # このオプションの省略不可にする
                    )
parser.add_argument('-i',
                    help='integer',
                    type=int, # 引数の型指定
                    choices=[0, 1], # 引数の範囲指定
                    metavar='int, 0 or 1',
                    default=0,
                    )
parser.add_argument('-m',
                    help='multipule',
                    type=float,
                    nargs=2, # 引数の数を指定, 2以上にするとリストになる
                    )
parser.add_argument('--infile', help='input file',
                    type=argparse.FileType('r')
                    )
parser.add_argument('--outfile', help='output file',
                    type=argparse.FileType('w')
                    )
parser.add_argument('--version', 
                    version='%(prog)s 1.0.0', # バージョンの表示
                    action='version',
                    default=False
                    )

# 引数の解析をする
args = parser.parse_args()
if args.verbose:
    print('yes', args.i, args.m[0] * args.m[1])
    # ファイルの書き込みと読み込み
    message = args.infile.read()
    args.infile.close()
    args.outfile.write(message + '!!')
    args.outfile.close()
else:
    print('no', args.i)

