//==========================================================
//
//モデルを出力する処理[model.cpp]
//Aoutor:今村晃大
//
//==========================================================
#include "model.h"
#include "input.h"
#include "camera.h"
#include "Object.h"
#include "3Dobject.h"
#include "cone.h"
#include "goal.h"

//グローバル変数
LPD3DXMESH g_pMeshModel = NULL;      //メッシュ(頂点情報)へのポインタ
LPD3DXBUFFER g_pBuffMatModel = NULL; //マテリアルへのポインタ
DWORD g_dwNumMatModel = 0;           //マテリアルの数
D3DXMATRIX g_mtxWorldModel;          //ワールドマトリックス
int g_nIdxShadow = -1;               //対象の影のインデックス(番号)

//================================================================
//静的メンバ関数
//================================================================
LPDIRECT3DVERTEXBUFFER9 CModel::m_pVtxBuff = NULL; //頂点バッファのポインタ

//==============================================================
//コンストラクタ
//==============================================================
CModel::CModel()
{
	m_type = TYPE_MODEL;
}

//==============================================================
//デストラクタ
//==============================================================
CModel::~CModel()
{

}

//==============================================================
//生成処理
//==============================================================
CModel* CModel::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType)
{
	//モデルのポインタ
	CModel* pModel;

	//3Dオブジェクトの生成
	pModel = new CModel;

	//3Dオブジェクトの初期化処理
	pModel->Init();

	//3Dオブジェクトの位置
	pModel->SetPosition(pos, rot, nType);

	//値を返す
	return pModel;
}

//==================================================================
//モデルの位置設定
//==================================================================
void CModel::SetPosition(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType)
{
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_3D *pVtx; //頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報のポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定	
	pVtx[0].pos = D3DXVECTOR3(-MODELSIZE, MODELSIZE, 0);
	pVtx[1].pos = D3DXVECTOR3(MODELSIZE, MODELSIZE, 0);
	pVtx[2].pos = D3DXVECTOR3(-MODELSIZE, -MODELSIZE, 0);
	pVtx[3].pos = D3DXVECTOR3(MODELSIZE, -MODELSIZE, 0);

	//法線ベクトルの設定
	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//頂点カラーの設定
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	if (m_bUse == false)
	{//使われない場合

		nType = nType;

		m_pos = pos;

		m_rot = rot;

		m_bUse = true; //使用している状態にする
	}

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

//==============================================================
//初期化処理
//==============================================================
HRESULT CModel::Init(void)
{
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//Xファイルの読み込み
	if (FAILED(D3DXLoadMeshFromX("data\\MODEL\\airplane000.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_pBuffMatModel,
		NULL,
		&g_dwNumMatModel,
		&g_pMeshModel)))
	{
		return E_FAIL;
	}

	//初期化処理
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);      //位置
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//移動
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//向き
	m_RotDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);  //目的の向き
	m_bUse = true;                              //使っているかどうか

	return S_OK;
}

//======================================================================
//終了処理
//======================================================================
void CModel::Uninit(void)
{
	//メッシュの破棄
	if (g_pMeshModel != NULL)
	{
		g_pMeshModel->Release();
		g_pMeshModel = NULL;
	}

	//マテリアルの破棄
	if (g_pBuffMatModel != NULL)
	{
		g_pBuffMatModel->Release();
		g_pBuffMatModel = NULL;
	}
}

//=======================================================================
//更新処理
//=======================================================================
void CModel::Update(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice(); //デバイスの取得

	//プレイヤーの移動
	CInputKeyboard * pInputKeyboard;

	//キーボードの取得
	pInputKeyboard = CManager::GetKeyboard();

	if (pInputKeyboard->GetPress(DIK_A) == true)
	{//Aキーが押された

		if (pInputKeyboard->GetPress(DIK_W) == true)
		{//左上移動
			m_pos.x += sinf(-D3DX_PI *0.75f)*2.0f;
			m_pos.z -= cosf(-D3DX_PI *0.75f)*2.0f;
			m_rot.y = D3DX_PI * 0.75f;
		}

		else if (pInputKeyboard->GetPress(DIK_S) == true)
		{//左下移動
			m_pos.x += sinf(-D3DX_PI *0.25f)*2.0f;
			m_pos.z -= cosf(-D3DX_PI *0.25f)*2.0f;
			m_rot.y = D3DX_PI * 0.25f;
		}

		else
		{//左移動
			m_pos.x += sinf(-D3DX_PI *0.5f)*2.0f;
			m_rot.y = D3DX_PI * 0.5;
		}
	}

	else if (pInputKeyboard->GetPress(DIK_D) == true)
	{//Dキーが押された

		if (pInputKeyboard->GetPress(DIK_W) == true)
		{//右上移動
			m_pos.x += sinf(D3DX_PI *0.75f)*2.0f;
			m_pos.z -= cosf(D3DX_PI *0.75f)*2.0f;
			m_rot.y = D3DX_PI * -0.75f;
		}

		else if (pInputKeyboard->GetPress(DIK_S) == true)
		{//右下移動
			m_pos.x += sinf(D3DX_PI *0.25f)*2.0f;
			m_pos.z -= cosf(D3DX_PI *0.25f)*2.0f;
			m_rot.y = D3DX_PI * -0.25f;
		}

		else
		{//右移動
			m_pos.x += sinf(D3DX_PI *0.5f)*2.0f;
			m_rot.y = -D3DX_PI * 0.5;
		}
	}

	else if (pInputKeyboard->GetPress(DIK_W) == true)
	{//上移動
		m_pos.z += sinf(D3DX_PI *0.5f)*2.0f;
		m_rot.y = D3DX_PI * 1.0;
	}

	else if (pInputKeyboard->GetPress(DIK_S) == true)
	{//下移動
		m_pos.z -= sinf(D3DX_PI *0.5f)*2.0f;
		m_rot.y = -D3DX_PI * 2.0;
	}

	else if (pInputKeyboard->GetPress(DIK_U) == true)
	{//上昇移動
		m_pos.y += sinf(D3DX_PI *0.5f)*2.0f;
	}

	else if (pInputKeyboard->GetPress(DIK_N) == true)
	{//上昇移動
		m_pos.y -= sinf(D3DX_PI *0.5f)*2.0f;
	}

	else if (pInputKeyboard->GetPress(DIK_H) == true)
	{//向きを更新(Y値を回転させる)
		m_pos.y += sinf(D3DX_PI *0.5f)*2.0f;
	}

	//if (GetKeyboardTrigger(DIK_SPACE) == true)
	//{//SPACEキーが押された
	//	D3DXVECTOR3 move;

	//	move.x = -sinf(g_Model.rot.y)*3.0f;

	//	move.z = -cosf(g_Model.rot.y)*3.0f;

	//	move.y = 0.0f;

	//	SetBullet(g_Model.pos, move, 200, BULLETTYPE_PLAYER);
	//}

	//位置を更新
	m_pos.x += m_move.x; //x座標
	m_pos.y += m_move.y; //y座標

	////移動量を更新(減退させる)
	//m_move.x += (0.0f - m_move.x)*0.3f; //x座標
	//m_move.y += (0.0f - m_move.y)*0.3f; //y座標

	////影の位置を設定
	//SetPositionShadow(g_nIdxShadow, g_Model.pos, SHADOWTYPE_MODEL);
}

//モデルの描画処理
void CModel::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice(); //デバイスの取得
	D3DXMATRIX mtxRot, mtxTrans;              //計算用マトリックス
	D3DMATERIAL9 matDef;                      //現在のマテリアル保存用
	D3DXMATERIAL *pMat;                       //マテリアルデータへのポインタ

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&g_mtxWorldModel);

	//向きを反映	
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	D3DXMatrixMultiply(&g_mtxWorldModel, &g_mtxWorldModel, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

	D3DXMatrixMultiply(&g_mtxWorldModel, &g_mtxWorldModel, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldModel);

	//現在のマテリアルを取得wer5
	pDevice->GetMaterial(&matDef);

	//マテリアルデータへのポインタを取得
	pMat = (D3DXMATERIAL*)g_pBuffMatModel->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)g_dwNumMatModel; nCntMat++)
	{
		//マテリアルの設定
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//テクスチャの設定
		pDevice->SetTexture(0, NULL);

		//モデル(パーツ)の描画
		g_pMeshModel->DrawSubset(nCntMat);
	}
	//保存していたマテリアルを戻す
	pDevice->SetMaterial(&matDef);

	//コーンとの当たり判定
	CModel::WallCollision();

	//ゴール判定
	CModel::GoalCollision();
}

 D3DXVECTOR3 CModel::GetMove(void)
{
	 return m_move;
}

 D3DXVECTOR3 CModel::GetPos(void)
 {
	 return m_pos;
 }

//==================================================
//壁との当たり判定処理
//==================================================
void CModel::WallCollision()
{
	for (int nCntObject = 0; nCntObject < MAX_OBJECT; nCntObject++)
	{
		if (m_apObject[nCntObject] != NULL)
		{
			if (m_apObject[nCntObject]->GetType() == TYPE_CONE)
			{
				CCone* m = (CCone*)CObject::m_apObject[nCntObject];

				D3DXVECTOR3 pos = m->GetPos();

				distance = D3DXVec3Length(&(m_pos - pos));

				CCone* a = (CCone*)CObject::m_apObject[nCntObject];

				D3DXVECTOR3 move = a->GetMove();

				//距離が一定の場合は当たり判定とみなす
				if (distance < 20.0f)
				{
					//押し戻すベクトルを計算
					D3DXVECTOR3 pushBackVector = m_pos - pos;
					D3DXVec3Normalize(&pushBackVector, &pushBackVector);

					//オブジェクトを押し戻す
					m_pos += pushBackVector * 1.0f;
				}
			}
		}
	}
}

//==============================================
//ゴール判定
//==============================================
void CModel::GoalCollision()
{
		LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice(); //デバイスの取得

	for (int nCntObject = 0; nCntObject < MAX_OBJECT; nCntObject++)
	{
		if (m_apObject[nCntObject] != NULL)
		{
			if (m_apObject[nCntObject]->GetType() == TYPE_GOAL)
			{
				CGoal* m = (CGoal*)CObject::m_apObject[nCntObject];

				D3DXVECTOR3 pos = m->GetPos();

				distance = D3DXVec3Length(&(m_pos - pos));

				//距離が一定の場合は当たり判定とみなす
				if (distance < 20.0f)
				{
					//押し戻すベクトルを計算
					D3DXVECTOR3 pushBackVector = m_pos - pos;
					D3DXVec3Normalize(&pushBackVector, &pushBackVector);

					//オブジェクトを押し戻す
					m_pos += pushBackVector * 1.0f;
				}
			}
		}
	}
}