#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "AblTaskCondition_HitBySpell.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UAblTaskCondition_HitBySpell : public UAblTaskCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpellName;
    
    UAblTaskCondition_HitBySpell();
};

