// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PSAImportOptions.generated.h"

/**
 * 
 */
UCLASS(config = Engine, defaultconfig, transient)
class UNREALPSKPSA_API UPSAImportOptions : public UObject
{
	GENERATED_BODY()
public:
	UPSAImportOptions();
	UPROPERTY( EditAnywhere, Category = "Import Settings")
		USkeleton* Skeleton;

	bool bInitialized;


	
};
