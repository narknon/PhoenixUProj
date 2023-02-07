#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SceneParameterInterface.h"
#include "SceneRigStageActorPlacement.h"
#include "SceneRigStageInterface.generated.h"

class USceneRigStageParameterBlock;
class USceneRigStage_NamedParameter;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigStageInterface : public UObject, public ISceneParameterInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneRigStageActorPlacement> ActorPlacements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USceneRigStage_NamedParameter*> Parameters;
    
    USceneRigStageInterface();
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    USceneRigStageParameterBlock* CreateParameterBlock(UObject* OuterObject) override PURE_VIRTUAL(CreateParameterBlock, return NULL;);
    
};

