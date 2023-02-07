#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "PlayerTemplateNameToDataAsset.generated.h"

class UPlayerTemplateDataAsset;

USTRUCT(BlueprintType)
struct FPlayerTemplateNameToDataAsset : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPlayerTemplateDataAsset* PlayerTemplateDataAsset;
    
    PHOENIX_API FPlayerTemplateNameToDataAsset();
};

