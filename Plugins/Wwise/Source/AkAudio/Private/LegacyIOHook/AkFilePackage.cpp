/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/

/*******************************************************************************
The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided 
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

  Version: <VERSION>  Build: <BUILDNUMBER>
  Copyright (c) <COPYRIGHTYEAR> Audiokinetic Inc.
*******************************************************************************/
//////////////////////////////////////////////////////////////////////
// 
// AkFilePackage.h
//
// This class represents a file package that was created with the 
// AkFilePackager utility app (located in ($WWISESDK)/samples/FilePackager/). 
// It holds a system file handle and a look-up table (CAkFilePackageLUT).
//
// CAkFilePackage objects can be chained together using the ListFilePackages
// typedef defined below.
//
//////////////////////////////////////////////////////////////////////

#include "AkFilePackage.h"

// Destroy file package and free memory / destroy pool.
void CAkFilePackage::Destroy()
{
	// Cache memory pointer because memory pool is destroyed _after_ deleting this.
	void * pToRelease	= m_pToRelease;

	// Call destructor.
	this->~CAkFilePackage();

	// Free memory.
	ClearMemory(pToRelease);
}

void CAkFilePackage::ClearMemory(
	void *		in_pMemToRelease	// Memory block to free before destroying pool.
	)
{
	if (in_pMemToRelease)
	{
		AkFree(AkMemID_FilePackage, in_pMemToRelease);
	}
}
