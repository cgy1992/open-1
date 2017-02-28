#pragma once
#include <Psapi.h>
#pragma comment(lib,"Psapi.lib")


class CSignMatch
{
public:
	enum{MinSignLen=1,MaxSignLen=0x100,MaxScanRange=0x10000};
	//�û�ָ�����������ַ���
	char m_szOrigSign[MaxSignLen];	
	//m_strOrigSignһ�δ������������,��Ҫ��?�任Ϊ0
	BYTE*	m_pPureSign;	
	//�����������,�������ģ��ƥ��
	BYTE*	m_pMaskSign;
	//�����볤��
	int		m_nSignLen;

	//��������ַ
	PBYTE	m_pBase;

	//��������ʼrva
	DWORD	m_dwSearchBegin;

	//�����Ľ���rva
	DWORD	m_dwSearchEnd;

	DWORD	m_nRange;
	DWORD	m_dwMatchPos;
private:
	void	FreeMemory();
	BYTE	HexCharToBin(BYTE chHex);

public:
	CSignMatch();
	CSignMatch(const CSignMatch&obj);
	CSignMatch(PBYTE pBase,DWORD dwStartRva,DWORD dwEndRva,char*szOrigSign);
	virtual ~CSignMatch();

	BOOL	SetOrigSign(PBYTE pBase,DWORD dwStartRva,DWORD dwEndRva,char*szOrigSign);
	PBYTE	SearchSign();
	PBYTE	SearchProcessSign(HANDLE hProcess);
};