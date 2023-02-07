#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Enemy_TargetSense.h"
#include "Enemy_TargetSenseAsset.generated.h"

UCLASS(Blueprintable)
class UEnemy_TargetSenseAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_TargetSense TargetSense;
    
    UEnemy_TargetSenseAsset();
};

