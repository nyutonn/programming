# 202年度 乾研100本ノック

自然言語処理に関するプログラムを実際に作ってもらい，互いにコードレビューを行います．\
問題に対する答えは一つではありません．どんな方法でも，無理矢理でも解いてみてください．

## 問題
[言語処理100本ノック 2020](https://nlp100.github.io/)  
(旧バージョン: [言語処理100本ノック 2015](http://www.cl.ecei.tohoku.ac.jp/nlp100/))

## 解説資料
[cl-tohoku NLP100 Book](https://www.cl.ecei.tohoku.ac.jp/local/nlp100-book/landing-page.html)
- 色々なパターンの解や補足情報が載っているので、自力で解いてみたあとに見てみるととても勉強になります
- 皆さんが研究で実際にコードを書くとき，当然そのコードの模範解答は存在しません．まずは自力でコードを書いてみることが重要です

## 取り組み方

- メンターが「次回までにn問解いてきてね」と指定します
- 受講者は指定された問題を予習してください
  - もし分からない場合も，試行の結果をコードの形で残すようにしましょう
  - 「分かりませんでした」「解説資料をコピペしました」だけで終わるのは避けましょう
- 各回では，お互いのコードを見ながら中身について議論します
- 議論の際の有益なコメント等は共有メモとしてscrapboxなどにまとめておくことを推奨します

## 初回のセッティング方法

```bash
cd [お好きなディレクトリ]
git clone 'git@github.com:cl-tohoku/100knock-2023.git'
cd 100knock-2023
git checkout -b [ユーザー名]
mkdir trainee_[ユーザー名]
git commit --allow-empty -m "Initial commit"
git push -u origin [ユーザー名]
```

以降は trainee_\[各ユーザー名\] ディレクトリ以下にコードを配置してください．

## コードを GitHub に push する時に毎回すること

(100knock-2023にcdしてから)

```bash
git add trainee_[ユーザー名]
git commit -m "イケてるコメント（加えた変更など）"
git push
```

## 個人ディレクトリの構成

できれば以下のようにしてください．

```plain
shiki-sato/
  ├ chapter01/
  │   └ shiki-sato_ch01.ipynb <- 名前がわかるように
  ├ chapter02/
  │   ├ data/            <- 処理対象のデータ（加工前）を配置
  │   │   └ hightemp.txt
  │   ├ src/             <- 中間スクリプトに落とす必要があればそれを配置
  │   │   ├ q014.py
  │   │   ├ q015.py
  │   │   └ q016.py
  │   ├ work/            <- 処理による中間生成物を配置
  │   │   ├ col1.txt
  │   │   ├ col2.txt
  │   │   ├ xaa
  │   │   ├ xab
  │   │   ├ xac
  │   │   ├ xad
  │   │   └ xae
  │   └ shiki-sato_ch02.ipynb
  ├ chapter03/
  .
  .
  .
```

`data` と `work` はgit管理下から除外されます．

## メンターの仕事

開始前に参加者のブランチから master にマージする．具体的には次のコマンドを叩けば良い：

```bash
scripts/merge_all_into_master.sh  # conflict が発生したら適宜解消する
git push
```

