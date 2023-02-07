#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interface_TickThrottlerKeepAlive.generated.h"

UINTERFACE(Blueprintable)
class MASTERTICKTHROTTLER_API UInterface_TickThrottlerKeepAlive : public UInterface {
    GENERATED_BODY()
};

class MASTERTICKTHROTTLER_API IInterface_TickThrottlerKeepAlive : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void TickThrottler_WakeUp(float DistanceSquaredToCamera);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void TickThrottler_KeepAlive(float DeltaTime, float DistanceSquaredToCamera);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void TickThrottler_GoToSleep(float DistanceSquaredToCamera);
    
};

