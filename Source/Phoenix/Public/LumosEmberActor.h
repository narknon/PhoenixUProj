#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "LumosScalabilitySettings.h"
#include "LumosEmberActor.generated.h"

class AAmbulatory_Character;
class UCurveFloat;
class ULumosEmberTrick;
class UMaterialSwapMeshStatesFireAndForgetComponent;

UCLASS(Blueprintable)
class ALumosEmberActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLumosScalabilitySettings CurrentScalabilitySettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* ArcHeightMultiplierCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceInFrontOfPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightAbovePlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EmberSpeedMultiplierOfDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BreadcrumbHeightModSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EmberLifeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FollowBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BreadcrumbTrailSegmentLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxBreadcrumbs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebug;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULumosEmberTrick*> PossibleEmberTricks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisconnectedFromWand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* FlickerCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FlickerCurveLoops;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULumosEmberTrick* EmberTrick;
    
    ALumosEmberActor();
    UFUNCTION(BlueprintCallable)
    void UpdateLumosFlicker(float DeltaTime, bool bIsFading);
    
    UFUNCTION(BlueprintCallable)
    void RefreshCurrentScalabilitySettings();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UMaterialSwapMeshStatesFireAndForgetComponent* GetScalabilityMeshStatesComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetLumosFlicker(float& IntensityMultiplier) const;
    
    UFUNCTION(BlueprintCallable)
    void ExternallyStartLumosFlickerForActor(AActor* OnlyForOwningActor, bool& bMatchedOwner);
    
    UFUNCTION(BlueprintCallable)
    void ExternallyStartLumosFlicker();
    
    UFUNCTION(BlueprintCallable)
    void CharacterTeleported(AAmbulatory_Character* TeleportedCharacter, FVector AmountDisplaced, FRotator AmountRotated);
    
    UFUNCTION(BlueprintCallable)
    void CacheLerpVolumeLumosVolumetricScatteringIntensity(float Value, bool bSuccess);
    
    UFUNCTION(BlueprintCallable)
    void CacheLerpVolumeLumosEVAdjust(float Value, bool bSuccess);
    
};

