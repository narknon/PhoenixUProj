#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UDSStatManager.generated.h"

class UUDSEventQueuer;

UCLASS(Blueprintable)
class UUDSStatManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUDSEventQueuer* UDSEventQueuer;
    
public:
    UUDSStatManager();
private:
    UFUNCTION(BlueprintCallable)
    void HandleRealtimeMinutePassed();
    
    UFUNCTION(BlueprintCallable)
    void HandleInGameDayPassed();
    
};

