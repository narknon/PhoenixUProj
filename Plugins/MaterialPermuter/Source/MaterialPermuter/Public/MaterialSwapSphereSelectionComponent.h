#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/SceneComponent.h"
#include "EMaterialSwapSphereSelectionType.h"
#include "MaterialSwapActorRules.h"
#include "MaterialSwapInfo.h"
#include "MaterialSwapParameters.h"
#include "MaterialSwapSphereSelectionActor.h"
#include "MaterialSwapSphereSelectionActorEventDelegate.h"
#include "MaterialSwapSphereSelectionMesh.h"
#include "MaterialSwapSphereSelectionComponent.generated.h"

class AActor;
class UMeshComponent;
class UTexture;

UCLASS(Blueprintable, Transient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MATERIALPERMUTER_API UMaterialSwapSphereSelectionComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialSwapSphereSelectionType SphereType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ManualPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SphereRadiusMeters;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UnswapDelaySeconds;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapActorRules ActorEventRules;
    
    UPROPERTY(AdvancedDisplay, BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapSphereSelectionActorEvent ActorEventDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SwapSphereMaterialParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSwapSphereMaterialParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSwapOwner;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialSwapInfo SwapInfo;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UMeshComponent>, FMaterialSwapSphereSelectionMesh> MaterialSwaps;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, FMaterialSwapSphereSelectionActor> ActorsInside;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector4 SwapSphereMaterialParameterValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bSwapping;
    
public:
    UMaterialSwapSphereSelectionComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool Swapping() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 Swapped() const;
    
    UFUNCTION(BlueprintCallable)
    void StartSwapping(const FMaterialSwapInfo& NewSwapInfo);
    
    UFUNCTION(BlueprintCallable)
    void SetVectorParameter(FName Name, FVector Value);
    
    UFUNCTION(BlueprintCallable)
    void SetVector4Parameter(FName Name, FVector4 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetTextureParameter(FName Name, UTexture* Value);
    
    UFUNCTION(BlueprintCallable)
    void SetScalarParameter(FName Name, float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetParameters(const FMaterialSwapParameters& Params);
    
    UFUNCTION(BlueprintCallable)
    void SetColorParameter(FName Name, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void IsWeatherOnly(bool& OnlySwappingWeather) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInside(AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetCurrentSwapInfo(FMaterialSwapInfo& CurrentSwapInfo) const;
    
    UFUNCTION(BlueprintCallable)
    void EndSwapping();
    
};

