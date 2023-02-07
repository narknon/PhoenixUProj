#pragma once
#include "CoreMinimal.h"
#include "CameraStackStatics.h"
#include "ECameraStackLookAtStrength.h"
#include "UObject/NoExportTypes.h"
#include "Templates/SubclassOf.h"
#include "PhoenixCameraStackStatics.generated.h"

class AActor;
class ACameraStackLookAtTargetActor;
class UCameraShakeBase;
class UObject;

UCLASS(Blueprintable)
class UPhoenixCameraStackStatics : public UCameraStackStatics {
    GENERATED_BODY()
public:
    UPhoenixCameraStackStatics();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ACameraStackLookAtTargetActor* SpawnCameraLookAtTargetActor(const UObject* WorldContextObject, FVector WorldLocation, ECameraStackLookAtStrength LookAtStrength);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetPlayerCameraLookAtLocationForDuration(const UObject* WorldContextObject, FVector LookAtLocation, float Duration, ECameraStackLookAtStrength LookAtStrength, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetPlayerCameraLookAtLocation(const UObject* WorldContextObject, FVector LookAtLocation, ECameraStackLookAtStrength LookAtStrength, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetPlayerCameraLookAtActorForDuration(const UObject* WorldContextObject, AActor* LookAtActor, float Duration, ECameraStackLookAtStrength LookAtStrength, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetPlayerCameraLookAtActor(const UObject* WorldContextObject, AActor* LookAtActor, ECameraStackLookAtStrength LookAtStrength, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ReleasePlayerCameraLookAt(const UObject* WorldContextObject, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PlayWorldCameraShakeScale(const UObject* WorldContextObject, TSubclassOf<UCameraShakeBase> Shake, FVector epicenter, float InnerRadius, float OuterRadius, float Falloff, float InScale, bool bOrientShakeTowardsEpicenter);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ACameraStackLookAtTargetActor* GetLookAtTargetActorWithStrength(const UObject* WorldContextObject, ECameraStackLookAtStrength LookAtStrength, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ACameraStackLookAtTargetActor* GetHighestPriorityLookAtTargetActor(const UObject* WorldContextObject, int32 PlayerIndex);
    
};

