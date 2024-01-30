#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "main.h"
#include "manager.h"
#include "Object.h"

//カメラクラス
class CCamera
{
public:
	CCamera();
	~CCamera();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetCamera(void);

private:
	D3DXMATRIX m_mtxView;		//ビューマトリックス
	D3DXMATRIX m_mtxProjection;	//プロジェクションマトリックス
	D3DVIEWPORT9 m_viewport;    //ビューポート
	D3DXVECTOR3 m_posV;			//視点
	D3DXVECTOR3 m_posR;			//注視点
	D3DXVECTOR3 m_posU;			//上方向ベクトル
	D3DXVECTOR3 rot;			//向き
	D3DXVECTOR3 playerpos;	    //プレイヤーの場所
	D3DXVECTOR3 posVDest;		//目的の視点
	D3DXVECTOR3 posRDest;		//目的の注視点
	D3DXVECTOR3 posMove;		//移動量
	float fDistance;			//距離
};

#endif
