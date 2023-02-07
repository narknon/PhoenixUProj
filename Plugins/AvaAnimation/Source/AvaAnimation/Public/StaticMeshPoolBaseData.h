#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ConditionalStaticMeshPool.h"
#include "StaticMeshPoolBaseData.generated.h"

UCLASS(Blueprintable)
class UStaticMeshPoolBaseData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConditionalStaticMeshPool> ConditionalStaticMeshPoolGroup;
    
    UStaticMeshPoolBaseData();
};

