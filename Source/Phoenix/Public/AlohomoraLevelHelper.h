#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EAlohomoraLevel.h"
#include "AlohomoraLevelHelper.generated.h"

UCLASS(Blueprintable)
class UAlohomoraLevelHelper : public UObject {
    GENERATED_BODY()
public:
    UAlohomoraLevelHelper();
    UFUNCTION(BlueprintCallable)
    static void SwitchAlohomoraLevel(EAlohomoraLevel& AlohomoraLevel);
    
    UFUNCTION(BlueprintCallable)
    static void SetAlohomoraLevel(EAlohomoraLevel AlohomoraLevel);
    
    UFUNCTION(BlueprintCallable)
    static bool IsAlohomoraLevel(EAlohomoraLevel AlohomoraLevel);
    
    UFUNCTION(BlueprintCallable)
    static EAlohomoraLevel GetAlohomoraLevel();
    
};

