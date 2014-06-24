//
//#include <hge.h>
//#include <hgesprite.h>
//#include <hgefont.h>
//#include <hgeparticle.h>
//#include <hgevector.h>
//
//HGE *hge=0;
//
////Background
//HTEXTURE    g_tBackground =0;
//hgeSprite*  g_sBackground = NULL;
//
//
//
//
//hgeSprite			*spr;
//hgeSprite			*spt;
//hgeFont				*fnt;
//hgeParticleSystem	*par;
//
////текстурка
//HTEXTURE			tex;
//
////звучок
//HEFFECT				snd;
//
//float x=100.0f, y=100.0f;
//float dx=0.0f, dy=0.0f;
//
//const float speed=10;
//const float friction=0.99f;
//
////ф-uя для звучка (в проекте)
//
//void boom()
//{
//
//	int pan=int((x-400)/4);
//	float pitch=(dx*dx+dy*dy)*0.0005f+0.2f;
//	
//	hge->Effect_PlayEx(snd,100,0,1.0,true);//   ?
//}
//
//bool FrameFunc()
//{
//	float dt=hge->Timer_GetDelta();
//
//	// Process keys
//	if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
//	if (hge->Input_GetKeyState(HGEK_LEFT)) dx-=speed*dt;
//	if (hge->Input_GetKeyState(HGEK_RIGHT)) dx+=speed*dt;
//	if (hge->Input_GetKeyState(HGEK_UP)) dy-=speed*dt;
//	if (hge->Input_GetKeyState(HGEK_DOWN)) dy+=speed*dt;
//
//
//	// Do some movement calculations and collision detection	
//	
//	
//	
//
//	// Update ///////////////////////
//	dx*=friction; dy*=friction; x+=dx; y+=dy;
//	boom();
//	if(x>784) {x=784-(x-784);dx=-dx;}
//	if(x<16) {x=16+16-x;dx=-dx;}
//	if(y>584) {y=584-(y-584);dy=-dy;}
//	if(y<16) {y=16+16-y;dy=-dy;}
//	par->info.nEmission=(int)(dx*dx+dy*dy)*2;
//	par->MoveTo(x,y);
//	par->Update(dt);
//
//	return false;
//}///////////////
//
//bool RenderFunc()////////////////render/////////////
//{
//	
//	// Render graphics
//	hge->Gfx_BeginScene();
//	hge->Gfx_Clear(0);
//	g_sBackground->Render(0,0);
//	par->Render();
//	spr->Render(x, y);
//	
//
//	fnt->printf(5, 5, HGETEXT_LEFT, "dt:%.3f\nFPS:%d (constant)", hge->Timer_GetDelta(), hge->Timer_GetFPS());
//	hge->Gfx_EndScene();
//
//	return false;
//}
////////////////////////////////////////////////
//
//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
//{
//	hge = hgeCreate(HGE_VERSION);
//
//	hge->System_SetState(HGE_LOGFILE, "laba_HGE.log");
//	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
//	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
//	hge->System_SetState(HGE_TITLE, "Alice in Wonderland");
//	hge->System_SetState(HGE_FPS, 100);
//	hge->System_SetState(HGE_WINDOWED, true);
//	hge->System_SetState(HGE_SCREENWIDTH, 800);
//	hge->System_SetState(HGE_SCREENHEIGHT, 600);
//	hge->System_SetState(HGE_SCREENBPP, 32);
//
//	
//
//	if(hge->System_Initiate()) {
//
//		// Load sound and texture
//		snd=hge->Effect_Load("meow.wav");
//		tex=hge->Texture_Load("kitty.png");
//		g_tBackground = hge->Texture_Load("texture.jpg");
//
//		if(!snd || !tex)
//		{
//			
//			hge->System_Shutdown();
//			hge->Release();
//			return 0;
//		}
//		
//		g_sBackground = new hgeSprite (g_tBackground, 0, 0, 1280, 720);
//
//		// Create and set up a sprite
//		spr=new hgeSprite(tex, 0, 0, 96, 96);
//		spr->SetHotSpot(48,48);
//
//		// Load a font
//		fnt=new hgeFont("font1.fnt");
//
//		// Create and set up a particle system
//		spt=new hgeSprite(tex,96,96, 96, 96);
//		//spt->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
//		spt->SetHotSpot(30,30);
//		par=new hgeParticleSystem("trail.psi",spt);
//		//par=new hgeParticleSystem("tail.png",spt);
//		par->Fire();
//
//		// Let's rock now!
//		hge->System_Start();
//
//		// Delete created objects and free loaded resources
//		delete par;
//		delete fnt;
//		delete spt;
//		delete spr;
//		hge->Texture_Free(tex);
//		hge->Effect_Free(snd);
//	}
//
//	// Clean up and shutdown
//	hge->System_Shutdown();
//	hge->Release();
//	return 0;
//}
//




#include <hge.h>
#include <hgesprite.h>
#include <hgevector.h>
#include <hgefont.h>
#include <hgeresource.h>
#include "bot.h"
#include "player.h"
#include <ctime>
#include <vector>
#include <list>
#include <iostream>
#include <string>

using namespace std;
#define BACKGROUND_SCROLLING_SPEED  0.105f//скорость движения
HGE *hge = NULL;
c_player*   Player1  = NULL;
hgeResourceManager* txt;
hgeFont* font1;

//Background
HTEXTURE    tm_Background  = 0;
HTEXTURE    t_Branch  = 0;
HTEXTURE    t_Background  = 0;
HTEXTURE tLose_Background = 0;
HTEXTURE tWon_Background = 0;

vector<Apple*> apple;
vector<Raven*> raven;

hgeSprite*  sm_Background  = NULL;
hgeSprite*  s_Branch = NULL;
hgeSprite*  s_Background  = NULL;
hgeSprite* sLose_Background=NULL;
hgeSprite* sWon_Background=NULL;

void Save();
void Load();
void StartNew();
bool L_RenderFunc();
bool L_FrameFunc();
bool W_FrameFunc();
bool W_RenderFunc();
bool FrameFunc();
bool RenderFunc();
bool FrameMenu();

hgeVector   g_vBGPosition = hgeVector(0,0);
float dt=0;
float freq=0.9;
int score=0, a=0, lives=3;





void Save()
{
	FILE* saves;
	if((saves =fopen("saves.txt", "w"))!=NULL);
	{
		fprintf(saves,"%d ", score);
		fprintf(saves, "%d ", a);
		
		fprintf(saves, "%d ", lives);
		fprintf(saves, "%f ", dt);
		fprintf(saves, "%f ", freq);
		fclose(saves);
	}
}

void Load()
{
	FILE* saves;
	if((saves =fopen("saves.txt", "r"))==0)
		return;
	else
	{
		fscanf(saves,"%d", &score);
		fscanf(saves, "%d", &a);
		fscanf(saves, "%d", &lives);
		fscanf(saves, "%f", &dt);
		fscanf(saves, "%f", &freq);
		fclose(saves);
	}
}


void StartNew()
{
        score=0;
        lives=3;
        dt=0;
        freq=0.9;
        Player1->SetPosition(hgeVector(100,268));
        Player1->SetVelocity(hgeVector(0,0));
		hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
		hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
}



bool Lose_RenderFunc(){

        hge->Gfx_BeginScene();
	    hge->Gfx_Clear(0);
        sLose_Background->Render(0,0);
        font1->SetScale(2.5);
        font1->SetColor(ARGB(255,204,0,0));
		font1->printf(250,200, HGETEXT_LEFT,"YOU LOSE");
		font1->SetScale(1.2);
        font1->SetColor(ARGB(255,0,191,255));
        font1->printf(5,570, HGETEXT_LEFT,"Press ESC to exit");
        hge->Gfx_EndScene();
        return false;
}

bool Lose_FrameFunc()
{
        if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
    return false;
}

bool Win_FrameFunc()
{        
        if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
    return false;
}

bool Win_RenderFunc(){

        hge->Gfx_BeginScene();
		hge->Gfx_Clear(0);
        sWon_Background->Render(0,0);
		font1->SetScale(2.5);
        font1->SetColor(ARGB(255,51,0,255));
		font1->printf(250,200, HGETEXT_LEFT,"YOU WON");
		font1->SetScale(1.2);
        font1->SetColor(ARGB(255,0,191,255));
        font1->printf(5,570, HGETEXT_LEFT,"Press ESC to exit");
        hge->Gfx_EndScene();
        return false;
}


bool FrameMenu()
{
	if (hge->Input_GetKey()==HGEK_SPACE)
	{
		StartNew();
	}
	if (hge->Input_GetKey()==HGEK_C)
	{
		Load();
		hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
		hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	}
	if (hge->Input_GetKey()==HGEK_S)
	{
		Save();
	}
	if (hge->Input_GetKeyState(HGEK_ESCAPE))
	{
		Save();
		return true;
	}
	return false;
}

bool RenderMenu()
{
	hge->Gfx_BeginScene();
    hge->Gfx_Clear(0);
	sm_Background->Render(0,0);
	hge->Gfx_EndScene();
	return false;

}


bool FrameFunc()
{
	float delta = hge->Timer_GetDelta();
	//Background
	if(g_vBGPosition.x < 800) g_vBGPosition.x += BACKGROUND_SCROLLING_SPEED;
	else g_vBGPosition  = hgeVector(0,0);
    //Check whether escape has been pressed or not
	Player1->Update(delta);
	::dt+=hge->Timer_GetDelta();
        if(dt>freq)
		{

            dt=0;
			apple.push_back(new Apple(hgeVector(900,rand()%600+40), hgeVector(5,0),"apple.png",hgeVector(50,54)));
			raven.push_back(new Raven(hgeVector(900,rand()%600+40), hgeVector(5,0),"bird1.png",hgeVector(169,120)));
        }
			for(vector<Apple*>::iterator it=apple.begin();it!=apple.end();)
        {
                if((*it)->GetBoundingBox().Intersect(&Player1->GetBoundingBox()))
                {
					delete (*it);
                        it = apple.erase(it);
                        Player1->SetVelocity(hgeVector(0,0));
						score+=10;
                        
                }
                else it++;
						 }


			for(vector<Raven*>::iterator it=raven.begin();it!=raven.end();)
        {
                if((*it)->GetBoundingBox().Intersect(&Player1->GetBoundingBox()))
                {
					delete (*it);
                        it = raven.erase(it);
						Player1->SetPosition(hgeVector(100,268));
                        Player1->SetVelocity(hgeVector(0,0));
						lives--;
                        if(lives==0)
                        {
                                hge->System_SetState(HGE_FRAMEFUNC, Lose_FrameFunc);
                                hge->System_SetState(HGE_RENDERFUNC, Lose_RenderFunc);

                        }
                        
                }
                else it++;
						 }


        for(int i=0;i<apple.size();i++)
		{
                int count=0;
                if(!apple[i]->Update(delta)){
                        for(vector<Apple*>::iterator j=apple.begin();j!=apple.end();j++,count++)
                                if(count==i){
                                        apple.erase(j);
                                        break;
                                }
                 }
        }

		 for(int i=0;i<raven.size();i++)
		{
                int count=0;
                if(!raven[i]->Update(delta)){
                        for(vector<Raven*>::iterator j=raven.begin();j!=raven.end();j++,count++)
                                if(count==i){
                                        raven.erase(j);
                                        break;
                                }
                 }
        }


		  if(score==500)
                {
                        freq-=0.2;
                        score++;
                        
                                hge->System_SetState(HGE_FRAMEFUNC, Win_FrameFunc);
                                hge->System_SetState(HGE_RENDERFUNC, Win_RenderFunc);
                        
                }
        
        
		
	if (hge->Input_GetKey()==HGEK_M)
	{
		hge->System_SetState(HGE_FRAMEFUNC, FrameMenu);
		hge->System_SetState(HGE_RENDERFUNC, RenderMenu);
	}
       
		if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
		return false;
}
 
bool RenderFunc()
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	s_Background->Render(0,0);
	s_Branch->Render(0,165);
	s_Branch->Render(780,165);
    if(g_vBGPosition.x > -982)  s_Branch->Render(g_vBGPosition.x + 982 + 800, 0);
	Player1->Render();
	font1->SetScale(1.2);
    font1->SetColor(ARGB(255,204,0,0));  
	font1->printf(720, 5, HGETEXT_RIGHT, "Score: %d", score);
	font1->SetColor(ARGB(255,153,255,0));  
	font1->printf(720, 35, HGETEXT_RIGHT, "Lives: %d", lives);

	for(int i=0;i<apple.size();i++)
             apple[i]->Render();
	for(int i=0;i<raven.size();i++)
             raven[i]->Render();

	hge->Gfx_EndScene();
	return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_FRAMEFUNC, FrameMenu);
    hge->System_SetState(HGE_RENDERFUNC, RenderMenu);
    hge->System_SetState(HGE_WINDOWED, true);
    hge->System_SetState(HGE_USESOUND, false);
    hge->System_SetState(HGE_FPS, HGEFPS_VSYNC);
    hge->System_SetState(HGE_TITLE, "Wormy");
	if(hge->System_Initiate())
{
	
	txt = new hgeResourceManager("Resource08.res");

    //Background
	tm_Background = hge->Texture_Load("menuAS.jpg");
	sm_Background = new hgeSprite(tm_Background, 0, 0, 800, 600);

    t_Branch = hge->Texture_Load("branch.png");
    t_Background  = hge->Texture_Load("background.jpg");
 
    s_Branch   = new hgeSprite(t_Branch, 0, 0, 780, 302);
    s_Background   = new hgeSprite(t_Background, 0, 0, 800, 600);

	tLose_Background = hge->Texture_Load("lose.jpg");
	sLose_Background = new hgeSprite(tLose_Background, 0, 0, 800, 600);

	tWon_Background = hge->Texture_Load("won.png");
	sWon_Background = new hgeSprite(tWon_Background, 0, 0, 600, 575);
	font1 = txt->GetFont("font1");

    g_vBGPosition   = hgeVector(982, 0);
 


	Player1 = new c_player(hgeVector(10, 268), hgeVector(5,0),"worm1.png",hgeVector(100,66));
	apple.push_back(new Apple(hgeVector(900,rand()%600+40), hgeVector(5,0),"apple.png",hgeVector(50,54)));//700
	raven.push_back(new Raven(hgeVector(900, rand()%600+40), hgeVector(5,0),"bird1.png",hgeVector(169,120)));//700
    hge->System_Start();

	delete Player1;
	delete txt;

//И, конечно, удалять их после
//Cleanup..
    hge->Texture_Free(t_Branch);
    hge->Texture_Free(t_Background);
	hge->Texture_Free(tLose_Background);
    hge->Texture_Free(tWon_Background);
	hge->Texture_Free(tm_Background);
 
    delete s_Branch;
    delete s_Background;
	delete sm_Background;
    delete sLose_Background;
    delete sWon_Background;

	for(vector<Apple*>::iterator k=apple.begin();k!=apple.end();k++)
                {
                    delete (*k);
                }
                apple.clear();

	for(vector<Raven*>::iterator k=raven.begin();k!=raven.end();k++)
                {
                    delete (*k);
                }
                raven.clear();
        
}
s_Branch->Render(g_vBGPosition.x,g_vBGPosition.y);
s_Background->Render(0,0);
if(g_vBGPosition.x > -1) s_Branch->Render(g_vBGPosition.x - 982 - 800, 0);

hge->System_Shutdown();
hge->Release();
 
    return 0;
}
