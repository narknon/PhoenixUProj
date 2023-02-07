#pragma once
#include "CoreMinimal.h"
#include "TimeRig_StoryGraph.h"
#include "SceneParameterInterface.h"
#include "SceneRig_StoryGraph.generated.h"

class UObject;
class USceneRigProvider;
class USceneRigStageParameterBlock;

UCLASS(Blueprintable)
class SCENERIG_API USceneRig_StoryGraph : public UTimeRig_StoryGraph, public ISceneParameterInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneRigProvider* AmbientSceneRig;
    
    USceneRig_StoryGraph();
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    USceneRigStageParameterBlock* CreateParameterBlock(UObject* OuterObject) override PURE_VIRTUAL(CreateParameterBlock, return NULL;);
    
};

