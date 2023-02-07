#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser_AppendToBaseChooser.h"
#include "GameplayTagContainer.h"
#include "AblAppendToBaseChooser_PoseMatching.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAppendToBaseChooser_PoseMatching : public UAblAnimationTagChooser_AppendToBaseChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTagContainer> AnimationArchitectTags;
    
    UAblAppendToBaseChooser_PoseMatching();
};

