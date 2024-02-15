#ifndef _CONE_H_
#define _CONE_H_

#include"main.h"
#include"manager.h"
#include"Object.h"

//マクロ定義
#define MAX_CONE  (128)   //オブジェクトの数
#define MAX_CONEMODEL (1)

//============================================
//コーンクラス
//============================================
class CCone :public CObject
{
public:
	CCone();
	~CCone();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CCone *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int Type);
	D3DXVECTOR3 GetPos(void);
	D3DXVECTOR3 GetMove(void);

protected:
	static LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	//頂点バッファ

private:

	D3DXVECTOR3 m_pos; //位置

	D3DXVECTOR3 m_move; //移動量

	D3DXVECTOR3 m_rot; //向き

	D3DXVECTOR3 m_RotDest; //目的の向き

	D3DXMATRIX mtxWorld;	//ワールドマトリックス

	int nIdxShadow;			//対象の影のインデックス(番号)

	float fDirection;  //距離

	int nCounterState; //ダメージ状態

	int nLife;         //体力　

	int m_Type;         //種類

	bool m_bUse;	   //使っているかどうか

	LPD3DXMESH m_pMeshCone;		    //メッシュ(頂点情報)へのポインタ

	LPD3DXBUFFER m_pBuffMatCone;	//マテリアルへのポインタ

	DWORD m_dwNumMatCone = 0;		//マテリアルの数

	LPDIRECT3DTEXTURE9 m_pTexture;	//テクスチャへのポインタ

	CCone* g_aObstacleModel[MAX_CONEMODEL]; //エネミーモデルの種類

	CCone* g_aEnemy[MAX_CONE];            //敵の情報

	int nCntCone;	   //敵のカウント

	int nCntConeModel; //モデルのカウント

	void SetPosition(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int Type); //位置情報
};

#endif 