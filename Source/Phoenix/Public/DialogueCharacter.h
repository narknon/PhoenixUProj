#pragma once
#include "CoreMinimal.h"
#include "Base_Character.h"
#include "DialogueCharacter.generated.h"

class UCharacterStateComponent;

UCLASS(Blueprintable)
class ADialogueCharacter : public ABase_Character {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCharacterStateComponent* ObjectStateComponent;
    
    ADialogueCharacter(const FObjectInitializer& ObjectInitializer);
};

