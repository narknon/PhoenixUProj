#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "BaseArchitectAsset_Connection.h"
#include "ObjectArchitectAsset_AssetProxy.h"
#include "ObjectArchitectAsset_Connection.generated.h"

USTRUCT(BlueprintType)
struct ANIMATIONARCHITECTRUNTIME_API FObjectArchitectAsset_Connection : public FBaseArchitectAsset_Connection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FObjectArchitectAsset_AssetProxy> AssetProxies;
    
    FObjectArchitectAsset_Connection();
};

