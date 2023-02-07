#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "StairStatusChangedDelegateDelegate.h"
#include "FlyingStairComponent.generated.h"

class UAnimSequence;
class USkeletalMeshComponent;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFlyingStairComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStairStatusChangedDelegate OnStairBuilding;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStairStatusChangedDelegate OnStairDemolishing;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeBeforeDemolitionWhenUnused;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 IndexForAutomaticChainBuilding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* BuildingStairMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* BuildingStairAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* BuildingStairAnimCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* DemolishingStairMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* DemolishingStairAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* DemolishingStairAnimCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayPartOfAnim;
    
public:
    UFlyingStairComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool NeedsToBeBuilt() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBuilt() const;
    
    UFUNCTION(BlueprintCallable)
    void Demolish();
    
    UFUNCTION(BlueprintCallable)
    void Build();
    
};

