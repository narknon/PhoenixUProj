#pragma once
#include "CoreMinimal.h"
#include "Biped_Character.h"
#include "PHX_Biped_Preview_Actor.generated.h"

class UCustomizableCharacterComponent;

UCLASS(Blueprintable)
class APHX_Biped_Preview_Actor : public ABiped_Character {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCustomizableCharacterComponent* Customization;
    
    APHX_Biped_Preview_Actor();
};

