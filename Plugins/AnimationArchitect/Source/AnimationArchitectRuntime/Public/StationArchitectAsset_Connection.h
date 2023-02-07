#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "BaseArchitectAsset_Connection.h"
#include "StationArchitectAsset_AssetProxy.h"
#include "StationArchitectAsset_Connection.generated.h"

USTRUCT(BlueprintType)
struct ANIMATIONARCHITECTRUNTIME_API FStationArchitectAsset_Connection : public FBaseArchitectAsset_Connection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStationArchitectAsset_AssetProxy> AssetProxies;
    
    FStationArchitectAsset_Connection();
};

