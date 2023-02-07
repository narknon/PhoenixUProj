#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PhysicsSimViewBPHelper.generated.h"

class AActor;

UCLASS(Blueprintable)
class UPhysicsSimViewBPHelper : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UPhysicsSimViewBPHelper();
    UFUNCTION(BlueprintCallable)
    static void SetActorId(AActor* Actor, const FString& ActorId);
    
    UFUNCTION(BlueprintCallable)
    static void DisableAutoSaveGame();
    
};

