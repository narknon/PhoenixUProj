#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionState.h"
#include "SceneActionState_SanctuaryLoadZone.generated.h"

UCLASS(Blueprintable)
class USceneActionState_SanctuaryLoadZone : public USceneRigActionState {
    GENERATED_BODY()
public:
    USceneActionState_SanctuaryLoadZone();
    UFUNCTION(BlueprintCallable)
    void OnZoneLoadedAndVisible();
    
};

