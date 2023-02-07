#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CreatureLookAtTargetEvaluation.h"
#include "CreatureLookAtTargetEvaluation_Float.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UCreatureLookAtTargetEvaluation_Float : public UCreatureLookAtTargetEvaluation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ValueRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D MultiplierRange;
    
    UCreatureLookAtTargetEvaluation_Float();
};

