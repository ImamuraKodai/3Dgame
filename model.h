#ifndef _MODEL_H_
#define _MODEL_H_

#include"main.h"
#include"manager.h"
#include"Object.h"

//�}�N����`
#define MODELSIZE (0.0f)

//���f���̏��
typedef enum
{
	PLAYERSTATE_APPEAR, //�o�����(�_��)
	PLAYERSTATE_NORMAL, //�ʏ���
	PLAYERSTATE_DAMAGE, //�_���[�W���
	PLAYERSTATE_WAIT,   //�o���҂����(�\���Ȃ�)
	PLAYERSTATE_DEATH,  //���S���
	PLAYERSTATE_MAX
}PLAYERSTATE;

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
	/*void HitModel(int nDamage);*/
	void SetPosition(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType);
	void GetModel(void);
	static CModel *Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, int nType);

protected:
	static LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;	//���_�o�b�t�@

private:

	D3DXVECTOR3 m_pos; //�ʒu

	D3DXVECTOR3 m_move; //�ړ���

	D3DXVECTOR3 m_rot; //����

	D3DXVECTOR3 m_RotDest; //�ړI�̌���

	float fDirection; //����

	PLAYERSTATE state; //�v���C���[�̏��

	int nCounterState; //�_���[�W���

	int nLife;         //�̗́@

	bool m_bUse;	   //�g���Ă��邩�ǂ���
};

#endif