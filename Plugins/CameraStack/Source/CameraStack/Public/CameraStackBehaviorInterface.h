#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CameraData.h"
#include "CameraStackBehaviorInterface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UCameraStackBehaviorInterface : public UInterface {
    GENERATED_BODY()
};

class ICameraStackBehaviorInterface : public IInterface {
    GENERATED_BODY()
public:
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool OnWriteCameraDataEvent(UPARAM(Ref) FCameraData& CameraData) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool OnUpdateEvent(float DeltaSeconds);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FString OnGetDebugStatsEvent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool OnActivateEvent();
    
};

