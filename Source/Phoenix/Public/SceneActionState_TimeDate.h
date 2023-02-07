#pragma once
#include "CoreMinimal.h"
#include "DayNightTimeOverrideInterface.h"
#include "SceneRigActionState.h"
#include "SceneActionState_TimeDate.generated.h"

UCLASS(Blueprintable)
class USceneActionState_TimeDate : public USceneRigActionState, public IDayNightTimeOverrideInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LerpAlpha;
    
    USceneActionState_TimeDate();
    
    // Fix for true pure virtual functions not being implemented
};

