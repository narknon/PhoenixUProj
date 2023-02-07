#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WorldActorReference.h"
#include "StaticBP_ActorReferenceHelper.generated.h"

class AActor;
class UObject;

UCLASS(Blueprintable)
class UTILITIESRUNTIME_API UStaticBP_ActorReferenceHelper : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UStaticBP_ActorReferenceHelper();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static bool GetActorFromReference(UObject* WorldContext, FWorldActorReference ActorReference, AActor*& Actor);
    
};

