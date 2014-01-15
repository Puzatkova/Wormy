#ifndef C_PLAYER_H
#define C_PLAYER_H
#pragma once
#include <hge.h>
#include <hgevector.h>
#include <hgeanim.h>

#define PLAYER_FRICTION 0.95

class c_player
{
	protected:
    static HGE*     hge;
    hgeVector       Position;
    hgeVector       Velocity;
    HTEXTURE        Texture;
    hgeAnimation*   Sprite;
    hgeRect         BoundingBox; //����������  ��� ����������� ������������
    float           Speed;

public:
		c_player(){}
        c_player(const c_player & player){}
        c_player(hgeVector Position, hgeVector Velocity,char* textureName,hgeVector sizeTexture);//�����������
		~c_player();//����������

		bool Update(float delta);
		void Render();

		void        SetVelocity(hgeVector velocity) { Velocity = velocity; };
		void        SetPosition(hgeVector position) { Position = position; };

		void SetAnim(HGE* hge, const char* textureName, hgeVector sizeTexture)
		{
                Texture = hge->Texture_Load("worm1.png");
                Sprite = new hgeAnimation(Texture,2,1,0,0,100,66);
                Sprite->SetHotSpot(sizeTexture.x/2,sizeTexture.y/2);
                Sprite->Play();
        }
	hgeRect     GetBoundingBox() { return BoundingBox; };
    hgeVector   GetPosition() { return Position; };
};


#endif