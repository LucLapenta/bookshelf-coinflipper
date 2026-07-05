# Bookshelf Coinflipper

Recently I have found myself flipping a coin to make simple decisions. It's
simple, flip a coin to decide between two choices when you are unsure about the best coice. If you don't like the result of the coin you just pick the other choice. The
omniscient coin has now revealed your true feelings. 

**There is only one rule:**
only one flip is allowed. You need to either accept or deny the coin, no redos.

I like to use this method for simple low consequence choices like: what should
we eat for lunch? Should I get a white t-shirt or a black one? I wouldn't use
this for major life decisions, but hey who knows?

## The Problem

My issue with relying on this method is that I never have coins lying around anymore. Sure you can use [Google coinflip](https://share.google/LnWpSTpF9ybSHNnuH) or ask Alexa to flip a coin, but I like things that are tactile.

On the other hand, its essentially instant to just generate a random number and assign it to heads or tails, but one of the best parts of flipping a coin is the suspense! There is that moment while the coin is flipping and you are just hanging on by a thread waiting for it to fall. And when that is missing it just does not feel right.

Aside the fact that it would be easiest to just keep more coins around we are going to build a hardware/software device to flip a coin and add some of the tactileness that the real thing gives you.

## The Prototype

This device uses three key components to create the coinflipper.

1. xiao rp2040 microcontroller - https://a.co/d/08oApQ3Z
    this is the main controler of the whole device. It should be easy to work with and have the enough memory, processor speed, and interfaces.
2. AdaFruit SSD1306 128x64 OLED LED display - https://a.co/d/0h02fWmf
    This is display for the system where we show things like helper text to guide the user through the process and showing coin animations while its running.
3. 16mm momentary button - https://a.co/d/02fcVPr8
    The goal with this button is to have a nice big button with a satifying press action. this needs to compete with the action of flipping the coin in the air so it better be good.

## Building

To build the project for arduino based boards, follow the setup instructions in the [arduino readme](./arduino/readme.md).

To create or modify image sequences to display on the board follow the instructions in the [assets readme](./assets/readme.md).

## TODO

- [ ] build project enclosure
- [ ] add battery system
- [ ] add zephyr support
