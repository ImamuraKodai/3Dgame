//==================
//
//文字を出力する処理[manager.cpp]
//Aoutor:今村晃大
//
//==================
#include<Windows.h>
#include"d3dx9.h" //描画処理に必要
#include"manager.h"
#include"main.h"
#include"renderer.h"
#include"player.h"
#include"input.h"
#include"block.h"
#include"camera.h"
#include"3Dobject.h"
#include"light.h"
#include"model.h"
#include"cone.h"

//静的メンバ変数
CRenderer * CManager::m_pRenderer = NULL;
CInputKeyboard * CManager::m_pKeyboard = NULL;
CManager * pManager = NULL;
CCamera * CManager::m_pCamera = NULL;
CLight * CManager::m_pLight = NULL;
CModel * CManager::m_pModel = NULL;
CCone * CManager::m_pCone = NULL;

//コンストラクタ
CManager::CManager()
{

}

//デストラクタ
CManager::~CManager()
{

}

//初期化処理
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	//レンダラーの取得
	m_pRenderer = GetRenderer();

	//キーボードの取得
	m_pKeyboard = GetKeyboard();

	if (m_pRenderer == NULL)
	{
		//レンダラーの生成
		m_pRenderer = new CRenderer;

		//レンダラーの初期化処理
		m_pRenderer->Init(hWnd, TRUE);
	}

	if (m_pKeyboard == NULL)
	{
		//キーボードの生成
		m_pKeyboard = new CInputKeyboard;

		//キーボードの初期化処理
		m_pKeyboard->Init(hInstance, hWnd);
	}

	if (m_pCamera == NULL)
	{
		//カメラの生成
		m_pCamera = new CCamera;

		//カメラの初期化処理
		m_pCamera->Init();
	}

	if (m_pLight == NULL)
	{
		//ライトの生成
		m_pLight = new CLight;

		//ライトの初期化処理
		m_pLight->Init();
	}

	////オブジェクトの生成
	//CPlayer::Create(D3DXVECTOR3(200.0f, 200.0f, 0.0f), 1);

	//CBlock::Create(D3DXVECTOR3(500.0f, 100.0f, 0.0f), 2);

	//3Dオブジェクトの生成
	C3DObject::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 3);

	//モデルの生成
	CModel * pModel = CModel::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 4);

	//カメラの生成
	CCamera * m_pCamera = CCamera::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 5);

	//コーンの生成
	CCone * m_pCone = CCone::Create(D3DXVECTOR3(200.0f, 0.0f, 200.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 6);

	m_pCone = CCone::Create(D3DXVECTOR3(500.0f, 0.0f, 500.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 7);

	m_pCone = CCone::Create(D3DXVECTOR3(200.0f, 0.0f, -100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 8);

	return S_OK;
}

//終了処理	
void CManager::Uninit(void)
{
	//すべてのオブジェクトの破棄(+終了処理)
	CObject::ReleaseAll();

	//レンダラーの破棄
	if (m_pRenderer != NULL)
	{
		//レンダラーの終了処理
		m_pRenderer->Uninit();

		delete m_pRenderer;

		m_pRenderer = NULL;
	}

	//キーボードの破棄
	if (m_pKeyboard != NULL)
	{
		//キーボードの終了処理
		m_pKeyboard->Uninit();

		delete m_pKeyboard;

		m_pKeyboard = NULL;
	}

	//カメラの破棄
	if (m_pCamera != NULL)
	{
		//カメラの終了処理
		m_pCamera->Uninit();

		delete m_pCamera;

		m_pCamera = NULL;
	}

	//ライトの破棄
	if (m_pLight != NULL)
	{
		//ライトの終了処理
		m_pLight->Uninit();

		delete m_pLight;

		m_pLight = NULL;
	}
}

//更新処理
void CManager::Update(void)
{
	//オブジェクトの更新処理
	//CObject::UpdateAll();

	//レンダラーの更新処理
	m_pRenderer->Update();

	//キーボードの更新処理
	m_pKeyboard->Update();

	//カメラの更新処理
	m_pCamera->Update();

	//ライトの更新処理
	m_pLight->Update();
}

//描画処理
void CManager::Draw(void)
{
	//オブジェクトの描画処理
	CObject::DrawAll();

	//レンダラーの描画処理
	m_pRenderer->Draw();                                             

	//カメラの描画処理
	m_pCamera->SetCamera();
}

//レンダラーの取得
CRenderer * CManager::GetRenderer(void)
{
	return m_pRenderer;
}

CObject * CManager::GetObject(void)
{
	return S_OK;
}

//キーボードの取得
CInputKeyboard * CManager::GetKeyboard(void)
{
	return m_pKeyboard;
}

//カメラの取得
CCamera * CManager::GetCamera(void)
{
	return m_pCamera;
}

//ライトの取得
CLight * CManager::GetLight(void)
{
	return m_pLight;
}

////staticの一括管理
//CManager * CManager::GetInstance(void)
//{
//	if (pManager == NULL)
//	{
//		return pManager = new CManager;
//	}
//
//	return pManager;
//}