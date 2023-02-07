#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "LockableInterface.generated.h"

class UAkComponent;
class UMeshComponent;

UINTERFACE(Blueprintable)
class ULockableInterface : public UInterface {
    GENERATED_BODY()
};

class ILockableInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetAudioSwitch(UAkComponent* AkComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnUnlocked(bool OpenLockable, bool ThrowLock, bool PlaySoundsAndEffects, bool FromMinigame);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnLocked();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetSoundPos();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UMeshComponent* GetAttachToMesh();
    
};

