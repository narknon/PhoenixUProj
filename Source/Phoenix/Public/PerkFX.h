#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "PerkFX.generated.h"

class AActor;

UCLASS(Blueprintable)
class UPerkFX : public UObject {
    GENERATED_BODY()
public:
    UPerkFX();
    UFUNCTION(BlueprintCallable)
    static void DoPerkFX(const FString& PerkName, AActor* InActor, FVector InLocation, FRotator InRotation);
    
};

