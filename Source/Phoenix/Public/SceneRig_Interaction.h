#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SceneRig.h"
#include "SceneRigStage_Actor.h"
#include "SceneRig_Interaction.generated.h"

class AActor;
class USceneRigStageParameterBlock;

UCLASS(Blueprintable)
class PHOENIX_API USceneRig_Interaction : public USceneRig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor interactionActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_Actor LocalPlayer;
    
    USceneRig_Interaction();
    UFUNCTION(BlueprintCallable)
    void SetSceneRoot(USceneRigStageParameterBlock* StageParameterBlock, const FTransform& Transform);
    
    UFUNCTION(BlueprintCallable)
    void SetInteractionActor(USceneRigStageParameterBlock* StageParameterBlock, AActor* Actor);
    
};

