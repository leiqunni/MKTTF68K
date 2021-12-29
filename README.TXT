X680x0 - ビットマップTTFフォント

説明
  このソフトはSHARP X680x0シリーズのフォントをTTFに変換するソフトです。
  X680x0の動作環境が必要です。

使い方
  まず、実機かエミュレータ環境にて mkbdf16.x を実行し、
  フォントROMからBDFフォントファイルを作成します。

  mkbdf16.x > fontrom_x68k.bdf （完全なBDFファイル）
  mkbdf16.x -c > fontrom_x68k.txt （ヘッダが無い文字データのみ）

（以後書きかけ）

元にしたソフトウェア
  - MKBDF68K 三津田 哲雄(MITSUDA Tetsuo)
    Oh!X 2001春号
    https://github.com/leiqunni/MKBDF68K
  - ttf-pc9800 hikaen2
    https://hikaen2.hatenablog.com/entry/20130104/1357304715
    https://github.com/hikaen2/ttf-pc9800

ファイルの説明
  - mkbdf16.c
    BDFフォント作成プログラムのソースコード。元のMKBDF68Kでは半角フォン
    トのMKBDF16R.Cと全角フォントのMKBDF16K.Cに分かれていましたが、この
    プログラムではひとつのBDFファイルを出力します。そのままBDFフォント
    として使えます。
  - mkbdf16.x
    X68kの実行ファイルです。
