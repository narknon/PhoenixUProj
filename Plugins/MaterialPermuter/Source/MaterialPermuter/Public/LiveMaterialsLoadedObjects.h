#pragma once
#include "CoreMinimal.h"
#include "LiveMaterialsPendingKill.h"
#include "LiveMaterialsLoadedObjects.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FLiveMaterialsLoadedObjects {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<UMaterialInterface*> LoadedObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UMaterialInterface*, FLiveMaterialsPendingKill> PendingKills;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<UMaterialInterface*> LockedObjects;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int64 TotalLoadedBytes;
    
    FLiveMaterialsLoadedObjects();
};

