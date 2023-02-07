#pragma once
#include "CoreMinimal.h"
#include "BaseArchitectAsset_Connection.h"
#include "InteractionArchitectAsset_AssetProxy.h"
#include "InteractionArchitectAsset_KeyValueGroup.h"
#include "InteractionArchitectAsset_Connection.generated.h"

USTRUCT(BlueprintType)
struct ANIMATIONARCHITECTRUNTIME_API FInteractionArchitectAsset_Connection : public FBaseArchitectAsset_Connection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInteractionArchitectAsset_KeyValueGroup> KeyValueGroups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInteractionArchitectAsset_AssetProxy> AssetProxies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsAdditive;
    
    FInteractionArchitectAsset_Connection();
};

