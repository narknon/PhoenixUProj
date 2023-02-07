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


/*=============================================================================
	AkJsonFactory.h:
=============================================================================*/
#pragma once

#include "Factories/Factory.h"
#include "AkJsonFactory.generated.h"

/*------------------------------------------------------------------------------------
	UAkJsonFactory
------------------------------------------------------------------------------------*/
UCLASS(hidecategories=Object)
class UAkJsonFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

#if CPP
	/*------------------------------------------------------------------------------------
		UFactory Interface
	------------------------------------------------------------------------------------*/
	/**
	 * Create a new instance
	 *
	 * @param Class		The type of class to create
	 * @param InParent	The parent class
	 * @param Name		The name of the new instance
	 * @param Flags		Creation flags
	 * @param Context	Creation context
	 * @param Warn		Warnings
	 * @return The new object if creation was successful, otherwise false 
	 */
	virtual UObject* FactoryCreateNew(UClass* Class,UObject* InParent,FName Name,EObjectFlags Flags,UObject* Context,FFeedbackContext* Warn) override;
#endif

	/**
	 * @return	true if this factory can deal with the file sent in.
	 */
	virtual bool FactoryCanImport(const FString& Filename) override;
	virtual bool ShouldShowInNewMenu() const override;

};



