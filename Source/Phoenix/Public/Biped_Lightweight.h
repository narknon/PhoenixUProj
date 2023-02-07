#pragma once
#include "CoreMinimal.h"
#include "Base_Character.h"
#include "Biped_Lightweight.generated.h"

class UBipedStateComponent;
class UFacialComponent;

UCLASS(Blueprintable)
class ABiped_Lightweight : public ABase_Character {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFacialComponent* FacialComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBipedStateComponent* ObjectStateComponent;
    
    ABiped_Lightweight();
};

