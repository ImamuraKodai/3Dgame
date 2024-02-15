//==================
//
//カメラを管理する処理[camera.cpp]
//Aoutor:今村晃大
//
//==================
#include "main.h"
#include "manager.h"
#include "camera.h"
#include "input.h"
#include "model.h"

//コンストラクタ
CCamera::CCamera()
{

}

//デストラクタ
CCamera::~CCamera()
{

}

//==============================================================
//生成処理
//==============================================================
CCamera * CCamera::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType)
{
	//モデルのポインタ
	CCamera * pModel;

	//3Dオブジェクトの生成
	pModel = new CCamera;

	//3Dオブジェクトの初期化処理
	pModel->Init();

	//3Dオブジェクトの位置
	pModel->SetCamera(pos, rot, nType);

	//値を返す
	return pModel;
}

//カメラの初期化処理
HRESULT CCamera::Init(void)
{
	m_posV = D3DXVECTOR3(0.0f, 75.0f, 50.0f);      //視点
	m_posR = D3DXVECTOR3(0.0f, 0.1f, 0.0f);        //注視点
	m_posU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);        //上方向ベクトル
	fDistance = (100.0f);						   //距離
	rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		   //向き
	move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);          //移動量
	playerpos = D3DXVECTOR3(0.0f, 1.0f, 5.0f);     //プレイヤーの位置
	posVDest = D3DXVECTOR3(0.0f, 100.0f, -100.0f); //目的の視点
	posRDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);      //目的の注視点
	posMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	   //移動量
	m_viewport.X = 0;                              //描画する画面の左上X座標
	m_viewport.Y = 0;                              //描画する画面の左上Y座標
	m_viewport.Width = 0;						   //描画する画面の幅
	m_viewport.Height = 0;						   //描画する画面の高さ
	m_viewport.MinZ = 0.0f;
	m_viewport.MaxZ = 1.0f;

	return S_OK;
}

//カメラの終了処理
void CCamera::Uninit(void)
{

}

//カメラの更新処理
void CCamera::Update(void)
{
	//プレイヤーの移動
	CInputKeyboard * pInputKeyboard;

	//キーボードの取得
	pInputKeyboard = CManager::GetKeyboard();

	//左移動
	if (pInputKeyboard->GetPress(DIK_A) == true)
	{
		m_posV.x -= 0.5f;
		m_posR.x -= 0.5f;
	}

	//右移動
	if (pInputKeyboard->GetPress(DIK_D) == true)
	{
		m_posV.x += 0.5f;
		m_posR.x += 0.5f;
	}

	//上移動
	if (pInputKeyboard->GetPress(DIK_W) == true)
	{
		m_posV.z += 0.5f;
		m_posR.z += 0.5f;
	}

	//下移動
	if (pInputKeyboard->GetPress(DIK_S) == true)
	{
		m_posV.z -= 0.5f;
		m_posR.z -= 0.5f;
	}

	//上方向移動
	if (pInputKeyboard->GetPress(DIK_I) == true)
	{
		m_posV.y += 0.5f;
		m_posR.y += 0.5f;
	}

	//下方向移動
	if (pInputKeyboard->GetPress(DIK_K) == true)
	{
		m_posV.y -= 0.5f;
		m_posR.y -= 0.5f;
	}

	//視点の左回転
	if (pInputKeyboard->GetPress(DIK_Z) == true)
	{
		rot.y += 0.1f;

		if (rot.y < -D3DX_PI)
		{
			rot.y = D3DX_PI;
		}

		m_posV.x = m_posR.x + cosf(rot.y) * fDistance;
		m_posV.z = m_posR.z + sinf(rot.y) * fDistance;
	}

	//視点の右回転
	if (pInputKeyboard->GetPress(DIK_C) == true)
	{
		rot.y -= 0.1f;

		if (rot.y < -D3DX_PI)
		{
			rot.y = D3DX_PI;
		}

		m_posV.x = m_posR.x + cosf(rot.y) * fDistance;
		m_posV.z = m_posR.z + sinf(rot.y) * fDistance;
	}

	//注視点の左回転
	if (pInputKeyboard->GetPress(DIK_Q) == true)
	{
		rot.y += 0.1f;

		if (rot.y < -D3DX_PI)
		{
			rot.y = D3DX_PI;
		}

		m_posR.x = m_posV.x - cosf(rot.y) * fDistance;
		m_posR.z = m_posV.z - sinf(rot.y) * fDistance;
	}

	//注視点の右回転
	if (pInputKeyboard->GetPress(DIK_E) == true)
	{
		rot.y -= 0.1f;

		if (rot.y < -D3DX_PI)
		{
			rot.y = D3DX_PI;
		}

		m_posR.x = m_posV.x - cosf(rot.y) * fDistance;
		m_posR.z = m_posV.z - sinf(rot.y) * fDistance;
	};

	//モデルの情報
	CModel* p = (CModel*)CObject::m_apObject[1];
	D3DXVECTOR3 pos = p->GetPos();

	//m_posV.x = move.x;
	//m_posV.y = move.y;
	//m_posV.z = move.z;

	m_posR.x = pos.x;
	m_posR.y = pos.y;
	m_posR.z = pos.z;

	//視点の慣性
	m_posV.x = m_posR.x;

	m_posV.z = m_posR.z - 150.0f;
}

//カメラの描画処理
void CCamera::Draw(void)
{

}

//カメラの設定処理
void CCamera::SetCamera(void)
{
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();
	
	//プロジェクションマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxProjection);

	//プロジェクションマトリックスを作成
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		D3DXToRadian(45.0f),
		(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
		10.0f,
		1000.0f);

	//プロジェクションマトリックスの設定
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);

	//ビューマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxView);

	//ビューマトリックスを作成
	D3DXMatrixLookAtLH(&m_mtxView,
		&m_posV,
		&m_posR,
		&m_posU);

	//ビューマトリックスの設定
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);

	m_posR = playerpos;
}

//カメラの設定処理
void CCamera::SetCamera(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType)
{
	m_posR = pos;

	D3DXVECTOR3 posMove;

	posMove = D3DXVECTOR3(5.0f, 0.0f, 5.0f); //移動量

	//目的の注視点を設定
	//m_posV.x = posMove.x + m_posR.x;
	//m_posV.z = posMove.z + m_posR.z;

	////目的の視点を設定
	//m_posR.x = pos.x + m_posV.x;
	//m_posR.z = pos.z + m_posV.z;
}