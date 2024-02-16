//==========================================================
//
//���f�����o�͂��鏈��[model.cpp]
//Aoutor:�����W��
//
//==========================================================
#include "model.h"
#include "input.h"
#include "camera.h"
#include "Object.h"
#include "3Dobject.h"
#include "cone.h"
#include "goal.h"

//�O���[�o���ϐ�
LPD3DXMESH g_pMeshModel = NULL;      //���b�V��(���_���)�ւ̃|�C���^
LPD3DXBUFFER g_pBuffMatModel = NULL; //�}�e���A���ւ̃|�C���^
DWORD g_dwNumMatModel = 0;           //�}�e���A���̐�
D3DXMATRIX g_mtxWorldModel;          //���[���h�}�g���b�N�X
int g_nIdxShadow = -1;               //�Ώۂ̉e�̃C���f�b�N�X(�ԍ�)

//================================================================
//�ÓI�����o�֐�
//================================================================
LPDIRECT3DVERTEXBUFFER9 CModel::m_pVtxBuff = NULL; //���_�o�b�t�@�̃|�C���^

//==============================================================
//�R���X�g���N�^
//==============================================================
CModel::CModel()
{
	m_type = TYPE_MODEL;
}

//==============================================================
//�f�X�g���N�^
//==============================================================
CModel::~CModel()
{

}

//==============================================================
//��������
//==============================================================
CModel* CModel::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType)
{
	//���f���̃|�C���^
	CModel* pModel;

	//3D�I�u�W�F�N�g�̐���
	pModel = new CModel;

	//3D�I�u�W�F�N�g�̏���������
	pModel->Init();

	//3D�I�u�W�F�N�g�̈ʒu
	pModel->SetPosition(pos, rot, nType);

	//�l��Ԃ�
	return pModel;
}

//==================================================================
//���f���̈ʒu�ݒ�
//==================================================================
void CModel::SetPosition(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

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

//==============================================================
//����������
//==============================================================
HRESULT CModel::Init(void)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();

	//X�t�@�C���̓ǂݍ���
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

	//����������
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);      //�ʒu
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//�ړ�
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//����
	m_RotDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);  //�ړI�̌���
	m_bUse = true;                              //�g���Ă��邩�ǂ���

	return S_OK;
}

//======================================================================
//�I������
//======================================================================
void CModel::Uninit(void)
{
	//���b�V���̔j��
	if (g_pMeshModel != NULL)
	{
		g_pMeshModel->Release();
		g_pMeshModel = NULL;
	}

	//�}�e���A���̔j��
	if (g_pBuffMatModel != NULL)
	{
		g_pBuffMatModel->Release();
		g_pBuffMatModel = NULL;
	}
}

//=======================================================================
//�X�V����
//=======================================================================
void CModel::Update(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice(); //�f�o�C�X�̎擾

	//�v���C���[�̈ړ�
	CInputKeyboard * pInputKeyboard;

	//�L�[�{�[�h�̎擾
	pInputKeyboard = CManager::GetKeyboard();

	if (pInputKeyboard->GetPress(DIK_A) == true)
	{//A�L�[�������ꂽ

		if (pInputKeyboard->GetPress(DIK_W) == true)
		{//����ړ�
			m_pos.x += sinf(-D3DX_PI *0.75f)*2.0f;
			m_pos.z -= cosf(-D3DX_PI *0.75f)*2.0f;
			m_rot.y = D3DX_PI * 0.75f;
		}

		else if (pInputKeyboard->GetPress(DIK_S) == true)
		{//�����ړ�
			m_pos.x += sinf(-D3DX_PI *0.25f)*2.0f;
			m_pos.z -= cosf(-D3DX_PI *0.25f)*2.0f;
			m_rot.y = D3DX_PI * 0.25f;
		}

		else
		{//���ړ�
			m_pos.x += sinf(-D3DX_PI *0.5f)*2.0f;
			m_rot.y = D3DX_PI * 0.5;
		}
	}

	else if (pInputKeyboard->GetPress(DIK_D) == true)
	{//D�L�[�������ꂽ

		if (pInputKeyboard->GetPress(DIK_W) == true)
		{//�E��ړ�
			m_pos.x += sinf(D3DX_PI *0.75f)*2.0f;
			m_pos.z -= cosf(D3DX_PI *0.75f)*2.0f;
			m_rot.y = D3DX_PI * -0.75f;
		}

		else if (pInputKeyboard->GetPress(DIK_S) == true)
		{//�E���ړ�
			m_pos.x += sinf(D3DX_PI *0.25f)*2.0f;
			m_pos.z -= cosf(D3DX_PI *0.25f)*2.0f;
			m_rot.y = D3DX_PI * -0.25f;
		}

		else
		{//�E�ړ�
			m_pos.x += sinf(D3DX_PI *0.5f)*2.0f;
			m_rot.y = -D3DX_PI * 0.5;
		}
	}

	else if (pInputKeyboard->GetPress(DIK_W) == true)
	{//��ړ�
		m_pos.z += sinf(D3DX_PI *0.5f)*2.0f;
		m_rot.y = D3DX_PI * 1.0;
	}

	else if (pInputKeyboard->GetPress(DIK_S) == true)
	{//���ړ�
		m_pos.z -= sinf(D3DX_PI *0.5f)*2.0f;
		m_rot.y = -D3DX_PI * 2.0;
	}

	else if (pInputKeyboard->GetPress(DIK_U) == true)
	{//�㏸�ړ�
		m_pos.y += sinf(D3DX_PI *0.5f)*2.0f;
	}

	else if (pInputKeyboard->GetPress(DIK_N) == true)
	{//�㏸�ړ�
		m_pos.y -= sinf(D3DX_PI *0.5f)*2.0f;
	}

	else if (pInputKeyboard->GetPress(DIK_H) == true)
	{//�������X�V(Y�l����]������)
		m_pos.y += sinf(D3DX_PI *0.5f)*2.0f;
	}

	//if (GetKeyboardTrigger(DIK_SPACE) == true)
	//{//SPACE�L�[�������ꂽ
	//	D3DXVECTOR3 move;

	//	move.x = -sinf(g_Model.rot.y)*3.0f;

	//	move.z = -cosf(g_Model.rot.y)*3.0f;

	//	move.y = 0.0f;

	//	SetBullet(g_Model.pos, move, 200, BULLETTYPE_PLAYER);
	//}

	//�ʒu���X�V
	m_pos.x += m_move.x; //x���W
	m_pos.y += m_move.y; //y���W

	////�ړ��ʂ��X�V(���ނ�����)
	//m_move.x += (0.0f - m_move.x)*0.3f; //x���W
	//m_move.y += (0.0f - m_move.y)*0.3f; //y���W

	////�e�̈ʒu��ݒ�
	//SetPositionShadow(g_nIdxShadow, g_Model.pos, SHADOWTYPE_MODEL);
}

//���f���̕`�揈��
void CModel::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice(); //�f�o�C�X�̎擾
	D3DXMATRIX mtxRot, mtxTrans;              //�v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;                      //���݂̃}�e���A���ۑ��p
	D3DXMATERIAL *pMat;                       //�}�e���A���f�[�^�ւ̃|�C���^

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&g_mtxWorldModel);

	//�����𔽉f	
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	D3DXMatrixMultiply(&g_mtxWorldModel, &g_mtxWorldModel, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

	D3DXMatrixMultiply(&g_mtxWorldModel, &g_mtxWorldModel, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &g_mtxWorldModel);

	//���݂̃}�e���A�����擾wer5
	pDevice->GetMaterial(&matDef);

	//�}�e���A���f�[�^�ւ̃|�C���^���擾
	pMat = (D3DXMATERIAL*)g_pBuffMatModel->GetBufferPointer();

	for (int nCntMat = 0; nCntMat < (int)g_dwNumMatModel; nCntMat++)
	{
		//�}�e���A���̐ݒ�
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, NULL);

		//���f��(�p�[�c)�̕`��
		g_pMeshModel->DrawSubset(nCntMat);
	}
	//�ۑ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);

	//�R�[���Ƃ̓����蔻��
	CModel::WallCollision();

	//�S�[������
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
//�ǂƂ̓����蔻�菈��
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

				//���������̏ꍇ�͓����蔻��Ƃ݂Ȃ�
				if (distance < 20.0f)
				{
					//�����߂��x�N�g�����v�Z
					D3DXVECTOR3 pushBackVector = m_pos - pos;
					D3DXVec3Normalize(&pushBackVector, &pushBackVector);

					//�I�u�W�F�N�g�������߂�
					m_pos += pushBackVector * 1.0f;
				}
			}
		}
	}
}

//==============================================
//�S�[������
//==============================================
void CModel::GoalCollision()
{
		LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice(); //�f�o�C�X�̎擾

	for (int nCntObject = 0; nCntObject < MAX_OBJECT; nCntObject++)
	{
		if (m_apObject[nCntObject] != NULL)
		{
			if (m_apObject[nCntObject]->GetType() == TYPE_GOAL)
			{
				CGoal* m = (CGoal*)CObject::m_apObject[nCntObject];

				D3DXVECTOR3 pos = m->GetPos();

				distance = D3DXVec3Length(&(m_pos - pos));

				//���������̏ꍇ�͓����蔻��Ƃ݂Ȃ�
				if (distance < 20.0f)
				{
					//�����߂��x�N�g�����v�Z
					D3DXVECTOR3 pushBackVector = m_pos - pos;
					D3DXVec3Normalize(&pushBackVector, &pushBackVector);

					//�I�u�W�F�N�g�������߂�
					m_pos += pushBackVector * 1.0f;
				}
			}
		}
	}
}