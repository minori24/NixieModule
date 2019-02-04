# nix module IN-12 Technical Details

## Specs
Compatible tube
 - IN-12A/B, IN-15

Driven Cathodes
 - 10 Digits + 1 Dot

Backlight
 - RGB LED Backlight

Dimension
 - 20mm x 40mm (Board only)

Supply Voltage
 - 5V

Nixie Tube Cathode Voltage
 - 180V

 I2C Max Speed
  - 400kHz

## I2C Command Protocol
nix modules is using PCA9685PW for I2C interface and to control PWM signals. Please refer datasheet for technical details.