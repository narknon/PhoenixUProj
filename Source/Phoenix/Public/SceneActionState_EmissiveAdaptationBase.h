#pragma once
#include "CoreMinimal.h"
#include "Interface_ExposureExpressionsGlobalsProvider.h"
#include "Interface_RenderSettingsEmissiveAdaptation.h"
#include "SceneRigActionState.h"
#include "SceneActionState_EmissiveAdaptationBase.generated.h"

UCLASS(Blueprintable)
class USceneActionState_EmissiveAdaptationBase : public USceneRigActionState, public IInterface_RenderSettingsEmissiveAdaptation, public IInterface_ExposureExpressionsGlobalsProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float InsertedPriortiy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrentBlend;
    
    USceneActionState_EmissiveAdaptationBase();
    
    // Fix for true pure virtual functions not being implemented
};

