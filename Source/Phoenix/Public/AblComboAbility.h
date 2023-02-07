#pragma once
#include "CoreMinimal.h"
#include "AblAbility.h"
#include "AblComboAbility.generated.h"

class USpellToolRecord;

UCLASS(Blueprintable)
class UAblComboAbility : public UAblAbility {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpellToolRecord* ComboSpellToolRecord;
    
public:
    UAblComboAbility();
};

