#pragma once

using namespace std;

#define SAFE_DELETE(x) if(x) {delete x; x = nullptr;} 


#include<Windows.h>
#include<stdio.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<iostream>
#include<string>
#include<time.h>
#include<map>
#include<vector>
//

#include"Singleton.h"
#include"Application.h"
#include"Renderer.h"

#include"GameObject.h"
#include"Texture.h"
#include"Sprite.h"
#include"TextureMgr.h"
#include"SceneDirector.h"
#include"Animation.h"
#include"FightObject.h"
#include"FightMgr.h"
#include"Player.h"