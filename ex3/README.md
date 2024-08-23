# 1 回だけメッセージを読み取る例

writer が長いメッセージを 1 回だけ書き込み、reader が読み込んで出力する例。

## ビルド & 実行

ビルド

```shell
cmake -S . -B build
cmake --build build
```

実行

読み込み側を起動

```shell
build/reader.out
```

書き込み側を起動（↑ のシェルとは別のシェルで起動する）

```shell
build/wrter.out
```

## ブロッキングについて

writer 側の`open`は、読み込み側が開くまでブロックされる。
上の実行例で、reader と writer の起動順序を入れ替えると、writer は reader が起動するまで open のところで止まったままとなる。

## FIFO の終端について

EOF という文字はない。したがって、明示的に writer がファイルの終端という情報を送ることはできない。
reader 側が持っている FIFO の書き込み側がすべてクローズされると、`read`が 0 を返す。
これをもって、ファイルの終端とみなすことが普通。[参考](https://unix.stackexchange.com/questions/376059/send-eof-to-named-pipe-cleaning-up-drying-up-fifo)
