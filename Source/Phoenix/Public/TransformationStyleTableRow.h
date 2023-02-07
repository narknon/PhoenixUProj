#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TransformationStyleTableRow.generated.h"

class ATransformationStyleBase;

USTRUCT(BlueprintType)
struct FTransformationStyleTableRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ATransformationStyleBase> EffectClass;
    
    PHOENIX_API FTransformationStyleTableRow();
};

