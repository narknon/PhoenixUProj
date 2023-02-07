#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "AIPerformTaskUnlockSpell.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskUnlockSpell : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpellType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpellSlot;
    
    UAIPerformTaskUnlockSpell();
};

