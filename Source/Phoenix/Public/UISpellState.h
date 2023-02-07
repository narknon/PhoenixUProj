#pragma once
#include "CoreMinimal.h"
#include "UISpellState.generated.h"

USTRUCT(BlueprintType)
struct FUISpellState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpellName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowInUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LockName;
    
    PHOENIX_API FUISpellState();
};

