#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AvaAudioCachedRTPC.generated.h"

class AActor;
class UAkGameObject;

UCLASS(Blueprintable)
class AKAUDIO_API UAvaAudioCachedRTPC : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAvaAudioCachedRTPC();
    UFUNCTION(BlueprintCallable)
    static void AvaAudioSetGlobalState(FName StateName, FName StateValue, bool& bSuccess, bool bForce);
    
    UFUNCTION(BlueprintCallable)
    static void AvaAudioSetGlobalRTPC(FName RTPCName, float RTPCValue, bool& bSuccess, int32 InterpolationTimeMilliseconds, float Threshold, bool bForce, bool bHoldMax);
    
    UFUNCTION(BlueprintCallable)
    static void AvaAudioSetGameObjectRTPC(UAkGameObject* AudioObject, FName RTPCName, float RTPCValue, bool& bSuccess, int32 InterpolationTimeMilliseconds, float Threshold, bool bForce);
    
    UFUNCTION(BlueprintCallable)
    static void AvaAudioSetActorRTPC(AActor* Actor, FName RTPCName, float RTPCValue, bool& bSuccess, int32 InterpolationTimeMilliseconds, float Threshold, bool bForce);
    
    UFUNCTION(BlueprintCallable)
    static void AvaAudioResetGlobalState(FName StateName);
    
    UFUNCTION(BlueprintCallable)
    static void AvaAudioResetGlobalRTPC(FName RTPCName);
    
    UFUNCTION(BlueprintCallable)
    static void AvaAudioResetGameObjectRTPC(UAkGameObject* AudioObject, FName RTPCName);
    
    UFUNCTION(BlueprintCallable)
    static void AvaAudioResetActorRTPC(AActor* Actor, FName RTPCName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void AvaAudioGetGlobalState(FName StateName, bool& bSuccess, FName& StateValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void AvaAudioGetGlobalRTPC(FName RTPCName, bool& bSuccess, float& RTPCValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void AvaAudioGetGameObjectRTPC(UAkGameObject* AudioObject, FName RTPCName, bool& bSuccess, float& RTPCValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void AvaAudioGetActorRTPC(AActor* Actor, FName RTPCName, bool& bSuccess, float& RTPCValue);
    
};

