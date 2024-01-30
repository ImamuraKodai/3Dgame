#ifndef _MANAGER_H_ 
#define _MANAGER_H_ //��d�C���N���[�h�h�~

#include<windows.h>
#include"d3dx9.h" //�`�揈���ɕK�v
#include"renderer.h"
#include"input.h"

//�O���錾
class CRenderer;
class CInputKeyboard;
class CObject;
class CCamera;
class CLight;
class CModel;

//�}�l�[�W���[�N���X
class CManager
{
public:
	CManager(); //�R���X�g���N�^
	~CManager(); //�f�X�g���N�^

	HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CRenderer *GetRenderer(void);	  //�����_���[�̎擾
	static CObject *GetObject(void);		  //�I�u�W�F�N�g�̎擾
	static CInputKeyboard *GetKeyboard(void); //�L�[�{�[�h�̎擾
	static CCamera *GetCamera(void);          //�J�����̎擾
	static CLight *GetLight(void);            //���C�g�̎擾
	static CModel *GetModel(void);            //���f���̎擾

private:
	static CRenderer *m_pRenderer;			  //�����_���[
	static CObject *m_apObject;				  //�I�u�W�F�N�g
	static CInputKeyboard *m_pKeyboard;		  //�L�[�{�[�h
	static CManager * pManager;				  //�}�l�[�W���[	
	static CCamera * m_pCamera;				  //�J����
	static CLight * m_pLight;                 //���C�g
	static CModel * m_pModel;                 //���f��
};

#endif