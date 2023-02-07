#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CompanionBlueprintLibrary.generated.h"

class AActor;

UCLASS(Blueprintable)
class UCompanionBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UCompanionBlueprintLibrary();
private:
    UFUNCTION(BlueprintCallable)
    static bool IsCompanionPawn(AActor* TargetActor);
    
    UFUNCTION(BlueprintCallable)
    static bool HasCompanionOverlaps(AActor* TargetActor);
    
};

