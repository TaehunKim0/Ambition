#pragma once

#define SAFE_DELETE(x) if(x) {delete x; x = nullptr;}

#include<Windows.h>
#include<stdio.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<string>
#include<list>
#include<vector>
#include<map>
#include<queue>
#include<time.h>

#include"Singleton.h"
#include"Time.h"
#include"App.h"
#include"Input.h"
#include"GameObject.h"
#include"CollisionMgr.h"
#include"ObjectMgr.h"
#include"GamDok.h"
#include"Texture.h"
#include"TextureMgr.h"
#include"Sprite.h"
#include"Animation.h"
#include"CommandMgr.h"

#include"Controller.h"
#include"PlayerController.h"
#include"AIController.h"
#include"TimeUI.h"
#include"Fighter.h"
#include"FightMgr.h"
#include"CharSelect.h"

