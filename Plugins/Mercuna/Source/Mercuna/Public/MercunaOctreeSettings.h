#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MercunaOctreeData.h"
#include "MercunaOctreeSettings.generated.h"

UCLASS(Blueprintable)
class MERCUNA_API UMercunaOctreeSettings : public UDataAsset {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaOctreeData OctreeData;
    
public:
    UMercunaOctreeSettings();
};

