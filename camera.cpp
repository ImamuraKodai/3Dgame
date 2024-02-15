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

//==============================================================
//��������
//==============================================================
CCamera * CCamera::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType)
{
	//���f���̃|�C���^
	CCamera * pModel;

	//3D�I�u�W�F�N�g�̐���
	pModel = new CCamera;

	//3D�I�u�W�F�N�g�̏���������
	pModel->Init();

	//3D�I�u�W�F�N�g�̈ʒu
	pModel->SetCamera(pos, rot, nType);

	//�l��Ԃ�
	return pModel;
}

//�J�����̏���������
HRESULT CCamera::Init(void)
{
	m_posV = D3DXVECTOR3(0.0f, 75.0f, 50.0f);      //���_
	m_posR = D3DXVECTOR3(0.0f, 0.1f, 0.0f);        //�����_
	m_posU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);        //������x�N�g��
	fDistance = (100.0f);						   //����
	rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		   //����
	move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);          //�ړ���
	playerpos = D3DXVECTOR3(0.0f, 1.0f, 5.0f);     //�v���C���[�̈ʒu
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
	};

	//���f���̏��
	CModel* p = (CModel*)CObject::m_apObject[1];
	D3DXVECTOR3 pos = p->GetPos();

	//m_posV.x = move.x;
	//m_posV.y = move.y;
	//m_posV.z = move.z;

	m_posR.x = pos.x;
	m_posR.y = pos.y;
	m_posR.z = pos.z;

	//���_�̊���
	m_posV.x = m_posR.x;

	m_posV.z = m_posR.z - 150.0f;
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
}

//�J�����̐ݒ菈��
void CCamera::SetCamera(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType)
{
	m_posR = pos;

	D3DXVECTOR3 posMove;

	posMove = D3DXVECTOR3(5.0f, 0.0f, 5.0f); //�ړ���

	//�ړI�̒����_��ݒ�
	//m_posV.x = posMove.x + m_posR.x;
	//m_posV.z = posMove.z + m_posR.z;

	////�ړI�̎��_��ݒ�
	//m_posR.x = pos.x + m_posV.x;
	//m_posR.z = pos.z + m_posV.z;
}