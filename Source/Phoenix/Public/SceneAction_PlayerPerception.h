#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "EPlayerPerceptionEnableDisable.h"
#include "SceneAction_PlayerPerception.generated.h"

class UActorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_PlayerPerception : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlayerPerceptionEnableDisable InteractTargeting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlayerPerceptionEnableDisable AutoTargeting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlayerPerceptionEnableDisable OppugnoTargeting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* SpecialAutoTarget;
    
    USceneAction_PlayerPerception();
};

