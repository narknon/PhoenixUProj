#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser_AppendToBaseChooser.h"
#include "GameplayTagContainer.h"
#include "AblAppendToBaseChooser_FlipFlop.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAppendToBaseChooser_FlipFlop : public UAblAnimationTagChooser_AppendToBaseChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer FirstTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer SecondTags;
    
    UAblAppendToBaseChooser_FlipFlop();
};

