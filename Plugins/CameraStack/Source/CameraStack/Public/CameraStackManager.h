#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Camera/PlayerCameraManager.h"
#include "CameraDefaultData.h"
#include "CameraInputMappings.h"
#include "CameraOptionMappings.h"
#include "Templates/SubclassOf.h"
#include "CameraStackManager.generated.h"

class AActor;
class ACameraStackActor;
class UCameraAspectRatioWidget;
class UCameraPostProcessHandler;
class UCameraStackSettings;
class UMaterial;
class UMaterialInstanceDynamic;
class UStaticMesh;
class UStaticMeshComponent;
class UUserWidget;

UCLASS(Blueprintable, Config=Engine, DefaultConfig, NonTransient)
class CAMERASTACK_API ACameraStackManager : public APlayerCameraManager {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DefaultCameraStyle;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraDefaultData DefaultData;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraInputMappings InputMappings;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraOptionMappings OptionMappings;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACameraStackActor> DefaultActorClass;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraAspectRatioWidget> AspectRatioWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCameraPostProcessHandler* PostProcessHandler;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, ACameraStackActor*> CameraActorMap;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> ActiveTarget;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyTickAssigned;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideBlendDuration;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendDurationOverride;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D LazyBlendSpeedRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCameraAspectRatioWidget* AspectRatioWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UUserWidget* RuleOfThirdsWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStaticMesh* FocusPlaneVisualizationMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterial* FocusPlaneVisualizationMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* DebugFocusPlaneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* DebugFocusPlaneMID;
    
public:
    ACameraStackManager(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SwitchToCamera(AActor* NewCamera, bool bInOverrideBlendDuration, float InBlendDuration);
    
    UFUNCTION(BlueprintCallable)
    void SwitchToActorsCameraActor(const AActor* newActor, bool bInOverrideBlendDuration, float InBlendDuration);
    
    UFUNCTION(BlueprintCallable)
    void SwitchToActiveTargetCamera(bool bInOverrideBlendDuration, float InBlendDuration);
    
    UFUNCTION(BlueprintCallable)
    ACameraStackActor* SpawnCameraActorForTarget(AActor* InTargetActor, UCameraStackSettings* InStackSettings, TSubclassOf<ACameraStackActor> InCameraActorClass);
    
    UFUNCTION(BlueprintCallable)
    void SetFixedCameraInPlace(bool bSetToFixed);
    
private:
    UFUNCTION(BlueprintCallable)
    void RemoveFromCameraActorMap(AActor* InActor);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCameraFixedInPlace() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetCameraStyle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACameraStackActor* GetActorsCameraActor(const AActor* InActor) const;
    
};

