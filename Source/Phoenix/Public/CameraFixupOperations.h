#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SceneRigStageClassHost.h"
#include "Templates/SubclassOf.h"
#include "CameraFixupOperations.generated.h"

class UCameraFixupActorAction;
class UCameraFixupOperation;
class USceneRigStage_SimpleConversation;
class USceneRig_SimpleConversation;

UCLASS(Blueprintable)
class UCameraFixupOperations : public UDataAsset, public ISceneRigStageClassHost {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USceneRigStage_SimpleConversation> StageClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USceneRig_SimpleConversation> SceneRigClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCameraFixupOperation*> Operations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCameraFixupActorAction*> ActorActions;
    
    UCameraFixupOperations();
    
    // Fix for true pure virtual functions not being implemented
};

