#pragma once
#include "CoreMinimal.h"
#include "QualifierConsideration.h"
#include "OptionActorIsTrackedErrorReported_Base.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UOptionActorIsTrackedErrorReported_Base : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnreported;
    
    UOptionActorIsTrackedErrorReported_Base();
};

