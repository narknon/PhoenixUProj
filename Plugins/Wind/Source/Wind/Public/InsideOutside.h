#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InsideOutside.generated.h"

class AActor;
class UObject;

UCLASS(Blueprintable)
class WIND_API UInsideOutside : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UInsideOutside();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool PositionOutside(UObject* WorldContextObject, FVector Position, bool bExact);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool PositionInside(UObject* WorldContextObject, FVector Position, bool bExact);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool ActorOutsideExactCached(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool ActorOutsideCoarseCached(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool ActorOutsideCached(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool ActorInsideExactCached(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool ActorInsideCoarseCached(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool ActorInsideCached(AActor* Actor);
    
};

