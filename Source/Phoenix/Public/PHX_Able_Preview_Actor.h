#pragma once
#include "CoreMinimal.h"
#include "Ambulatory_Character.h"
#include "PHX_Able_Preview_Actor.generated.h"

class UBipedStateComponent;
class UCustomizableCharacterComponent;

UCLASS(Blueprintable)
class APHX_Able_Preview_Actor : public AAmbulatory_Character {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCustomizableCharacterComponent* Customization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBipedStateComponent* ObjectStateComponent;
    
    APHX_Able_Preview_Actor();
};

