#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "P4Support.generated.h"

UCLASS(Blueprintable)
class UP4Support : public UObject {
    GENERATED_BODY()
public:
    UP4Support();
    UFUNCTION(BlueprintCallable)
    static FString GetCurrentPerforceChangelist();
    
};

