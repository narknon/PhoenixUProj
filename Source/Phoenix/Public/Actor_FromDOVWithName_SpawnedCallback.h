#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Actor_FromDOVWithName_SpawnedCallback.generated.h"

class AActor;
class UActor_FromDOVWithName;

UCLASS(Blueprintable)
class UActor_FromDOVWithName_SpawnedCallback : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* Caller;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActor_FromDOVWithName* Provider;
    
    UActor_FromDOVWithName_SpawnedCallback();
    UFUNCTION(BlueprintCallable)
    void ObjectSpawnCallback(AActor* SpawnedActor, const FName& GroupName);
    
};

