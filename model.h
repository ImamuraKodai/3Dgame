#ifndef _MODEL_H_
#define _MODEL_H_

#include"main.h"
#include"manager.h"
#include"Object.h"

//マクロ定義
#define MODELSIZE (0.0f)

//===================================
//モデルクラス
//===================================
class CModel :public CObject
{
public:
	CModel();
	~CModel();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void WallCollision();
	void GoalCollision();

	/*void HitModel(int nDamage);*/
	static CModel *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType);

	D3DXVECTOR3 GetMove(void);

	D3DXVECTOR3 GetPos(void);

	void ExampleFunction() {
		int value = GetType();
		// m_typeにアクセスできる
	}

protected:
	static LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	//頂点バッファ

private:

	void SetPosition(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType);

	D3DXVECTOR3 m_pos; //位置
	
	D3DXVECTOR3 m_move; //移動量

	D3DXVECTOR3 m_rot; //向き

	D3DXVECTOR3 m_RotDest; //目的の向き

	float distance;	   //距離

	int nCounterState; //ダメージ状態

	int nLife;         //体力　

	bool m_bUse;	   //使っているかどうか
};

#endif
