#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Templates/SubclassOf.h"
#include "CameraStackStatics.generated.h"

class AActor;
class ACameraStackActor;
class ACameraStackManager;
class UCameraStackSettings;
class UObject;

UCLASS(Blueprintable)
class CAMERASTACK_API UCameraStackStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UCameraStackStatics();
    UFUNCTION(BlueprintCallable)
    static ACameraStackActor* SpawnCameraStackActorForTarget(AActor* InTargetActor, UCameraStackSettings* InStackSettings, TSubclassOf<ACameraStackActor> InCameraActorClass);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetPlayerCameraNamedTargetActor(const UObject* WorldContextObject, FName InTargetName, AActor* InTargetActor, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetPlayerCameraContext(const UObject* WorldContextObject, FName InContextName, bool bSet, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ResetPlayerCameraRotation(const UObject* WorldContextObject, int32 PlayerIndex, float ResetDuration, const FRotator& DesiredDelta, bool bResetYaw, bool bResetPitch);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FTransform GetPlayerViewTransform(const UObject* WorldContextObject, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FTransform GetPlayerCameraTransform(const UObject* WorldContextObject, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ACameraStackManager* GetPlayerCameraStackManager(const UObject* WorldContextObject, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FRotator GetPlayerCameraArmRotation(const UObject* WorldContextObject, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable)
    static ACameraStackActor* GetCameraStackActorForTarget(AActor* InTargetActor);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ForceSetPlayerCameraArmRotationTowardsLocation(const UObject* WorldContextObject, int32 PlayerIndex, FVector InTargetLocation);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ForceSetPlayerCameraArmRotation(const UObject* WorldContextObject, int32 PlayerIndex, FRotator InRotation);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ForcePlayerCameraReset(const UObject* WorldContextObject, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void FilterCurrentPlayerCameraInput(const UObject* WorldContextObject, int32 PlayerIndex, float InDuration);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ClearPlayerCameraContext(const UObject* WorldContextObject, FName InContextName, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable)
    static bool CheckForCameraCutOnTeleport(AActor* InTeleportingActor);
    
};

