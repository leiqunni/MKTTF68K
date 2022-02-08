MKTTF68K - ビットマップTTFフォント

説明
  このソフトはSHARP X680x0シリーズのフォントをTTFに変換するソフトです。
  X680x0の動作環境が必要です。

使い方
  まず、実機かエミュレータ環境にて mkbdf16.x を実行し、
  フォントROMからBDFフォントファイルを作成します。
  
  C:\>mkbdf16.x > fontrom.bdf （完全なBDFファイル）
  C:\>mkbdf16.x -c > fontrom.txt （ヘッダが無い文字データのみ）

  ここで出作った fontrom.bdf を data ディレクトリに配置して、make してく
  ださい。make に成功すると compiled ディレクトリに X680x0.ttf が生成
  されます。

コンパイルに必要なソフトウェア
  - make
  - Ruby
  - FontForge
  - bdfresize
  - Potrace
  - patch
  - sed
  - ttx (fontTools)

  LinuxやCygwin環境でコンパイルできます。32bit/64bitどちらの環境でも
  動作します。Cygwin環境では bdfresize を自分で用意する必要があります。
  下記URL等からソースコードを拾えます。
  https://github.com/ntwk/bdfresize

  注意：上記サイトのソースコードは、そのままではコンパイル時にエラーが
  出ます。charresize.c の49行目辺りに、

  char	*malloc();

  と何故か宣言されているので、これを削除するなりコメントアウトしてくだ
  さい。

  また fontTools の ttx は Python 3.8 のものを使ったので、実行ファイル
  名が Makefile の中で ttx3.8 と書かれています。適宜変更してください。

アーカイブに同梱されているファイルのオリジナル配付サイト
  - 東雲 ビットマップフォントファミリー
    http://openlab.ring.gr.jp/efont/shinonome/
  - ユニコードコンソーシアムの変換表
    http://www.unicode.org/Public/MAPPINGS/
  - 安岡孝一 (Koichi Yasuoka)
    http://kanji.zinbun.kyoto-u.ac.jp/~yasuoka/

元にしたソフトウェア
  - MKBDF68K 三津田 哲雄(MITSUDA Tetsuo)
    Oh!X 2001春号
    https://github.com/leiqunni/MKBDF68K
  - ttf-pc9800 hikaen2
    https://hikaen2.hatenablog.com/entry/20130104/1357304715
    https://github.com/hikaen2/ttf-pc9800

ファイルの説明
  - data/shnm8x16a.bdf
    東雲フォント（Shinonome 16dot font for ISO 8859-1）
    オリジナルファイル：shinonome-0.9.11p1.tar.bz2
  - data/shnm8x16r.bdf
    東雲フォント（Shinonome 16dot font for JISX 0201, 1976）
    オリジナルファイル：shinonome-0.9.11p1.tar.bz2
  - data/shnmk16.bdf
    東雲フォント（Shinonome 16dot font for JISX 0208, 1983/1990）
    オリジナルファイル：shinonome-0.9.11p1.tar.bz2
  - data/CP932.TXT
    ユニコードコンソーシアムの変換表（CP932からUnicode）
    オリジナルファイル：VENDORS/MICSFT/WINDOWS/CP932.TXT
  - data/JIS0201.TXT
    ユニコードコンソーシアムの変換表（JIS X 0201-1976からUnicode）
    オリジナルファイル：OBSOLETE/EASTASIA/JIS/JIS0201.TXT
  - data/Uni2JIS
    安岡孝一さんの変換表（UnicodeからJIS C 6226-1978）
    オリジナルファイル：
    http://kanji.zinbun.kyoto-u.ac.jp/~yasuoka/ftp/CJKtable/Uni2JIS.Z
  - data/EXT.TXT
    PC-98の文字セットからUnicodeへの変換表
  - data/X680x0.ttx
    FontForgeで生成した日本語TrueTypeフォント文字幅広すぎ対策
    詳しくは下記URL等ご参照ください。
    https://itouhiro.hatenablog.com/entry/20140910/font
  - Makefile
    コンパイル用Makeファイル
  - mkbdf16.c
    BDFフォント作成プログラムのソースコード。元のMKBDF68Kでは半角フォン
    トのMKBDF16R.Cと全角フォントのMKBDF16K.Cに分かれていましたが、この
    プログラムではひとつのBDFファイルを出力します。そのままBDFフォント
    として使えます。
  - mkbdf16.x
    X68kの実行ファイル。
  - README.TXT
    このファイル。
