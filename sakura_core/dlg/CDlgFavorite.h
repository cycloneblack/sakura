/*!	@file
	@brief �����̊Ǘ��_�C�A���O�{�b�N�X

	@author MIK
	@date 2003.4.8
*/
/*
	Copyright (C) 2003, MIK
	Copyright (C) 2010, Moca

	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose, 
	including commercial applications, and to alter it and redistribute it 
	freely, subject to the following restrictions:

		1. The origin of this software must not be misrepresented;
		   you must not claim that you wrote the original software.
		   If you use this software in a product, an acknowledgment
		   in the product documentation would be appreciated but is
		   not required.

		2. Altered source versions must be plainly marked as such, 
		   and must not be misrepresented as being the original software.

		3. This notice may not be removed or altered from any source
		   distribution.
*/



#ifndef SAKURA_CDLGFAVORITE_H_
#define SAKURA_CDLGFAVORITE_H_

#include "dlg/CDialog.h"
#include "recent/CRecent.h"

//!�u�����Ƃ��C�ɓ���̊Ǘ��v�_�C�A���O
//�A�N�Z�X���@�F[�ݒ�] - [�����̊Ǘ�]
class SAKURA_CORE_API CDlgFavorite : public CDialog
{
public:
	/*
	||  Constructors
	*/
	CDlgFavorite();
	~CDlgFavorite();

	/*
	||  Attributes & Operations
	*/
	int DoModal( HINSTANCE, HWND, LPARAM );	/* ���[�_���_�C�A���O�̕\�� */

protected:
	/*
	||  �����w���p�֐�
	*/
	BOOL	OnInitDialog( HWND, WPARAM wParam, LPARAM lParam );
	BOOL	OnBnClicked( int );
	BOOL	OnNotify( WPARAM wParam, LPARAM lParam );
	BOOL	OnActivate( WPARAM wParam, LPARAM lParam );
	LPVOID	GetHelpIdTable( void );

	void	SetData( void );	/* �_�C�A���O�f�[�^�̐ݒ� */
	int		GetData( void );	/* �_�C�A���O�f�[�^�̎擾 */

	bool	RefreshList( void );
	void	SetDataOne( int nIndex, int nLvItemIndex );	/* �_�C�A���O�f�[�^�̐ݒ� */
	bool	RefreshListOne( int nIndex );
	//void	ChangeSlider( int nIndex );
	
	void    GetFavorite( int nIndex );
	int     DeleteSelected();

private:
	CRecentFile			m_cRecentFile;
	CRecentFolder		m_cRecentFolder;
	CRecentSearch		m_cRecentSearch;
	CRecentReplace		m_cRecentReplace;
	CRecentGrepFile		m_cRecentGrepFile;
	CRecentGrepFolder	m_cRecentGrepFolder;
	CRecentCmd			m_cRecentCmd;

	enum {
		// ! �Ǘ���
		FAVORITE_INFO_MAX = 8 // �Ǘ��� +1(�ԕ�)
	};

	struct FavoriteInfo {
		CRecent*	m_pRecent;			//�I�u�W�F�N�g�ւ̃|�C���^
		TCHAR*		m_pszCaption;		//�L���v�V����
		int			m_nId;				//�R���g���[����ID
		bool		m_bHaveFavorite;	//���C�ɓ���������Ă��邩�H
		bool		m_bHaveView;		//�\�����ύX�@�\�������Ă��邩�H
		bool		m_bFilePath;		//�t�@�C��/�t�H���_���H
		int			m_nViewCount;		//�J�����g�̕\����
	};

	struct ListViewSortInfo {
		HWND	hListView; //!< ���X�g�r���[�� HWND
		int		nSortColumn; //!< �\�[�g�� -1�Ŗ��w��
		bool	bSortAscending; //!< �\�[�g������
	};

	FavoriteInfo        m_aFavoriteInfo[FAVORITE_INFO_MAX];
	ListViewSortInfo    m_aListViewInfo[FAVORITE_INFO_MAX];

	int		m_nCurrentTab;
	TCHAR	m_szMsg[1024];

	static void  ListViewSort(ListViewSortInfo&, const CRecent* , int, bool);
};

#endif	//SAKURA_CDLGFAVORITE_H_
