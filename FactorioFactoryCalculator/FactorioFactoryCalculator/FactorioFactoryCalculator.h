
// FactorioFactoryCalculator.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CFactorioFactoryCalculatorApp:
// このクラスの実装については、FactorioFactoryCalculator.cpp を参照してください
//

class CFactorioFactoryCalculatorApp : public CWinApp
{
public:
	CFactorioFactoryCalculatorApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CFactorioFactoryCalculatorApp theApp;
