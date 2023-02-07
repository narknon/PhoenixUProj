#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CompanionStatsTriggers.generated.h"

UCLASS(Blueprintable)
class UCompanionStatsTriggers : public UObject {
    GENERATED_BODY()
public:
    UCompanionStatsTriggers();
protected:
    UFUNCTION(BlueprintCallable)
    void OnStatChanged(const FName StatID, const int32 Value, const int32 Delta);
    
};

