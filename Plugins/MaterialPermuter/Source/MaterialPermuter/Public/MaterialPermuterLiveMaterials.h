#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LiveMaterialsLoadedObjects.h"
#include "LiveMaterialsPendingLoads.h"
#include "MaterialPermuterLoadingBundleList.h"
#include "MaterialPermuterLoadingTriggers.h"
#include "MaterialPermuterMaterialAssetIndex.h"
#include "MaterialPermuterLiveMaterials.generated.h"

class UMaterialInterface;
class UWorld;

UCLASS(Blueprintable, Transient)
class MATERIALPERMUTER_API UMaterialPermuterLiveMaterials : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterLoadingTriggers Triggers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterLoadingBundleList Bundles;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterMaterialAssetIndex Index;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLiveMaterialsLoadedObjects LoadedObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLiveMaterialsPendingLoads PendingLoads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UMaterialInterface>> Missing;
    
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UWorld>> HasBegunPlayWorlds;
    
    UMaterialPermuterLiveMaterials();
};

