#pragma once
#include "CoreMinimal.h"
#include "Base_Character.h"
#include "DB_Character.generated.h"

class UAnimationComponent;
class UBipedStateComponent;
class UCustomizableCharacterComponent;
class UFacialComponent;

UCLASS(Blueprintable)
class ADB_Character : public ABase_Character {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBipedStateComponent* ObjectStateComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCustomizableCharacterComponent* Customization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFacialComponent* FacialComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationComponent* AnimationComponent;
    
    ADB_Character();
};

