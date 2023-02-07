#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Actor_FromDOV_SpawnedCallback.generated.h"

class AActor;
class UActor_FromDOV;

UCLASS(Blueprintable)
class UActor_FromDOV_SpawnedCallback : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* Caller;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActor_FromDOV* Provider;
    
    UActor_FromDOV_SpawnedCallback();
    UFUNCTION(BlueprintCallable)
    void ObjectSpawnCallback(AActor* SpawnedActor, const FName& GroupName);
    
};

