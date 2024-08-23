# FIFO へ書き込む例

writer は、標準入力から文字列を読み取り、その値を FIFO に書き込む。

cat コマンドで、上記の FIFO を読み取る。

ビルド

```shell
$ cmake -S . -B build
$ cmake --build build
```

実行

読み込み側を起動

```shell
$ mkfifo /tmp/my_fifo
$ cat /tmp/my_fifo
```

書き込み側を起動（↑ のシェルとは別のシェルで起動する）

```shell
build/wrter.out
```

書き込み側のシェルで 10 回、標準入力に値を打ち込むと終了する。
