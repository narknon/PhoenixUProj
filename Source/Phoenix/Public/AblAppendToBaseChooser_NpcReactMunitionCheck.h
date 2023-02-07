#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser_AppendToBaseChooser.h"
#include "GameplayTagContainer.h"
#include "AblAppendToBaseChooser_NpcReactMunitionCheck.generated.h"

class UInteractionArchitectAsset;

UCLASS(Blueprintable, EditInlineNew)
class UAblAppendToBaseChooser_NpcReactMunitionCheck : public UAblAnimationTagChooser_AppendToBaseChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInteractionArchitectAsset*> MunitionAssetsToFind;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MunitionTagsToFind;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AnimationTagsToAppend;
    
    UAblAppendToBaseChooser_NpcReactMunitionCheck();
};

