#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtras.h"
#include "SceneActionState_EmissiveAdaptationBase.h"
#include "SceneActionState_EmissiveAdaptationExtrasSingle.generated.h"

UCLASS(Blueprintable)
class USceneActionState_EmissiveAdaptationExtrasSingle : public USceneActionState_EmissiveAdaptationBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FExposureExpressionsExtras Extras;
    
    USceneActionState_EmissiveAdaptationExtrasSingle();
};

