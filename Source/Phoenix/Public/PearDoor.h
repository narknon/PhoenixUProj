#pragma once
#include "CoreMinimal.h"
#include "Door.h"
#include "PearDoor.generated.h"

class ULockableComponent;
class UObject;

UCLASS(Blueprintable)
class APearDoor : public ADoor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULockableComponent* LockableComponent;
    
public:
    APearDoor(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    void TickleThePear(const UObject* Caller);
    
};

