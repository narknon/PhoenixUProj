#pragma once
#include "CoreMinimal.h"
#include "SkeletalMeshDriver.h"
#include "DialogueLineRule.h"
#include "DialogueLineRule_FacialEmotion.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDialogueLineRule_FacialEmotion : public UDialogueLineRule, public ISkeletalMeshDriver {
    GENERATED_BODY()
public:
    UDialogueLineRule_FacialEmotion();
    
    // Fix for true pure virtual functions not being implemented
};

