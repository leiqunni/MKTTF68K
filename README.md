# MKTTF68K
SHARP X680x0のROMビットマップフォントからTrueTypeフォントを生成します。

# 使用例
![enter image description here](https://user-images.githubusercontent.com/1372589/153024356-ac22619e-53ab-4678-a844-395f2632845a.png)

![enter image description here](https://user-images.githubusercontent.com/1372589/153024396-1fddf1d3-9a22-43a0-ad66-8d752f0bbe88.png)

# 機能の説明
X680x0シリーズの16x16 ROMビットマップのフォントからWindowsやMacintosh等で使えるTrueTypeフォントを生成します。  
元にしたttf-pc9800からの特徴は、元のビットマップフォントからアウトラインを生成しているので、フォントサイズを変更してもドットが表現されます。  
また文字コードをシフトJISからUnicodeに変換し、その際に足りない文字を東雲フォントから補っています。  

実機のROMイメージからBDFファイルの作成には、MKBDF68K 三津田 哲雄(MITSUDA Tetsuo)を、BDFファイルからアウトラインを作成しTureTyoeフォントを生成する部分は、ttf-pc9800 hikaen2を元にしています。

MKBDF68K: https://github.com/leiqunni/MKBDF68K  
ttf-pc9800: https://github.com/hikaen2/ttf-pc9800 and https://hikaen2.hatenablog.com/entry/20130104/1357304715

# 必要なもの
* LinuxやCygwinなどのUnix環境
* make
* ruby
* fontforge
* bdfresize
* potrace
* patch
* sed
* ttx (fontTools) 

# インストール
LinuxやCygwin環境でコンパイルできます。32bit/64bitどちらの環境でも 動作します。Cygwin環境では bdfresize を自分で用意する必要があります。下記URL等からソースコードを拾えます。  
https://github.com/ntwk/bdfresize  
注意：上記サイトのソースコードは、そのままではコンパイル時にエラーが出ます。charresize.c の49行目辺りに、

	char	*malloc();

と何故か宣言されているので、これを削除するなりコメントアウトしてください。

またfontToolsのttxはPython 3.8のものを使ったので、実行ファイル名がMakefileの中でtth3.8と書かれています。適宜変更してください。

# 使い方
まず、実機かエミュレータ環境にてmkbdf16.xを実行し、フォントROMからBDFファイルを作成します。

    C:\>mkbdf16.x > fontrom.bdf （完全なBDFファイル）
    C:\>mkbdf16.x -c > fontrom.txt （ヘッダが無い文字データのみ）

次に、配布されている圧縮ファイルを作業環境で展開し、その中のdataディレクトリにfontrom.bdfを置いて、makeしてください。makeに成功すると、compiledディレクトリにX680x0.ttfが生成されます。

# その他
最近のFontForgeには「FontForgeで生成した日本語TrueTypeフォント文字幅広すぎ問題」があります。問題回避に一度生成されたTTFファイルにttxでパッチを当てています。詳しくは下記URLサイトを御覧ください。  
https://itouhiro.hatenablog.com/entry/20140910/font

# License
[MIT license](https://en.wikipedia.org/wiki/MIT_License).
