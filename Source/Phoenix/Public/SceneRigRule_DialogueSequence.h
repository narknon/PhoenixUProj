#pragma once
#include "CoreMinimal.h"
#include "ActionParameter_DialogueEvent.h"
#include "ActionParameter_FString.h"
#include "SceneRigRule.h"
#include "SceneRigStage_IntReference.h"
#include "SceneRigStage_StringReference.h"
#include "TimeRigOutputSymbol.h"
#include "SceneRigRule_RuleAsset.h"
#include "SceneRigRule_DialogueSequence.generated.h"

class UDialogueLineRule;
class UDialogueSequenceReferenceProvider;
class UDialogueSequenceRule;
class USceneRig;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API USceneRigRule_DialogueSequence : public USceneRigRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDialogueSequenceReferenceProvider* DialogueSequenceReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_StringReference DialogueEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_StringReference DialogueSequenceName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigStage_IntReference DialogueFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActionParameter_DialogueEvent DialogEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActionParameter_FString DialogueSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRig* TemplateSceneRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CreateTransformActions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CreateChracterOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogueSequenceRule* Rule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneRigRule_RuleAsset> RuleAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDialogueLineRule*> LineRules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigOutputSymbol DialogueFinish;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigOutputSymbol ForceFinish;
    
    USceneRigRule_DialogueSequence();
};

