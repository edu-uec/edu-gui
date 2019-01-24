# Qt Quick

- Qt5.11.2 をMojave で使えなかったためQt5.11.0 を使用
- main.cpp は初期のまま(2018/10/14 時点) でqmlファイルを作成した
- MainForm.ui.qml は.uiが使えるかのテストでmainの処理では触れてない．
- 動作としては，クリックするとブロックが横に増えていくという感じ

※build ~~/ ファイルも入れているけど，Qt kit の扱いかたが分からず一様gitに乗せています．

build を入れないで，実行できるか確認してみたらうまく読み込めず実行できなかったのでこういうことしてます．

# gui-develop
文字通りeduの画面構成を担っているが、テストのために他ブランチの機能を吸収することも多いため、実質いわゆるdevelopブランチに該当するものであると思っている。

# RaspberryPi 上での動かし方

- Qt5 を install します
  - ラズパイ用のQt リポジトリ参照
- 入れたら，OpenGL を有効にします

```
$ sudo raspi-config
-> Advanced Option
-> GL Driver
 -> GL (Full KMS) or GL (fake KMS ) を選択 
```
fake でも大丈夫だと思いますが，Qtを実行したとき調子が悪かったら変えて見たらよいかも？

- コマンドラインから qtcreator を立ち上げます

```
$ qtcreator
```
- clone してきたprojecto をOpen
- Kit がないと言われると思うので，手動で設定します
- https://qiita.com/soramimi_jp/items/b2b238d1537dbb99abea
- ↑にあるように，Kit で Add を選択
  - C - /usr/bin/gcc
  - C++ - /usr/bin/g++
  - の対応で設定します
  - [大切] Qt を 設定してあげます
  - ` /usr/local/Qt_{version}/ ` みたいな感じで入れてあるはずなので，それを選んであげます

- これえプロジェクトを起動できるはず
- 実行して見ましょう．

## Julius を入れます ( optional )

- 忙しい人のため

```
$ sudo aptitude install libasound2-dev
```

```
$ cd
$ sudo wget -O julius-4.4.2.tar.gz https://github.com/julius-speech/julius/archive/v4.4.2.tar.gz
$ tar zxvf julius-4.4.2.tar.gz
$ cd Julius-4.4.2/
$ ./configure --with-mictype=alsa
$ make
$ sudo make install
```

```
$ mkdir julius-kit
$ cd julius-kit
$ sudo wget https://osdn.net/dl/julius/dictation-kit-v4.4.zip
$ sudo wget -O grammar-kit-v4.3.1.zip https://github.com/julius-speech/grammar-kit/archive/v4.3.1.zip
$ unzip dictation-kit-v4.4.zip
$ unzip grammar-kit-v4.3.1.zip
```

```
$ cp -r dictation-kit-v4.4/model {edu リポジトリ}/Julius/
```

- https://fabcross.jp/category/make/sorepi/20180326_julius.html?fm=side_ranking より
- こんな感じでぽちぽちすればいけます
- ↑ grammar は別にいらないかも
- 最後ので model をコピーする(ちょっと時間かかる)

```
$ export ALSADEV="plughw:1,0"
```
- ここの設定をすべきかどうかまだちょっと不明

## マイクの優先順位を変える

### 実験中

- よくはない例

```
pi@raspberrypi:~/Edu/edu $ cat /proc/asound/modules
 0 (null)
 1 snd_usb_audio
```

- こんな感じで， snd_usb_audio がラズパイデフォルトのマイクより優先されてる状態に持っていくのが目標


- /lib/modprobe.d/aliases.conf
- /etc/modprobe.d/alsa-base.conf
- をいじって... みたいな記述があるけど，色々やって見たけどパソコンくんが全然いうことを聞いてくれなかったので
- default の mic (snd_...?) を blacklist に入れて 無視するようにした
- TODO: もっと美しく，あざかに



## 履歴
- commit "introduced socket_sever system and corresponded julius order reflected to gui items"<br><br>
ソケットサーバーのシステムを導入し、別プログラムedu(juliusReceiver, socket client)からの送信を想定して、受信プログラムを作成。
QMLはjulius orderによるw_xxx系のaddやc_003のremoveぐらいには対応するようにした。
