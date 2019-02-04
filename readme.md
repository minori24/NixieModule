# nix module: mini size nixie tube driver modules

## nix module(仮)
nix moduleはニキシー管の制御に必要な部品を2x4cmの小さな基板に詰め込んだモジュールです。高圧電源の制御や煩雑なダイナミック点灯のコードを考える必要もなく、マイコンとI2Cで接続するだけでニキシー管の制御が可能です。Arduinoライブラリと組み合わせることでシンプルにニキシー管を点灯させることができます。

最大16桁をI2C経由で連結させ、各桁を独立して制御できます。すべての数字でフェードイン・フェードアウト、シャッフルなどのエフェクトが可能です。またRGB LEDによるバックライトもついています。


## Features
- 2x4cm
- I2Cインタフェース(プルアップ抵抗実装済み)
- ハードウェアPWM制御
- RGBバックライト(WS2812B互換 SK6812mini)
- スタティック点灯でシンプルな回路構成

## Arduino Library
ライブラリは[こちら]()にあります。

使用方法については[Getting Started](doc/getting_started.md)を参照して下さい。

## Open Design
回路図、BOM、PCB DesignをこのGithub Repoで公開しています。KiCadで自由に編集可能です。

PWM Driver is PCA9685PW

NPN Transistor is MMBTA42

LED is SK6812mini (WS2812B-ish 3535 serial RGB LED)

PWMドライバはサーボモータの制御によく使われるPCA9685PW、RGB LEDはシリアル接続LEDの小型版なので、Arduino以外のマイコンボードやRaspberry Piによる制御も簡単に行えます。