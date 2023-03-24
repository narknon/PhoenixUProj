#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EStandardManagedPriority.h"
#include "ChannelingSpellTool.h"
#include "LumosLevelData.h"
#include "Templates/SubclassOf.h"
#include "LumosSpellTool.generated.h"

class AActor;
class ALumosEmberActor;
class UAkAudioEvent;
class ULumosScalabilitySettingsAsset;
class UObject;

UCLASS(Blueprintable)
class ALumosSpellTool : public AChannelingSpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLumosLevelData> LevelDataArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> LumosActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULumosScalabilitySettingsAsset* LumosScalabilitySettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> IgnoreActorList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ObjectNearVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ObjectNearTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InterpTimeMS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector CollisionQueryOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* LumosMotionStartFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* LumosMotionStopFX;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ALumosEmberActor* LumosActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ALumosEmberActor* LastLumosActor;
    
public:
    ALumosSpellTool(const FObjectInitializer& ObjectInitializer);
private:
    UFUNCTION(BlueprintCallable)
    void TurnOffLumos(const UObject* i_caller);
    
public:
    UFUNCTION(BlueprintCallable)
    void StopLumos();
    
    UFUNCTION(BlueprintCallable)
    static void SetLumosVolumetricScatteringIntensity(float Intensity);
    
    UFUNCTION(BlueprintCallable)
    static void SetLumosLevelSettingsNew(float IntensityFactor, float Radius, float MinDistance);
    
    UFUNCTION(BlueprintCallable)
    static void SetLumosLevelSettings(float Intensity, float Radius, float MinDistance);
    
    UFUNCTION(BlueprintCallable)
    static void ResetLumosLevelSettings();
    
    UFUNCTION(BlueprintCallable)
    void ObjectNearSound();
    
    UFUNCTION(BlueprintCallable)
    bool IsLumosActive();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetLumosVolumetricScatteringIntensity();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetLumosLevelIntensityFactor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetLumosDebug();
    
    UFUNCTION(BlueprintCallable)
    ALumosEmberActor* GetLumosActor();
    
    UFUNCTION(BlueprintCallable)
    void DeactivateLumos(EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void ActivateLumos(EStandardManagedPriority Priority, UObject* InInstigator);
    
};

