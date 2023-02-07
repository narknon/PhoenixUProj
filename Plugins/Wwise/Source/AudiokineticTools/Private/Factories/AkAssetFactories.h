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


#pragma once

#include "Factories/Factory.h"
#include "AkAssetFactories.generated.h"

UCLASS(hidecategories = Object)
class UAkAssetFactory : public UFactory
{
	GENERATED_BODY()

public:
	FGuid AssetID;
};

UCLASS(hidecategories = Object)
class UAkAcousticTextureFactory : public UAkAssetFactory
{
	GENERATED_UCLASS_BODY()

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool CanCreateNew() const override;
};

UCLASS(hidecategories = Object)
class UAkAudioBankFactory : public UAkAssetFactory
{
	GENERATED_UCLASS_BODY()

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool CanCreateNew() const override;
};

UCLASS(hidecategories = Object)
class UAkAudioEventFactory : public UAkAssetFactory
{
	GENERATED_UCLASS_BODY()

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool CanCreateNew() const override;
};

UCLASS(hidecategories = Object)
class UAkAuxBusFactory : public UAkAssetFactory
{
	GENERATED_UCLASS_BODY()

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool CanCreateNew() const override;
};

UCLASS(hidecategories = Object)
class UAkRtpcFactory : public UAkAssetFactory
{
	GENERATED_UCLASS_BODY()

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool CanCreateNew() const override;
};

UCLASS(hidecategories = Object)
class UAkTriggerFactory : public UAkAssetFactory
{
	GENERATED_UCLASS_BODY()

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool CanCreateNew() const override;
};

UCLASS(hidecategories = Object)
class UAkExternalSourceFactory : public UAkAssetFactory
{
public:
	GENERATED_UCLASS_BODY()

	virtual UObject* FactoryCreateFile(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
	virtual bool FactoryCanImport(const FString& Filename) override;
	virtual bool CanCreateNew() const override { return false; }
	virtual bool ShouldShowInNewMenu() const override { return false; }
};

// mlarouche - For now Switch and State factory are only used in drag & drop
UCLASS(hidecategories = Object)
class UAkStateValueFactory : public UAkAssetFactory
{
	GENERATED_UCLASS_BODY()

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};

UCLASS(hidecategories = Object)
class UAkSwitchValueFactory : public UAkAssetFactory
{
	GENERATED_UCLASS_BODY()

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
