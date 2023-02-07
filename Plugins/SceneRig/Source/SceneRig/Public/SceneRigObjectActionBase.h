#pragma once
#include "CoreMinimal.h"
#include "SkeletalMeshDriver.h"
#include "SceneRigActionBase.h"
#include "SceneRigObjectActionBase.generated.h"

class UActorProvider;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigObjectActionBase : public USceneRigActionBase, public ISkeletalMeshDriver {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasProxyParent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* ActorProvider;
    
    USceneRigObjectActionBase();
    
    // Fix for true pure virtual functions not being implemented
};

