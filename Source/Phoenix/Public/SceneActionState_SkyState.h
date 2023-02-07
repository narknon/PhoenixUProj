#pragma once
#include "CoreMinimal.h"
#include "DayNightSkyStateOverrideInterface.h"
#include "SceneRigActionState.h"
#include "SceneActionState_SkyState.generated.h"

UCLASS(Blueprintable)
class USceneActionState_SkyState : public USceneRigActionState, public IDayNightSkyStateOverrideInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LerpAlpha;
    
    USceneActionState_SkyState();
    
    // Fix for true pure virtual functions not being implemented
};

