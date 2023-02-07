#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EToolEffectType.h"
#include "ToolEffectData.generated.h"

class UCurveFloat;

UCLASS(Blueprintable)
class UToolEffectData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EToolEffectType EffectType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* GraphCurveFloat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseScale;
    
    UToolEffectData();
};

