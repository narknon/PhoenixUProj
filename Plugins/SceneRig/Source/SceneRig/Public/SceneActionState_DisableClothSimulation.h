#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_DisableClothSimulation.generated.h"

class USceneAction_DisableClothSimulation;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_DisableClothSimulation : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneAction_DisableClothSimulation* DisableClothDefinition;
    
    USceneActionState_DisableClothSimulation();
};

