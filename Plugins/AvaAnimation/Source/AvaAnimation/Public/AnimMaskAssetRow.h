#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AnimMaskAssetRow.generated.h"

class UAnimMaskAsset;

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimMaskAssetRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMaskAsset* AnimMaskAsset;
    
    FAnimMaskAssetRow();
};

