#pragma once
#include "CoreMinimal.h"
#include "SaveReceivesWeatherDecalsStateMesh.h"
#include "SaveReceivesWeatherDecalsStateActor.generated.h"

class AActor;
class USaveReceivesWeatherDecalsStateActor;

UCLASS(Blueprintable, NonTransient)
class WEATHER_API USaveReceivesWeatherDecalsStateActor : public USaveReceivesWeatherDecalsStateMesh {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> Owner;
    
    USaveReceivesWeatherDecalsStateActor();
    UFUNCTION(BlueprintCallable)
    void Update(bool markRenderStateDirty);
    
    UFUNCTION(BlueprintCallable)
    static USaveReceivesWeatherDecalsStateActor* CreateActor(AActor* Actor, bool ReceivesWeatherDecals, bool markRenderStateDirty);
    
};

