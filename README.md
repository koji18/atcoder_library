# AtCoder Solutions

AtCoder競技プログラミング問題をC++で解いた解答集です。

## 実行方法

VSCode で右上の▶️ボタン（Code Runner）で実行

```
右上ボタン → プログラム実行
F5キー → デバッグ実行
```

## Makefile での実行（推奨）

```
make run SRC=ABC/a/273.cpp
make set SRC=ABC/a/273.cpp
make new ABC 999 a
```

### テスト

```
make download SRC=ABC/a/273.cpp
make test SRC=ABC/a/273.cpp
```

`oj` があれば自動でサンプル取得・実行します。ない場合は `in/` と `out/` を手動で用意して `make test` できます。

### ランダム取得

```
make randa PROB=a
```

`ABC_MAX` を指定すると対象範囲を変えられます（例: `ABC_MAX=300`）。

### VSCode タスク

`make run (active)` / `make set (active)` を使うと、アクティブなファイルで実行できます。

## ファイル構成

```
atcoder/
├── ABC/
│   ├── a/
│   ├── b/
│   └── c/
├── ARC/
└── paiza/
```

## 入力形式

AtCoderの標準入力形式に準拠。問題ごとに異なります。

```
# 例1：N個の整数
5
1 2 3 4 5

# 例2：N行のデータ
3
10 20
30 40
50 60
```

## 環境設定

- VSCode
- Code Runner拡張機能
- g++でコンパイル、gdbでデバッグ対応
