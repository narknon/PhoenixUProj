#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/SceneComponent.h"
#include "ELerpVolumesInterpolantType.h"
#include "LerpVolumesInterpolants.h"
#include "LerpVolumesInterpolantsEvaluator.h"
#include "LerpVolumesLocalEvaluationDelegateDelegate.h"
#include "LerpVolumesLocalEvaluationComponent.generated.h"

class ULerpVolumesLibrary;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LERPVOLUMES_API ULerpVolumesLocalEvaluationComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SecondsPerUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDistanceThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdatesEnabled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesLocalEvaluationDelegate EvaluationDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULerpVolumesLibrary* LocalLibrary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLerpVolumesInterpolants LocalInterpolantDefaults;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLerpVolumesInterpolantsEvaluator LocalState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float UpdateCountdown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector LastPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bLastPositionValid;
    
public:
    ULerpVolumesLocalEvaluationComponent();
    UFUNCTION(BlueprintCallable)
    void SetUpdatesEnabled(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void SetLocalLibrary(ULerpVolumesLibrary* NewLocalLibrary);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocalVector(FName VariableName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocalUnitDirection(FName VariableName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocalTag(FName VariableName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocalScalar(FName VariableName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocalInteger(FName VariableName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocalColor(FName VariableName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLocalVector(FName VariableName, FVector& VariableValue) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLocalUnitDirection(FName VariableName, FVector& VariableValue) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetLocalType(FName VariableName, ELerpVolumesInterpolantType& VariableType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLocalTag(FName VariableName, FString& VariableValue) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLocalScalar(FName VariableName, float& VariableValue) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLocalInteger(FName VariableName, int32& VariableValue) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLocalColor(FName VariableName, FLinearColor& VariableValue) const;
    
    UFUNCTION(BlueprintCallable)
    void ForceUpdate();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreUpdatesEnabled() const;
    
};

