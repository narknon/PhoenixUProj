#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "LightComponentStatesSaveData.h"
#include "SceneActionState_LightComponentStates.generated.h"

UCLASS(Blueprintable)
class USceneActionState_LightComponentStates : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLightComponentStatesSaveData SaveData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 SavedData;
    
    USceneActionState_LightComponentStates();
};

