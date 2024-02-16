#ifndef _OBJECT_H_ 
#define _OBJECT_H_ //二重インクルード防止

#include<windows.h>
#include"d3dx9.h" //描画処理に必要

#define MAX_OBJECT (128) //敵の総数
#define NUM_OBJECT (4)   //オブジェクトの種類

//オブジェクトクラス
class CObject
{
public:

	//プレイヤーの状態
	typedef enum
	{
		TYPE_NOMAL,
		TYPE_MODEL, //出現状態
		TYPE_CONE,  //コーン
		TYPE_GOAL,  //ゴール
		PLAYERSTATE_MAX
	}TYPE;

	CObject();  //コンストラクタ
	virtual ~CObject(); //デストラクタ

	virtual HRESULT Init(void) = 0; //ポリゴンの初期化処理
	virtual void Uninit(void) = 0;  //ポリゴンの終了処理
	virtual void Update(void) = 0;  //ポリゴンの更新処理
	virtual void Draw(void) = 0;    //ポリゴンの描画処理

	void SetPosition(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType); //位置と種類	
	TYPE GetType() const { return m_type; }

	static void ReleaseAll(void); //すべてのオブジェクトの破棄
	static void UpdateAll(void);  //すべての更新処理
	static void DrawAll(void);    //すべての描画処理

protected:
	void Release(void); //オブジェクトの破棄
	TYPE m_type;

public:
	static CObject *m_apObject[MAX_OBJECT]; //オブジェクトの総数
	static int m_nNumAll;					//オブジェクト総数
	int m_nID;								//自分自身のID
	D3DXVECTOR3 m_pos;						//自分の位置

private:
};

#endif