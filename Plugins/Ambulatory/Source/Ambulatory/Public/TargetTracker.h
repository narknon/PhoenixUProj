#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "ETargetID.h"
#include "ETargetType.h"
#include "TargetHasNewBestTargetDelegate.h"
#include "TargetListIsNowEmptyDelegate.h"
#include "Templates/SubclassOf.h"
#include "TargetTracker.generated.h"

class AActor;
class UTargetTypeBase;

UCLASS(Blueprintable, DefaultToInstanced)
class AMBULATORY_API UTargetTracker : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTargetHasNewBestTarget NotifyOfNewBestTarget;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTargetListIsNowEmpty NotifyTargetListIsNowEmpty;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TEnumAsByte<ETargetID::Type>, UTargetTypeBase*> Targets;
    
public:
    UTargetTracker();
    UFUNCTION(BlueprintCallable)
    void RemoveTargetByPtr(ETargetID::Type InTargetID, UTargetTypeBase* InTargetToRemove);
    
    UFUNCTION(BlueprintCallable)
    void RemoveTarget(ETargetID::Type InTargetID, bool bCheckForEmptyList);
    
    UFUNCTION(BlueprintCallable)
    bool IsTargetListEmptyThisFrame();
    
    UFUNCTION(BlueprintCallable)
    TMap<TEnumAsByte<ETargetID::Type>, UTargetTypeBase*> GetTargets();
    
    UFUNCTION(BlueprintCallable)
    FVector GetTargetLocation(TEnumAsByte<ETargetID::Type> InTargetID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTargetTypeBase* GetTargetByID(TEnumAsByte<ETargetID::Type> InTargetType) const;
    
    UFUNCTION(BlueprintCallable)
    AActor* GetTargetActor(TEnumAsByte<ETargetID::Type> InTargetID);
    
    UFUNCTION(BlueprintCallable)
    float GetComputedPriority(TEnumAsByte<ETargetID::Type> InTargetID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<ETargetID::Type> GetBestTargetID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTargetTypeBase* GetBestTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector ComputeTargetLocation(FVector ProjectFromLocation, float ProjectDistance) const;
    
    UFUNCTION(BlueprintCallable)
    FVector ComputeDirectionToTargetOfType(const FVector SourceLocation, TEnumAsByte<ETargetID::Type> InTargetID, bool bFlattenInXYPlane, bool bNormalize);
    
    UFUNCTION(BlueprintCallable)
    FVector ComputeDirection(const FVector SourceLocation, bool bFlattenInXYPlane, bool bNormalize);
    
    UFUNCTION(BlueprintCallable)
    static FVector ComputeCameraDirection(AActor* InActor, bool bFlattenInXYPlane);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AnyValidTargetsByType(TEnumAsByte<ETargetType::Type> InTargetType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AnyValidTargetsByID(TEnumAsByte<ETargetID::Type> InTargetID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AnyValidTargets() const;
    
    UFUNCTION(BlueprintCallable)
    UTargetTypeBase* AddTarget_StaticWorldDirection(FVector InStaticWorldDirection, TEnumAsByte<ETargetID::Type> InTargetID);
    
    UFUNCTION(BlueprintCallable)
    UTargetTypeBase* AddTarget_Location(FVector InTargetLocation, TEnumAsByte<ETargetID::Type> InTargetID);
    
    UFUNCTION(BlueprintCallable)
    UTargetTypeBase* AddTarget_DesiredDirection(TEnumAsByte<ETargetID::Type> InTargetID);
    
    UFUNCTION(BlueprintCallable)
    UTargetTypeBase* AddTarget_Custom(TSubclassOf<UTargetTypeBase> TargetClass, TEnumAsByte<ETargetID::Type> InTargetID);
    
    UFUNCTION(BlueprintCallable)
    UTargetTypeBase* AddTarget_CameraDirection(TEnumAsByte<ETargetID::Type> InTargetID);
    
    UFUNCTION(BlueprintCallable)
    UTargetTypeBase* AddTarget_ActorWithOffset(AActor* InTargetActor, const FVector& InTargetOffset, TEnumAsByte<ETargetID::Type> InTargetID);
    
    UFUNCTION(BlueprintCallable)
    UTargetTypeBase* AddTarget_Actor(AActor* InTargetActor, TEnumAsByte<ETargetID::Type> InTargetID);
    
};

