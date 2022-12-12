# Corne keyboard layout

`rpbaptist`'s excellent and comprehensive keymap is far,
far more than I would want from a collection of layouts,

As such I've decided to take his work as a starting point;
it's beautifully crafted, and well-layed out and documented,
so this was a no-brainer.

I've "stripped out" the things I don't need,
such as the gaming layer,
and replaced the Colemak layer with QWERTY.
I say "stripped out" the gaming layer, but what I really mean is
that I've replaced it with a Workman layer instead
(one day I may even learn it).

Finally, as `rpbaptist` himself said:

> Many thanks to foostan for the keyboard, all QMK contributors and drashna specifically for his work on this keyboard.

## Layers

### QWERTY

I'm a big fan of `rpbaptist`'s use of tap/hold keys, but I think it could be taken further.

Something that I explored working with the MiniDox and Miuni32 is putting modifiers
on the home row as tap/hold keys. This is something that *hasn't* made it to this layout,
but it's laid the foundation for some small changes to `rpbaptist`'s work.

Considering that there is a chance you may want to spend some time interacting with the numpad,
I think it makes more sense to activate the numpad layer with something on the left hand home row.
I've elected to make that 'A'.

I've elected to leave 'escape' where it is, as that's a very natural positive for it,
and had intended to replace 'left control/bracket' with shift, but, as they already
live under the thumbs, I've placed 'non-US backslash' there instead
(as this is a fairly normal ISO location for '\').
On the other side of the board, in homage to my long-term love of the Zeal60,
I've put 'grave' ('`') on the far left. Normally your pinky would hit a shift first,
but, once again, these live under the thumbs.

Now, unlike `rpbaptist`, I'm a right thumb space lover.
The problem, however, is that I would quite like to have enter there too.
In reality this isn't **awful**, because I've elected to place enter on the NUMPAD layer.
Yeah, okay, this is a bit weird. My thinking is that it's a handy thing to have in a numpad,
as occasionally one may be forced to type out a large number of newline-delimited numerical sequences,
and moving back to the default layer to do so every time would become a pain.
The downside, of course, is that you have to change to the numpad layer every time you want to hit enter.
Some would argue that I'm prioritising an edge case to spite myself,
and you might be right. I'll figure it out properly later ;)

I've fiddled around with the thumbs a little, but not much.
Like I said earlier, I like the space under the right thumb. So what goes on the left thumb?
TAB. I don't know why, but the idea of having a tab under the left thumb just feels... right?
Let's see how that goes.

Everything else I've left alone (which is a bit like saying "I demolished the house, but other than I didn't do anything.")

To summarise:

- Holding SHIFT while tapping BACKSPACE will output DEL. Holding both SHIFT keys will output SHIFT+DEL.
- I don't know about you but "lower" and "raise" don't mean that much to me. 
  I named my layers `SYM`, short for symbols and `NAV`, short for navigation.
  Holding the key will activate the layer for as long as it is held, double tapping it will switch to it.
  Single tapping it once will switch to main layer again.

### SYM

This is another one that's been radically affected.

This layer is based, loosely, on [Pascal Getreuer's](https://getreuer.info/posts/keyboards/symbol-layer/index.html)
brilliant introspection on what a symbol layer should be.

I *largely* agree with him, with some exceptions.

- Is it really easier for you to tap one key for :: instead of pressing : twice?
  Especially considering it's under right index home?
- Why is colon on the symbol row at all? 'shift + ;' so much harder than 'symbol + j'???
- Similarly, I definitely don't type '../' enough to want it on a special row.
- '?' is easily accessible from the default layer
- There's no "£" TT_TT
- '@' is accessible from the default layer
- Why isn't there an underscore?
- Why is there a '.' here at all?
- Why is there a "'"?????

Instead, I'm 

- placing underscore under the right index
- moving '~' to the right little finger
- removing the '\'
- removing the '?'
- removing the '@'
- removing the '.'
- removing the "'"
- putting a '£' somewhere

Take a look at the keymap for details!

### NAV

I don't even understand a little why this doesn't use vim, but there we go.
I've changed this immediately, and moved home etc. to row beneath,
matching down/up to j/k, and home/end to h/l.

I've gotten rid of all the tab stuff here, and stripped out anything I don't think too useful for me.

Loved the left-hand side, but decided to put 6 F keys on each row.

### UTIL

I thought this was a great layer. Left entirely alone.

### NUMPAD

This gives access to a numpad on the right half with some additional symbols I find useful when using the numpad.

## RGB

I took `rpbaptist`'s work wholesale here. 2bamboozle4me.

## Building

`qmk compile -kb crkbd/rev1/common -km beaver`
`qmk flash -kb crkbd/rev1/common -km beaver`

and don't forget the right bootloader...

`... -bl dfu-split-[right/left]`

## Notes

> I use several OLED slave side images, depending on the keycaps I am using. These also determine the default LED color and underglow.
 
add `THEME=` and the string related to the theme from the list below
 
> Current supported themes are:
> 
> - godspeed
> - laser
> - pulse
