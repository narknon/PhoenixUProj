#pragma once
#include "CoreMinimal.h"
#include "CustomizableCharacterInterface.h"
#include "GameFramework/Character.h"
#include "Howler_Character.generated.h"

UCLASS(Blueprintable)
class AHowler_Character : public ACharacter, public ICustomizableCharacterInterface {
    GENERATED_BODY()
public:
    AHowler_Character(const FObjectInitializer& ObjectInitializer);
    
    // Fix for true pure virtual functions not being implemented
};

