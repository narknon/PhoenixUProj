#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "BroomFlightVFXActor.generated.h"

class AFlyingBroom;
class UMaterialInstanceDynamic;
class UNiagaraComponent;
class UPostProcessComponent;

UCLASS(Blueprintable)
class ABroomFlightVFXActor : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETraceTypeQuery> MapTraceType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Time;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float PitchMultiply;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float YawMultiply;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float YawStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FString> SpeedKeys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FVector2D> SpeedValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FString> TimeKeys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FVector2D> TimeValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* SpawnedSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* DynamicBroomMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FString, FVector2D> BroomParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FString, FVector2D> MatParams;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPostProcessComponent* BroomPostProcess;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* BroomNiagara;
    
public:
    ABroomFlightVFXActor(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UNiagaraComponent* SpawnNiagaraSystem();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupVFXRefs();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupGroundVFX();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupBroomTrailVFX();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupBoostGainVFX();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetRadialBlurToggleParameterValue(float ToggleAmount);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetRadialBlurParameterValues(float EffectAmount, FLinearColor TargetPos);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UPostProcessComponent* GetPostProcess();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UNiagaraComponent* GetNiagara();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    AFlyingBroom* GetBroomCapsule();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DestroyNiagaraAndPostProcessComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CreateBroomMaterialDynamic();
    
};

