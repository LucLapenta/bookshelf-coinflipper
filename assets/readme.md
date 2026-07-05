## Setting up images for animations

1. To create images for animation, start with a gif of a coinflipping animation. I uses [this one](https://tenor.com/view/pokemon-tcg-pikachu-pokemon-tcg-pokemon-the-trading-card-game-gif-5781129915881131114)

2. Then resize it to make sure it fits on the screen (128x64 pixels). I used a size of 40x40 and [ezgif](https://ezgif.com/) to resize the file.

3. Next split the gif into frames using ffmepg:

`ffmpeg -i ./<mygif>.gif -vsync 0 ./coinflip_frame_%d.png`

*Possibly I could have also resized the gif with ffmpeg, but could not find a simple method that also kept the background transparent.*

4. convert the images into raw bytes using https://javl.github.io/image2cpp/
    - you can upload all images in a sequence and get the exported arduino code or bytes to copy/paste back to your file
    - if you are using a board with low RAM, store the byte arrays as PROGMEM and include in the main `.ino` sketch. For the Xiao rp2040, we have plenty of ram for this small image sequence, so I stored the files in a seperate header to keep the main sketch file easier to read.

