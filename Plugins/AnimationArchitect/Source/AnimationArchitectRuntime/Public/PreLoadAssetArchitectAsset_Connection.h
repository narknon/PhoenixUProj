#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "BaseArchitectAsset_Connection.h"
#include "PreLoadAssetArchitectAsset_AssetProxy.h"
#include "PreLoadAssetArchitectAsset_Connection.generated.h"

USTRUCT(BlueprintType)
struct ANIMATIONARCHITECTRUNTIME_API FPreLoadAssetArchitectAsset_Connection : public FBaseArchitectAsset_Connection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPreLoadAssetArchitectAsset_AssetProxy> AssetProxies;
    
    FPreLoadAssetArchitectAsset_Connection();
};

