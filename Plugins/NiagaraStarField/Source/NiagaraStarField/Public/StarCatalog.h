#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Star.h"
#include "StarCatalogEntryConvert.h"
#include "StarCatalogNameIDMap.h"
#include "StarCatalog.generated.h"

UCLASS(Blueprintable)
class NIAGARASTARFIELD_API UStarCatalog : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStarCatalogEntryConvert Convert;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStarCatalogNameIDMap ConstellationIDMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStarCatalogNameIDMap ExtraIDMap;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStar> Stars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TotalStars;
    
public:
    UStarCatalog();
    UFUNCTION(BlueprintCallable)
    void ForceRebuild();
    
};

