#pragma once
#include "CoreMinimal.h"
#include "SkeletalMeshDriver.h"
#include "DialogueLineRule.h"
#include "DialogueLineRule_ExplicitLayeredAnimation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDialogueLineRule_ExplicitLayeredAnimation : public UDialogueLineRule, public ISkeletalMeshDriver {
    GENERATED_BODY()
public:
    UDialogueLineRule_ExplicitLayeredAnimation();
    
    // Fix for true pure virtual functions not being implemented
};

