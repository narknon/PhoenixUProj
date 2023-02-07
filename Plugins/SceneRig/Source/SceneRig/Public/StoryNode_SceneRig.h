#pragma once
#include "CoreMinimal.h"
#include "ETimeRigInitializingBehavior.h"
#include "StoryNode_Script.h"
#include "StoryNode_SceneRig.generated.h"

class UObject;
class USceneRig;
class USceneRigProvider;

UCLASS(Blueprintable)
class SCENERIG_API UStoryNode_SceneRig : public UStoryNode_Script {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneRigProvider* StorySR;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETimeRigInitializingBehavior InitializingBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSkippable;
    
    UStoryNode_SceneRig();
    UFUNCTION(BlueprintCallable)
    USceneRig* GetSceneRigBP(const UObject* Caller);
    
};

