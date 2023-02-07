#pragma once
#include "CoreMinimal.h"
#include "DialogueLineRule.h"
#include "DialogueLineRule_PickCamera.generated.h"

class UDialogueLineRule_PickCamera_Event;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDialogueLineRule_PickCamera : public UDialogueLineRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDialogueLineRule_PickCamera_Event*> Events;
    
    UDialogueLineRule_PickCamera();
};

