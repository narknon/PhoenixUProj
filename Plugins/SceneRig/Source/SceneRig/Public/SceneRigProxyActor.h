#pragma once
#include "CoreMinimal.h"
#include "TimeRigElement.h"
#include "ESceneRigProxyActor_PlatformHide.h"
#include "SceneRigStageRole.h"
#include "SceneRigProxyActor.generated.h"

class UActorProvider;

UCLASS(Blueprintable, EditInlineNew)
class SCENERIG_API USceneRigProxyActor : public UTimeRigElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStageRole Role;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInterestPoint;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldHoldDuringInitialization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTimeRigElement*> ChildElements;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ESceneRigProxyActor_PlatformHide HideOnPlatforms;
    
    USceneRigProxyActor();
};

