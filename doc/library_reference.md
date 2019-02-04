# Arduino Library Reference

## コンストラクタと初期化

コンストラクタ
```
NixieModule_IN_12 nix0 = NixieModule_IN_12(uint8_t addr);
NixieModule_IN_14 nix1 = NixieModule_IN_14(uint8_t addr);
```
`uint8_t addr`

モジュール裏のショートジャンパで設定したアドレスを渡します。複数のモジュールを同じバスに接続する場合にアドレスが重複しないよう注意して下さい。


```
void init()
```
モジュールを初期化します。


## 数字の表示
```
void setNumber(uint8_t number, uint8_t step)
```

ニキシー管に表示する数字を設定します。

`uint8_t number`

表示したい数値を指定します。0-9の値です。

`uint8_t step`

クロスフェードやシャッフル表示の場合、現在表示されている数字から新しく設定した数字に切り替わるまでのステップ数を指定します。これらのエフェクトを使用しない場合(transition mode = TMODE_NORMAL)、指定した数値に関わらず常にstep = 1です。

```
void update()
```
`setNumber()` で指定した数字を表示します。stepで指定した回数呼び出すことでクロスフェードやシャッフルのエフェクトをかけながら数字を切り替えます。

```
nix0.setNumber(7, 100); //'7'を表示, 100stepで変化
for (int i=0; i<100; i++){
    nix0.update();
    delay(2);
}
```
数字が切り替わるスピードはstepの回数と `update()` を呼び出す間隔で決まります。`delay()`を入れて適宜調整して下さい。

## エフェクト設定
```
void setTransitionMode(uint8_t mode)
```
`uint8_t mode`

数字の切り替えで使用するエフェクトを指定します。

`TMODE_NORMAL` : エフェクト無し

`TMODE_FADE` : クロスフェード

`TMODE_SHUFFLE` : シャッフル

## 明るさの調整
```
void setBrightness(uint8_t b)
```

`float b`

明るさを 0 - 1.0 の間で指定します。


## I2C Command Protocol
ライブラリを使用せず直接制御する場合のI2CコマンドはPCA9685PWのデータシートを参照して下さい。PCA9685PWの出力ピンの出力とニキシー管の接続は回路図を参照。

# RGB LED
LEDの制御にはAdafruit NeoPixel Library等のライブラリが使えます。

Adafruit Neopixel Library on GitHub

https://github.com/adafruit/Adafruit_NeoPixel

いまさらNeo Pixelまとめ - 滴了庵日録

https://lipoyang.hatenablog.com/entry/20180106/p1

# Future Candidates

