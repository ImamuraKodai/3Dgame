//==================
//
//�������o�͂��鏈��[manager.cpp]
//Aoutor:�����W��
//
//==================
#include<Windows.h>
#include"d3dx9.h" //�`�揈���ɕK�v
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

//�ÓI�����o�ϐ�
CRenderer * CManager::m_pRenderer = NULL;
CInputKeyboard * CManager::m_pKeyboard = NULL;
CManager * pManager = NULL;
CCamera * CManager::m_pCamera = NULL;
CLight * CManager::m_pLight = NULL;
CModel * CManager::m_pModel = NULL;
CCone * CManager::m_pCone = NULL;

//�R���X�g���N�^
CManager::CManager()
{

}

//�f�X�g���N�^
CManager::~CManager()
{

}

//����������
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	//�����_���[�̎擾
	m_pRenderer = GetRenderer();

	//�L�[�{�[�h�̎擾
	m_pKeyboard = GetKeyboard();

	if (m_pRenderer == NULL)
	{
		//�����_���[�̐���
		m_pRenderer = new CRenderer;

		//�����_���[�̏���������
		m_pRenderer->Init(hWnd, TRUE);
	}

	if (m_pKeyboard == NULL)
	{
		//�L�[�{�[�h�̐���
		m_pKeyboard = new CInputKeyboard;

		//�L�[�{�[�h�̏���������
		m_pKeyboard->Init(hInstance, hWnd);
	}

	if (m_pCamera == NULL)
	{
		//�J�����̐���
		m_pCamera = new CCamera;

		//�J�����̏���������
		m_pCamera->Init();
	}

	if (m_pLight == NULL)
	{
		//���C�g�̐���
		m_pLight = new CLight;

		//���C�g�̏���������
		m_pLight->Init();
	}

	////�I�u�W�F�N�g�̐���
	//CPlayer::Create(D3DXVECTOR3(200.0f, 200.0f, 0.0f), 1);

	//CBlock::Create(D3DXVECTOR3(500.0f, 100.0f, 0.0f), 2);

	//3D�I�u�W�F�N�g�̐���
	C3DObject::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 3);

	//���f���̐���
	CModel * pModel = CModel::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 4);

	//�J�����̐���
	CCamera * m_pCamera = CCamera::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 5);

	//�R�[���̐���
	CCone * m_pCone = CCone::Create(D3DXVECTOR3(200.0f, 0.0f, 200.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 6);

	m_pCone = CCone::Create(D3DXVECTOR3(500.0f, 0.0f, 500.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 7);

	m_pCone = CCone::Create(D3DXVECTOR3(200.0f, 0.0f, -100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 8);

	return S_OK;
}

//�I������	
void CManager::Uninit(void)
{
	//���ׂẴI�u�W�F�N�g�̔j��(+�I������)
	CObject::ReleaseAll();

	//�����_���[�̔j��
	if (m_pRenderer != NULL)
	{
		//�����_���[�̏I������
		m_pRenderer->Uninit();

		delete m_pRenderer;

		m_pRenderer = NULL;
	}

	//�L�[�{�[�h�̔j��
	if (m_pKeyboard != NULL)
	{
		//�L�[�{�[�h�̏I������
		m_pKeyboard->Uninit();

		delete m_pKeyboard;

		m_pKeyboard = NULL;
	}

	//�J�����̔j��
	if (m_pCamera != NULL)
	{
		//�J�����̏I������
		m_pCamera->Uninit();

		delete m_pCamera;

		m_pCamera = NULL;
	}

	//���C�g�̔j��
	if (m_pLight != NULL)
	{
		//���C�g�̏I������
		m_pLight->Uninit();

		delete m_pLight;

		m_pLight = NULL;
	}
}

//�X�V����
void CManager::Update(void)
{
	//�I�u�W�F�N�g�̍X�V����
	//CObject::UpdateAll();

	//�����_���[�̍X�V����
	m_pRenderer->Update();

	//�L�[�{�[�h�̍X�V����
	m_pKeyboard->Update();

	//�J�����̍X�V����
	m_pCamera->Update();

	//���C�g�̍X�V����
	m_pLight->Update();
}

//�`�揈��
void CManager::Draw(void)
{
	//�I�u�W�F�N�g�̕`�揈��
	CObject::DrawAll();

	//�����_���[�̕`�揈��
	m_pRenderer->Draw();                                             

	//�J�����̕`�揈��
	m_pCamera->SetCamera();
}

//�����_���[�̎擾
CRenderer * CManager::GetRenderer(void)
{
	return m_pRenderer;
}

CObject * CManager::GetObject(void)
{
	return S_OK;
}

//�L�[�{�[�h�̎擾
CInputKeyboard * CManager::GetKeyboard(void)
{
	return m_pKeyboard;
}

//�J�����̎擾
CCamera * CManager::GetCamera(void)
{
	return m_pCamera;
}

//���C�g�̎擾
CLight * CManager::GetLight(void)
{
	return m_pLight;
}

////static�̈ꊇ�Ǘ�
//CManager * CManager::GetInstance(void)
//{
//	if (pManager == NULL)
//	{
//		return pManager = new CManager;
//	}
//
//	return pManager;
//}