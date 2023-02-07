#pragma once
#include "CoreMinimal.h"
#include "BaseArchitectAsset.h"
#include "PreLoadAssetArchitectAsset_Connection.h"
#include "PreLoadAssetArchitectAsset.generated.h"

UCLASS(Blueprintable)
class ANIMATIONARCHITECTRUNTIME_API UPreLoadAssetArchitectAsset : public UBaseArchitectAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPreLoadAssetArchitectAsset_Connection> ConnectionArray;
    
    UPreLoadAssetArchitectAsset();
};

