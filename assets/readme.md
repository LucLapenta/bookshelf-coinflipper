## Setting up images for animations

1. To create images for animation, I found a gif of a coin flipping.

2. Then resize it to make sure it fits on the screen (128x64 pixels). I used 40x40 size and https://ezgif.com/ to resize.

3. split the gif into frames using ffmepg:

`ffmpeg -i ./<mygif>.gif -vsync 0 ./coinflip_frame_%d.png`

*Possibly I could have also resized the gif with ffmpeg, but could not find a simple method that also kept the background transparent.*

4. convert the images into raw bytes using https://javl.github.io/image2cpp/
    4.1 you can upload all images in a sequence and get the exported arduino code or bytes to copy/paste back to your file

