#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_ResetClothSim.generated.h"

class USceneAction_ResetClothSim;

UCLASS(Blueprintable)
class USceneActionState_ResetClothSim : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneAction_ResetClothSim* ResetClothSim;
    
    USceneActionState_ResetClothSim();
};

