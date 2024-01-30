//==================
//
//�J�������Ǘ����鏈��[camera.cpp]
//Aoutor:�����W��
//
//==================
#include "main.h"
#include "manager.h"
#include "camera.h"
#include "input.h"
#include "model.h"

//�R���X�g���N�^
CCamera::CCamera()
{

}

//�f�X�g���N�^
CCamera::~CCamera()
{

}

//�J�����̏���������
HRESULT CCamera::Init(void)
{
	m_posV = D3DXVECTOR3(0.0f, 100.0f, -100.0f);   //���_
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);        //�����_
	m_posU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);        //������x�N�g��
	fDistance = (100.0f);						   //����
	rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		   //����
	playerpos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);     //�v���C���[�̈ʒu
	posVDest = D3DXVECTOR3(0.0f, 100.0f, -100.0f); //�ړI�̎��_
	posRDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);      //�ړI�̒����_
	posMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	   //�ړ���
	m_viewport.X = 0;                              //�`�悷���ʂ̍���X���W
	m_viewport.Y = 0;                              //�`�悷���ʂ̍���Y���W
	m_viewport.Width = 0;						   //�`�悷���ʂ̕�
	m_viewport.Height = 0;						   //�`�悷���ʂ̍���
	m_viewport.MinZ = 0.0f;
	m_viewport.MaxZ = 1.0f;

	return S_OK;
}

//�J�����̏I������
void CCamera::Uninit(void)
{

}

//�J�����̍X�V����
void CCamera::Update(void)
{
	//�v���C���[�̈ړ�
	CInputKeyboard * pInputKeyboard;

	//�L�[�{�[�h�̎擾
	pInputKeyboard = CManager::GetKeyboard();

	//���ړ�
	if (pInputKeyboard->GetPress(DIK_A) == true)
	{
		m_posV.x -= 0.5f;
		m_posR.x -= 0.5f;
	}

	//�E�ړ�
	if (pInputKeyboard->GetPress(DIK_D) == true)
	{
		m_posV.x += 0.5f;
		m_posR.x += 0.5f;
	}

	//��ړ�
	if (pInputKeyboard->GetPress(DIK_W) == true)
	{
		m_posV.z += 0.5f;
		m_posR.z += 0.5f;
	}

	//���ړ�
	if (pInputKeyboard->GetPress(DIK_S) == true)
	{
		m_posV.z -= 0.5f;
		m_posR.z -= 0.5f;
	}

	//������ړ�
	if (pInputKeyboard->GetPress(DIK_I) == true)
	{
		m_posV.y += 0.5f;
		m_posR.y += 0.5f;
	}

	//�������ړ�
	if (pInputKeyboard->GetPress(DIK_K) == true)
	{
		m_posV.y -= 0.5f;
		m_posR.y -= 0.5f;
	}

	//���_�̍���]
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

	//���_�̉E��]
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

	//�����_�̍���]
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

	//�����_�̉E��]
	if (pInputKeyboard->GetPress(DIK_E) == true)
	{
		rot.y -= 0.1f;

		if (rot.y < -D3DX_PI)
		{
			rot.y = D3DX_PI;
		}

		m_posR.x = m_posV.x - cosf(rot.y) * fDistance;
		m_posR.z = m_posV.z - sinf(rot.y) * fDistance;
	}

	////�����_
	//g_camera.posRDest = D3DXVECTOR3(pModel->pos.x + -sinf(pModel->rot.y)*50.0f, pModel->pos.y, pModel->pos.z + -cosf(pModel->rot.y)*50.0f);

	//g_camera.posVDest.x = g_camera.posRDest.x + cosf(g_camera.rot.y) * g_camera.fDistance;

	//g_camera.posVDest.z = g_camera.posRDest.z + sinf(g_camera.rot.y) * g_camera.fDistance;

	//���f���̏��
	CModel * pModel;

	//pModel->GetModel();

	////�����_�̊���
	//m_posR = pModel->m_pos;

	//���_�̊���
	m_posV.x = m_posR.x;

	m_posV.z = m_posR.z - 100.0f;
}

//�J�����̕`�揈��
void CCamera::Draw(void)
{

}

//�J�����̐ݒ菈��
void CCamera::SetCamera(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//�v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxProjection);

	//�v���W�F�N�V�����}�g���b�N�X���쐬
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		D3DXToRadian(45.0f),
		(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
		10.0f,
		1000.0f);

	//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);

	//�r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxView);

	//�r���[�}�g���b�N�X���쐬
	D3DXMatrixLookAtLH(&m_mtxView,
		&m_posV,
		&m_posR,
		&m_posU);

	//�r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);

	m_posR = playerpos;

	posMove = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //�ړ���

	////�ړI�̒����_��ݒ�
	//m_posV.x = posMove.x + m_posR.x;
	//m_posV.z = posMove.z + m_posR.z;

	////�ړI�̎��_��ݒ�
	//m_posR.x = playerpos.x + m_posV.x;
	//m_posR.z = playerpos.z + m_posV.z;
}