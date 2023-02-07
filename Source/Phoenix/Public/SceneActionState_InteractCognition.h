#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_InteractCognition.generated.h"

class UCognitionStimuliSourceComponent;

UCLASS(Blueprintable)
class USceneActionState_InteractCognition : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* OwnedCognitionComponent;
    
    USceneActionState_InteractCognition();
};

