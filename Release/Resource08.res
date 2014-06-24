Texture background
{
 filename=bg.jpg
}
Sprite bgSprite
{
 texture=background
 rect=0, 0, 512, 512
}

Texture sheet
{
 filename=sheet.png
}
Animation coin
{
 texture=sheet
 rect=0, 0, 32, 32
 frames=5
 fps=8.0
 mode=FORWARD,LOOP
}

Font font1
{
 filename=font1.fnt
}

Sound coinSound
{
 filename=coin.ogg
}

Sprite sparkles
{
 texture=sheet
 rect=0, 40, 32, 32
 blendmode=ALPHAADD
}
Particle coinCollected
{
 filename=particle.psi
 sprite=sparkles
 fps=50.0
}
