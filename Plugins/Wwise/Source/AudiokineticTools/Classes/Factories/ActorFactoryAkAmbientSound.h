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
	ActorFactoryAkAmbientSound.h:
=============================================================================*/
#pragma once

#include "ActorFactories/ActorFactory.h"
#include "ActorFactoryAkAmbientSound.generated.h"

/*------------------------------------------------------------------------------------
	UActorFactoryAkAmbientSound
------------------------------------------------------------------------------------*/
UCLASS(config=Editor, collapsecategories, hidecategories=Object, MinimalAPI)
class UActorFactoryAkAmbientSound : public UActorFactory
{
	GENERATED_UCLASS_BODY()
	
	// Begin UActorFactory Interface
	virtual void PostSpawnActor( UObject* Asset, AActor* NewActor ) override;
	virtual void PostCreateBlueprint( UObject* Asset, AActor* CDO ) override;
	virtual bool CanCreateActorFrom( const FAssetData& AssetData, FText& OutErrorMsg ) override;
	virtual UObject* GetAssetFromActorInstance(AActor* ActorInstance) override;
	// End UActorFactory Interface
};



