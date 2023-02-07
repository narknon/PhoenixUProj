#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LerpVolumesBoundsCacheLevelRemapping.generated.h"

UCLASS(Blueprintable)
class LERPVOLUMES_API ULerpVolumesBoundsCacheLevelRemapping : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FName> FastLevelNameMap;
    
    ULerpVolumesBoundsCacheLevelRemapping();
    UFUNCTION(BlueprintCallable)
    void RebuildAll();
    
};

