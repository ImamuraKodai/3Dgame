#ifndef _MODEL_H_
#define _MODEL_H_

#include"main.h"
#include"manager.h"
#include"Object.h"

//�}�N����`
#define MODELSIZE (0.0f)

//===================================
//���f���N���X
//===================================
class CModel :public CObject
{
public:
	CModel();
	~CModel();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void WallCollision();
	void GoalCollision();

	/*void HitModel(int nDamage);*/
	static CModel *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType);

	D3DXVECTOR3 GetMove(void);

	D3DXVECTOR3 GetPos(void);

	void ExampleFunction() {
		int value = GetType();
		// m_type�ɃA�N�Z�X�ł���
	}

protected:
	static LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	//���_�o�b�t�@

private:

	void SetPosition(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType);

	D3DXVECTOR3 m_pos; //�ʒu
	
	D3DXVECTOR3 m_move; //�ړ���

	D3DXVECTOR3 m_rot; //����

	D3DXVECTOR3 m_RotDest; //�ړI�̌���

	float distance;	   //����

	int nCounterState; //�_���[�W���

	int nLife;         //�̗́@

	bool m_bUse;	   //�g���Ă��邩�ǂ���
};

#endif
