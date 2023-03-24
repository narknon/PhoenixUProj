#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EMaterialPermuterLoadingPriority.h"
#include "MaterialPermuterKeyProperty.h"
#include "MaterialPreLoadKeysActor.generated.h"

class UMaterialInterface;
class UMaterialPermuterLoadingBundle;

UCLASS(Abstract, Blueprintable)
class AMaterialPreLoadKeysActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaterialPermuterKeyProperty> MaterialPermuterKeys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterLoadingPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStaticLoad;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInterface*> PreLoadedMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInterface*> DynamicallyLoadedMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMaterialPermuterLoadingBundle* LoadingBundle;
    
public:
    AMaterialPreLoadKeysActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void BuildPreLoads();
    
};

