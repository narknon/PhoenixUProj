#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MoonPath.h"
#include "FixedIdealMoonPathData.generated.h"

UCLASS(Blueprintable)
class DAYNIGHT_API UFixedIdealMoonPathData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMoonPath MoonPath;
    
    UFixedIdealMoonPathData();
    UFUNCTION(BlueprintCallable)
    void ForceRecompute();
    
};

