#pragma once
#include "CoreMinimal.h"
#include "CombatCursedData.h"
#include "StateEffectComponent.h"
#include "CombatCursedComponent.generated.h"

class UGameplayPropertyMod;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCombatCursedComponent : public UStateEffectComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCombatCursedData Data;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGameplayPropertyMod* ModAdded;
    
public:
    UCombatCursedComponent();
};

