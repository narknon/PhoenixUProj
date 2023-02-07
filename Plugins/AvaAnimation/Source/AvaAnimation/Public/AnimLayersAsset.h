#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AnimationRequestLayer.h"
#include "AnimLayersAsset.generated.h"

UCLASS(Blueprintable)
class AVAANIMATION_API UAnimLayersAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimationRequestLayer> Layers;
    
    UAnimLayersAsset();
};

