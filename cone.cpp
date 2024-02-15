//==========================================================
//
//�R�[����`�悷�鏈��[cone.cpp]
//Aoutor:�����W��
//
//==========================================================
#include "cone.h"
#include "camera.h"
#include "Object.h"

//==============================================================
//�ÓI�����o�֐�
//==============================================================
LPDIRECT3DVERTEXBUFFER9 CCone::m_pVtxBuff = NULL; //���_�o�b�t�@�̃|�C���^

//==================================
//�R���X�g���N�^
//==================================
CCone::CCone()
{
	m_type = TYPE_CONE;
}

//===================================
//�f�X�g���N�^
//===================================
CCone::~CCone()
{

}

//=========================================================
//��������
//=========================================================
CCone * CCone::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int Type)
{
	//�R�[���̃|�C���^
	CCone* pCone;

	//�R�[���̐���
	pCone = new CCone;

	//�R�[���̏���������
	pCone->Init();

	//�R�[���̈ʒu
	pCone->SetPosition(pos, rot, Type);

	//�l��Ԃ�
	return pCone;
}

//===========================================
//�ʒu���
//===========================================
void CCone::SetPosition(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int Type)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_CONE,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_3D *pVtx; //���_���ւ̃|�C���^

	//���_�o�b�t�@�����b�N���A���_���̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntCone = 0; nCntCone < MAX_CONE; nCntCone++)
	{
		//���_���W�̐ݒ�	
		pVtx[0].pos = D3DXVECTOR3(-MODELSIZE, MODELSIZE, 0);
		pVtx[1].pos = D3DXVECTOR3(MODELSIZE, MODELSIZE, 0);
		pVtx[2].pos = D3DXVECTOR3(-MODELSIZE, -MODELSIZE, 0);
		pVtx[3].pos = D3DXVECTOR3(MODELSIZE, -MODELSIZE, 0);

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

		pVtx += 4;
	}

	for (nCntCone = 0; nCntCone < MAX_CONE; nCntCone++)
	{
		if (m_bUse == false)
		{//�g���Ȃ��ꍇ

			m_Type = Type;

			m_pos = pos;

			m_rot = rot;

			m_bUse = true; //�g�p���Ă����Ԃɂ���
		}
	}

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();
}

//===========================================
//����������
//===========================================
HRESULT CCone::Init(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	for (nCntCone = 0; nCntCone < MAX_CONE; nCntCone++)
	{
		if (nCntConeModel == 0)
		{
			//X�t�@�C���̓ǂݍ���
			D3DXLoadMeshFromX("data\\MODEL\\conebar000.x",
				D3DXMESH_SYSTEMMEM,
				pDevice,
				NULL,
				&m_pBuffMatCone,
				NULL,
				&m_dwNumMatCone,
				&m_pMeshCone);
		}

		//D3DXMATERIAL * pMat; //�}�e���A���̃|�C���^

		////�}�e���A�����ɑ΂���|�C���^���擾
		//pMat = (D3DXMATERIAL *)m_pMeshCone[nCntConeModel]->GetBufferPointer();
	}

	return S_OK;
}

//===========================================
//�I������
//===========================================
void CCone::Uninit(void)
{
	//���b�V���̔j��
	if (m_pMeshCone != NULL)
	{
		m_pMeshCone->Release();
		m_pMeshCone = NULL;
	}

	//�}�e���A���̔j��
	if (m_pBuffMatCone != NULL)
	{
		m_pBuffMatCone->Release();
		m_pBuffMatCone = NULL;
	}
}

//=========================================
//�X�V����
//=========================================
void CCone::Update(void)
{

}

//==================================
//�`�揈��
//==================================
void CCone::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice(); //�f�o�C�X�̎擾
	D3DXMATRIX mtxRot, mtxTrans;              //�v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;                      //���݂̃}�e���A���ۑ��p
	D3DXMATERIAL *pMat;                       //�}�e���A���f�[�^�ւ̃|�C���^

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&mtxWorld);

	//�����𔽉f	
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

	D3DXMatrixMultiply(&mtxWorld, &mtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &mtxWorld);

	//���݂̃}�e���A�����擾wer5
	pDevice->GetMaterial(&matDef);

	//�}�e���A���f�[�^�ւ̃|�C���^���擾
	pMat = (D3DXMATERIAL*)m_pBuffMatCone->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)m_dwNumMatCone; nCntMat++)
	{
		//�}�e���A���̐ݒ�
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, NULL);

		//���f��(�p�[�c)�̕`��
		m_pMeshCone->DrawSubset(nCntMat);
	}
	//�ۑ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);
}

//=====================================================
//�ʒu�̎擾
//=====================================================
D3DXVECTOR3 CCone::GetPos(void)
{
	return m_pos;
}

//=====================================================
//�ړ��ʂ̎擾
//=====================================================
D3DXVECTOR3 CCone::GetMove(void)
{
	return m_move;
}