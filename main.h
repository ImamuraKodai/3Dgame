#ifndef _MAIN_H_ 
#define _MAIN_H_ //二重インクルード防止

//DirectXの初期設定
#include<windows.h>
#include"d3dx9.h"
#define DIRECTINPUT_VERSION (0x0800) //
#include "dinput.h" //
#include "xaudio2.h"

//ライブラリのリンク
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"dinput8.lib") //入力処理に必要

//マクロ定義
#define SCREEN_WIDTH (1280)													//ウインドウの幅
#define SCREEN_HEIGHT (720)													//ウインドウの高さ
#define FVF_VERTEX_2D (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)			//2Dテクスチャ
#define FVF_VERTEX_3D (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_DIFFUSE|D3DFVF_TEX1) //3Dテクスチャ


//頂点情報[2D]の構造体を定義
typedef struct
{
	D3DXVECTOR3 pos; //頂点座標
	float rhw;       //rhw
	D3DCOLOR col;    //カラー
	D3DXVECTOR2 tex; //頂点バッファ

}VERTEX_2D;

//頂点情報[3D]の構造体を定義
typedef struct
{
	D3DXVECTOR3 pos; //頂点座標
	D3DXVECTOR3 nor; //法線ベクトル
	D3DCOLOR col;    //頂点カラー
	D3DXVECTOR2 tex; //テクスチャ座標
}VERTEX_3D;

//前方宣言
class CRenderer;
class CObject;

//プロトタイプ宣言
//CRenderer *GetRenderer(void);
CObject **GetObject(void);

#endif