#pragma once
#include "CoreMinimal.h"
#include "SpawnSelectInfo.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "DynamicNavComponentInfo.h"
#include "EMarkupType.h"
#include "MaterialPropertyOverrideData.h"
#include "RepairData.h"
#include "BaseStateComponent.generated.h"

class AActor;
class UGeometryCollection;
class UMaterialPropertyData;
class UStaticMesh;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UBaseStateComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialPropertyData* MaterialPropertyData;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideMaterialProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPropertyOverrideData MaterialPropertyOverrideData;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRepairData RepairData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* OverrideRepairLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EMarkupType, float> MarkupMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ImmunityTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ImmuneUnlessCriticalTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bImmuneToEverythingExcept;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ImmuneToEverythingExceptTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnSelectInfo m_DbIdInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDynamicNavComponentInfo> DynamicNavigationComponentNames;
    
    UBaseStateComponent();
    UFUNCTION(BlueprintCallable)
    void SetRepairBaseMesh(UStaticMesh* Mesh);
    
    UFUNCTION(BlueprintCallable)
    void SetDestructibleGeometryCollection(UGeometryCollection* GeometryCollection);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStaticMesh* GetRepairBaseMesh() const;
    
    UFUNCTION(BlueprintCallable)
    void AddMarkup(EMarkupType i_Markup, float i_Value);
    
};

