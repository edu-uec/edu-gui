# Qt Quick

- Qt5.11.2 をMojave で使えなかったためQt5.11.0 を使用
- main.cpp は初期のまま(2018/10/14 時点) でqmlファイルを作成した
- MainForm.ui.qml は.uiが使えるかのテストでmainの処理では触れてない．
- 動作としては，クリックするとブロックが横に増えていくという感じ

※build ~~/ ファイルも入れているけど，Qt kit の扱いかたが分からず一様gitに乗せています．

build を入れないで，実行できるか確認してみたらうまく読み込めず実行できなかったのでこういうことしてます．

# gui-develop
文字通りeduの画面構成を担っているが、テストのために他ブランチの機能を吸収することも多いため、実質いわゆるdevelopブランチに該当するものであると思っている。

## 履歴
- commit "introduced socket_sever system and corresponded julius order reflected to gui items"
ソケットサーバーのシステムを導入し、別プログラムedu(juliusReceiver, socket client)からの送信を想定して、受信プログラムを作成。
QMLはjulius orderによるw_xxx系のaddやc_003のremoveぐらいには対応するようにした。
