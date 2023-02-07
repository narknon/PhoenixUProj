#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActorSpawnFromDOVCallback.generated.h"

class AActor;
class UActor_SpawnFromDOVBase;

UCLASS(Blueprintable)
class UActorSpawnFromDOVCallback : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* Caller;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActor_SpawnFromDOVBase* Provider;
    
    UActorSpawnFromDOVCallback();
    UFUNCTION(BlueprintCallable)
    void ObjectSpawnCallback(AActor* SpawnedActor, const FName& GroupName);
    
};

