#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "BaseArchitectAsset_Connection.h"
#include "BaseArchitectMonolithicAsset_AssetProxy.h"
#include "BaseArchitectMonolithicAsset_Connection.generated.h"

USTRUCT(BlueprintType)
struct ANIMATIONARCHITECTRUNTIME_API FBaseArchitectMonolithicAsset_Connection : public FBaseArchitectAsset_Connection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBaseArchitectMonolithicAsset_AssetProxy> AssetProxies;
    
    FBaseArchitectMonolithicAsset_Connection();
};

