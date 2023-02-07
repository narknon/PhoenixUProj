#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "SelfOnlyAfterNamedActionEndConsideration.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API USelfOnlyAfterNamedActionEndConsideration : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Action;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WindowSize;
    
    USelfOnlyAfterNamedActionEndConsideration();
};

