//==========================================================
//
//コーンを描画する処理[cone.cpp]
//Aoutor:今村晃大
//
//==========================================================
#include "cone.h"
#include "camera.h"
#include "Object.h"

//==============================================================
//静的メンバ関数
//==============================================================
LPDIRECT3DVERTEXBUFFER9 CCone::m_pVtxBuff = NULL; //頂点バッファのポインタ

//==================================
//コンストラクタ
//==================================
CCone::CCone()
{
	m_type = TYPE_CONE;
}

//===================================
//デストラクタ
//===================================
CCone::~CCone()
{

}

//=========================================================
//生成処理
//=========================================================
CCone * CCone::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int Type)
{
	//コーンのポインタ
	CCone* pCone;

	//コーンの生成
	pCone = new CCone;

	//コーンの初期化処理
	pCone->Init();

	//コーンの位置
	pCone->SetPosition(pos, rot, Type);

	//値を返す
	return pCone;
}

//===========================================
//位置情報
//===========================================
void CCone::SetPosition(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int Type)
{
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_CONE,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_3D *pVtx; //頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報のポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntCone = 0; nCntCone < MAX_CONE; nCntCone++)
	{
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

		pVtx += 4;
	}

	for (nCntCone = 0; nCntCone < MAX_CONE; nCntCone++)
	{
		if (m_bUse == false)
		{//使われない場合

			m_Type = Type;

			m_pos = pos;

			m_rot = rot;

			m_bUse = true; //使用している状態にする
		}
	}

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

//===========================================
//初期化処理
//===========================================
HRESULT CCone::Init(void)
{
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	for (nCntCone = 0; nCntCone < MAX_CONE; nCntCone++)
	{
		if (nCntConeModel == 0)
		{
			//Xファイルの読み込み
			D3DXLoadMeshFromX("data\\MODEL\\conebar000.x",
				D3DXMESH_SYSTEMMEM,
				pDevice,
				NULL,
				&m_pBuffMatCone,
				NULL,
				&m_dwNumMatCone,
				&m_pMeshCone);
		}

		//D3DXMATERIAL * pMat; //マテリアルのポインタ

		////マテリアル情報に対するポインタを取得
		//pMat = (D3DXMATERIAL *)m_pMeshCone[nCntConeModel]->GetBufferPointer();
	}

	return S_OK;
}

//===========================================
//終了処理
//===========================================
void CCone::Uninit(void)
{
	//メッシュの破棄
	if (m_pMeshCone != NULL)
	{
		m_pMeshCone->Release();
		m_pMeshCone = NULL;
	}

	//マテリアルの破棄
	if (m_pBuffMatCone != NULL)
	{
		m_pBuffMatCone->Release();
		m_pBuffMatCone = NULL;
	}
}

//=========================================
//更新処理
//=========================================
void CCone::Update(void)
{

}

//==================================
//描画処理
//==================================
void CCone::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice(); //デバイスの取得
	D3DXMATRIX mtxRot, mtxTrans;              //計算用マトリックス
	D3DMATERIAL9 matDef;                      //現在のマテリアル保存用
	D3DXMATERIAL *pMat;                       //マテリアルデータへのポインタ

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&mtxWorld);

	//向きを反映	
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

	D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);

	//現在のマテリアルを取得wer5
	pDevice->GetMaterial(&matDef);

	//マテリアルデータへのポインタを取得
	pMat = (D3DXMATERIAL*)m_pBuffMatCone->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)m_dwNumMatCone; nCntMat++)
	{
		//マテリアルの設定
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//テクスチャの設定
		pDevice->SetTexture(0, NULL);

		//モデル(パーツ)の描画
		m_pMeshCone->DrawSubset(nCntMat);
	}
	//保存していたマテリアルを戻す
	pDevice->SetMaterial(&matDef);
}

//=====================================================
//位置の取得
//=====================================================
D3DXVECTOR3 CCone::GetPos(void)
{
	return m_pos;
}

//=====================================================
//移動量の取得
//=====================================================
D3DXVECTOR3 CCone::GetMove(void)
{
	return m_move;
}