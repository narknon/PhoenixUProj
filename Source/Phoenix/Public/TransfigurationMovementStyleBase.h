#pragma once
#include "CoreMinimal.h"
#include "DampedSpringQuat.h"
#include "DampedSpringScalar.h"
#include "DampedSpringVector.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Curves/CurveFloat.h"
#include "TransfigurationMovementStyleBase.generated.h"

class ATransfigurationPreviewActor;

UCLASS(Blueprintable, NotPlaceable)
class ATransfigurationMovementStyleBase : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ATransfigurationPreviewActor* PreviewActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTransform TargetTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTransform PreviewTransformOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector FootprintExtent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FBox> FootprintRegions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<bool> RegionPlacementBlocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LinearInterpolationSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSpringDynamics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDampedSpringVector LinearSpring;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDampedSpringQuat AngularSpring;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDampedSpringScalar ScaleSpring;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve SpringSpeedToTiltAngleCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve ObjectBoundsToTiltMultiplierCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve ObjectBoundsToLinearFrequencyMultiplierCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisperseNPCs;
    
public:
    ATransfigurationMovementStyleBase();
protected:
    UFUNCTION(BlueprintCallable)
    void UpdateFootprintRegionSizes(const FVector& PlacementFootprintSize);
    
public:
    UFUNCTION(BlueprintCallable)
    void StartTransition(float InDuration);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ShowDecal(bool bShow);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ShowBeamAtLocalLocation(const FVector& InLocationLocal);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetWallTransformFromBounds(const FVector& LocalExtent, const FVector& LocalLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetTransformFromBounds(const FVector& LocalExtent, const FVector& LocalLocation);
    
    UFUNCTION(BlueprintCallable)
    void SetPlacementRegionTransform();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Place();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPreviewActorDestroyed(AActor* InActor);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Lift();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ClearLitBeams();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void CanPlace(bool bCanPlace);
    
};

