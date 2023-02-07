#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EDoorLockLevel.h"
#include "ELockDifficulty.h"
#include "LockDifficultyHelper.generated.h"

UCLASS(Blueprintable)
class ULockDifficultyHelper : public UObject {
    GENERATED_BODY()
public:
    ULockDifficultyHelper();
    UFUNCTION(BlueprintCallable)
    static ELockDifficulty ConvertLockLevelToLockDifficulty(EDoorLockLevel LockLevel);
    
    UFUNCTION(BlueprintCallable)
    static EDoorLockLevel ConvertLockDifficultyToLockLevel(ELockDifficulty LockDifficulty);
    
};

