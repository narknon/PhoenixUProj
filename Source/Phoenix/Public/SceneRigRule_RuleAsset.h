#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SceneRigStage_ActorReference.h"
#include "SceneRigRule_RuleAsset.generated.h"

class UDialogueSequenceRule;

USTRUCT(BlueprintType)
struct FSceneRigRule_RuleAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ForSpecificActor: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_ActorReference SpecificActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogueSequenceRule* Rule;
    
    PHOENIX_API FSceneRigRule_RuleAsset();
};

