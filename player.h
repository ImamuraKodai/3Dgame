#ifndef _PLAYER_H_ 
#define _PLAYER_H_ //二重インクルード防止

#include"main.h"
#include"Object2D.h"

class CPlayer : public CObject2D
{
public:

	D3DXVECTOR3 move;  //移動
	D3DXVECTOR3 rot;   //向き
	bool bDisp;        //使っているかどうか
	int nCounterState; //ダメージ状態
	int nAppearCounter;//出現状態
	int nLife;         //体力　

	CPlayer();
	~CPlayer();

	//==========================
	//メンバ関数
	//==========================
	static CPlayer * Create(D3DXVECTOR3 pos, int nType);
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

protected:
	static LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		  //頂点バッファ
	LPDIRECT3DTEXTURE9 m_pTexture[NUM_OBJECT] = {};	  //テクスチャ

private:

	void MovePlayer(void); //プレイヤーの移動

	int m_CounterAnim;								  //アニメーションカウンター
	int m_PatternAnim;								  //アニメーションパターンNo.
};

#endif