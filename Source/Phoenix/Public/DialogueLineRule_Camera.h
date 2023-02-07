#pragma once
#include "CoreMinimal.h"
#include "SkeletalMeshDriver.h"
#include "DialogLineRule_CameraCharacter.h"
#include "DialogueLineRule.h"
#include "DialogueLineRule_Camera.generated.h"

class UDialogueLineRule_MoveCamera_Event;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDialogueLineRule_Camera : public UDialogueLineRule, public ISkeletalMeshDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDialogLineRule_CameraCharacter> Characters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDialogueLineRule_MoveCamera_Event*> Events;
    
    UDialogueLineRule_Camera();
    
    // Fix for true pure virtual functions not being implemented
};

