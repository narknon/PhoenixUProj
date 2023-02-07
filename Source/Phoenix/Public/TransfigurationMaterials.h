#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TransfigurationMaterials.generated.h"

class UMaterialInterface;

UCLASS(Blueprintable)
class UTransfigurationMaterials : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* VFXFlipbookMaster;
    
    UTransfigurationMaterials();
};

