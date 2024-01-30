//==================
//
//3D�I�u�W�F�N�g���Ǘ����鏈��[3DObject.cpp]
//Aoutor:�����W��
//
//==================
#include<Windows.h>
#include"main.h"
#include"manager.h"
#include"3DObject.h"

//�ÓI�����o�ϐ�
LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff = NULL;
LPDIRECT3DTEXTURE9 m_pTexture = NULL;

//�R���X�g���N�^
C3DObject::C3DObject()
{

}

//�R���X�g���N�^
C3DObject::~C3DObject()
{

}

//��������
C3DObject * C3DObject::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType)
{
	//3D�I�u�W�F�N�g�̃|�C���^
	C3DObject * p3DObject;

	//3D�I�u�W�F�N�g�̐���
	p3DObject = new C3DObject;

	//3D�I�u�W�F�N�g�̏���������
	p3DObject->Init();

	//3D�I�u�W�F�N�g�̈ʒu
	p3DObject->SetPosition(pos, rot, nType);

	//�l��Ԃ�
	return p3DObject;
}

//�I�u�W�F�N�g�̈ʒu�ݒ�
void C3DObject::SetPosition(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice(); //�f�o�C�X�̎擾

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_3D *pVtx; //���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//���_���W�̐ݒ�	
	pVtx[0].pos = D3DXVECTOR3(-PORIGONSIZE, 0.0f, PORIGONSIZE);
	pVtx[1].pos = D3DXVECTOR3(PORIGONSIZE, 0.0f, PORIGONSIZE);
	pVtx[2].pos = D3DXVECTOR3(-PORIGONSIZE, 0.0f, -PORIGONSIZE);
	pVtx[3].pos = D3DXVECTOR3(PORIGONSIZE, 0.0f, -PORIGONSIZE);

	//�@���x�N�g���̐ݒ�
	pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	if (m_bUse == false)
	{//�g���Ȃ��ꍇ

		nType = nType;

		m_pos = pos;

		m_rot = rot;

		m_bUse = true; //�g�p���Ă����Ԃɂ���
	}

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//����������
HRESULT C3DObject::Init(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\field004.jpg",
		&m_pTexture);
	
	//����������
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //�ʒu
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f); //����
	m_bUse = false;						   //�g�p���Ă��Ȃ���Ԃɂ���

	return S_OK;
}

//�I������
void C3DObject::Uninit(void)
{
	//�e�N�X�`���̔j��
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}

	//���_�o�b�t�@�̔j��
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//�X�V����
void C3DObject::Update(void)
{
	//VERTEX_3D *pVtx; //���_�o�b�t�@�̐ݒ�

	////���_�o�b�t�@�����b�N
	//m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	////���_���W�̐ݒ�	
	//pVtx[0].pos = D3DXVECTOR3(-PORIGONSIZE, 0.0f, PORIGONSIZE);
	//pVtx[1].pos = D3DXVECTOR3(PORIGONSIZE, 0.0f, PORIGONSIZE);
	//pVtx[2].pos = D3DXVECTOR3(-PORIGONSIZE, 0.0f, -PORIGONSIZE);
	//pVtx[3].pos = D3DXVECTOR3(PORIGONSIZE, 0.0f, -PORIGONSIZE);

	////���_�J���[�̐ݒ�
	//pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	//pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	//pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
	//pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

	////���_�o�b�t�@���A�����b�N����
	//m_pVtxBuff->Unlock();
}

//�`�揈��
void C3DObject::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice(); //�f�o�C�X�̎擾

	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;									  

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//�����𔽉f	
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTexture);

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,
		0,
		2);
}

//�ʒu�擾
D3DXVECTOR3 C3DObject::GetPosition(void)
{
	return m_pos;
}