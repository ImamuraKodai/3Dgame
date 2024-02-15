#ifndef _CONE_H_
#define _CONE_H_

#include"main.h"
#include"manager.h"
#include"Object.h"

//�}�N����`
#define MAX_CONE  (128)   //�I�u�W�F�N�g�̐�
#define MAX_CONEMODEL (1)

//============================================
//�R�[���N���X
//============================================
class CCone :public CObject
{
public:
	CCone();
	~CCone();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static CCone *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int Type);
	D3DXVECTOR3 GetPos(void);
	D3DXVECTOR3 GetMove(void);

protected:
	static LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	//���_�o�b�t�@

private:

	D3DXVECTOR3 m_pos; //�ʒu

	D3DXVECTOR3 m_move; //�ړ���

	D3DXVECTOR3 m_rot; //����

	D3DXVECTOR3 m_RotDest; //�ړI�̌���

	D3DXMATRIX mtxWorld;	//���[���h�}�g���b�N�X

	int nIdxShadow;			//�Ώۂ̉e�̃C���f�b�N�X(�ԍ�)

	float fDirection;  //����

	int nCounterState; //�_���[�W���

	int nLife;         //�̗́@

	int m_Type;         //���

	bool m_bUse;	   //�g���Ă��邩�ǂ���

	LPD3DXMESH m_pMeshCone;		    //���b�V��(���_���)�ւ̃|�C���^

	LPD3DXBUFFER m_pBuffMatCone;	//�}�e���A���ւ̃|�C���^

	DWORD m_dwNumMatCone = 0;		//�}�e���A���̐�

	LPDIRECT3DTEXTURE9 m_pTexture;	//�e�N�X�`���ւ̃|�C���^

	CCone* g_aObstacleModel[MAX_CONEMODEL]; //�G�l�~�[���f���̎��

	CCone* g_aEnemy[MAX_CONE];            //�G�̏��

	int nCntCone;	   //�G�̃J�E���g

	int nCntConeModel; //���f���̃J�E���g

	void SetPosition(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int Type); //�ʒu���
};

#endif 