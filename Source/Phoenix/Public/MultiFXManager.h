#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "MaterialSwapParameters.h"
#include "ESkinFXEffectEndStyle.h"
#include "MultiFX.h"
#include "MultiFXHandle.h"
#include "MultiFXPlus.h"
#include "MultiFXPlusHandles.h"
#include "MultiFXManager.generated.h"

class AActor;
class UNiagaraComponent;
class UParticleSystemComponent;
class USceneComponent;
class USkinFXComponent;

UCLASS(Blueprintable)
class UMultiFXManager : public UObject {
    GENERATED_BODY()
public:
    UMultiFXManager();
private:
    UFUNCTION(BlueprintCallable)
    void UpdateFX();
    
public:
    UFUNCTION(BlueprintCallable)
    static void SpawnMultiFXPlus(const FMultiFXPlus& MultiPlus, UObject* Object, FMultiFXPlusHandles& FXHandles, const FVector& Location, const FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable)
    static FMultiFXHandle SpawnMultiFXAttached(const FMultiFX& MultiFX, USceneComponent* AttachToComponent, const FMaterialSwapParameters& MaterialSwapParameters, FName AttachPointName, const FVector& Location, const FRotator& Rotation, const FVector& Scale, TEnumAsByte<EAttachLocation::Type> LocationType, bool bAutoDestroy);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static FMultiFXHandle SpawnMultiFXAtLocation(const FMultiFX& MultiFX, UObject* WorldContextObject, const FMaterialSwapParameters& MaterialSwapParameters, const FVector& Location, const FRotator& Rotation, const FVector& Scale, bool bAutoDestroy);
    
    UFUNCTION(BlueprintCallable)
    static void SetVfxRotation(const FMultiFXHandle& InHandle, const FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable)
    static void SetVfxLocation(const FMultiFXHandle& InHandle, const FVector& Location);
    
    UFUNCTION(BlueprintCallable)
    static void SetCustomTimeDilation(const FMultiFXHandle& InHandle, float Dilation);
    
private:
    UFUNCTION(BlueprintCallable)
    void MovementStopped(AActor* InActor);
    
public:
    UFUNCTION(BlueprintCallable)
    static bool IsVfxPlaying(const FMultiFXHandle& InHandle);
    
    UFUNCTION(BlueprintCallable)
    static bool IsVfxLooping(const FMultiFXHandle& InHandle);
    
    UFUNCTION(BlueprintCallable)
    static bool IsValid(const FMultiFXHandle& InHandle);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlusComplete(const FMultiFXPlusHandles& InHandles);
    
    UFUNCTION(BlueprintCallable)
    static FRotator GetVfxRotation(const FMultiFXHandle& InHandle);
    
    UFUNCTION(BlueprintCallable)
    static FVector GetVfxLocation(const FMultiFXHandle& InHandle);
    
    UFUNCTION(BlueprintCallable)
    static USkinFXComponent* GetSkinFxComponent(const FMultiFXHandle& InHandle);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetSfxHandle(const FMultiFXHandle& InHandle);
    
    UFUNCTION(BlueprintCallable)
    static UParticleSystemComponent* GetParticleSystemComponent(const FMultiFXHandle& InHandle);
    
    UFUNCTION(BlueprintCallable)
    static UNiagaraComponent* GetNiagaraComponent(const FMultiFXHandle& InHandle);
    
    UFUNCTION(BlueprintCallable)
    static float GetCustomTimeDilation(const FMultiFXHandle& InHandle);
    
    UFUNCTION(BlueprintCallable)
    static void DetachVfxRule(const FMultiFXHandle& InHandle, EDetachmentRule DetachmentRules);
    
    UFUNCTION(BlueprintCallable)
    static void DestroyPlus(FMultiFXPlusHandles& InHandles, bool bImmediate, ESkinFXEffectEndStyle EndStyle);
    
    UFUNCTION(BlueprintCallable)
    static void Destroy(FMultiFXHandle& InHandle, bool bImmediate, ESkinFXEffectEndStyle EndStyle);
    
};

