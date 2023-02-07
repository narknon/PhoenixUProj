#pragma once
#include "CoreMinimal.h"
#include "AkComponent.h"
#include "AvaAudioMurmurationComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UAvaAudioMurmurationComponent : public UAkComponent {
    GENERATED_BODY()
public:
    UAvaAudioMurmurationComponent();
    UFUNCTION(BlueprintCallable)
    void UpdateHealthRTPCCallback(AActor* InActor, float Delta, bool bIndicateHUD);
    
    UFUNCTION(BlueprintCallable)
    void StartIntensityDecay();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCharacterLoadComplete(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnAddOnMeshesChanged(AActor* Actor);
    
public:
    UFUNCTION(BlueprintCallable)
    void IncrementRTPC(const FString& RTPC_Name, int32 Increment, float InterpolationTime, bool bDecay);
    
    UFUNCTION(BlueprintCallable)
    void AbsoluteRTPC(const FString& RTPC_Name, float RTPC_Value, float InterpolationTimeMs, bool bDecay);
    
};

