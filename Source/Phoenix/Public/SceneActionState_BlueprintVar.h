#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_BlueprintVar.generated.h"

UCLASS(Blueprintable)
class USceneActionState_BlueprintVar : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bFirstTime;
    
    USceneActionState_BlueprintVar();
};

